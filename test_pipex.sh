#!/bin/bash

# === Configuration ===
PIPEX="./pipex"
INPUT="test_input.txt"
OUT_PIPEX="pipex_out.txt"
OUT_SHELL="shell_out.txt"

run_test() {
    label="$1"
    cmd1="$2"
    cmd2="$3"
    infile="${4:-$INPUT}"
    outfile_pipex="${5:-$OUT_PIPEX}"
    outfile_shell="${6:-$OUT_SHELL}"

    echo "------ $label ------"
    echo "Commande : \"$cmd1\" | \"$cmd2\""

    # Générer input si nécessaire
    if [ "$infile" == "$INPUT" ]; then
        echo -e "Hello\nWorld\nHello" > "$INPUT"
    fi

    # Exécuter pipex
    $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile_pipex" 2>/dev/null

    # Exécuter shell
    bash -c "$cmd1 < $infile | $cmd2" > "$outfile_shell" 2>/dev/null

    # Comparaison
    if diff -q "$outfile_pipex" "$outfile_shell" >/dev/null; then
        echo "[OK] Résultats identiques"
    else
        echo "[KO] Résultats différents"
        echo "--- Résultat pipex :"
        cat "$outfile_pipex" 2>/dev/null || echo "(fichier manquant)"
        echo "--- Résultat shell :"
        cat "$outfile_shell"
    fi
    echo ""
}

echo "==== Lancement des tests pipex vs shell ===="

run_test "Test 1" "cat" "wc -l"
run_test "Test 2" "grep Hello" "wc -c"
run_test "Test 3" "sort" "uniq"
run_test "Test 4" "invalidcmd" "wc"
run_test "Test 5" "cat" "invalidcmd"
run_test "Test 6" "cat nofile.txt" "wc -l"
run_test "Test 7" "echo test" "wc -w"
run_test "Test 8" "head -n 1" "tail -n 1"
run_test "Test 9" "cat" "cat > /dev/null"
run_test "Test 10" "tr a-z A-Z" "rev"

run_test "Test 11" "cat" "cat"
run_test "Test 12" "grep foo" "wc -l" "nonexistent_input.txt"
run_test "Test 13" "echo test" "cat" "$INPUT" "/root/output.txt"
run_test "Test 14" "/bin/echo Hello" "/usr/bin/wc -c"
run_test "Test 15" "echo 'Hello * World?'" "wc -w"
run_test "Test 16" "grep -E 'foo|bar'" "wc -l"
run_test "Test 17" "echo hello > test.txt" "wc -l"
run_test "Test 18" "sh -c 'exit 42'" "cat"
yes "line" | head -n 1000 > big_input.txt
run_test "Test 19" "cat" "wc -l" "big_input.txt"
run_test "Test 20" "sh -c 'sleep 1 && echo done'" "wc -w"

echo "==== Fin des tests ===="

# Nettoyage
rm -f "$INPUT" "$OUT_PIPEX" "$OUT_SHELL" big_input.txt

