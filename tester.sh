#!/bin/bash
echo "=============================================== file4.berr"
./so_long file4.berr
echo "=============================================== files3.ber"
./so_long files3.ber
echo "=============================================== file5.ber"
./so_long file5.ber
echo "=============================================== files2.ber"
./so_long files2.ber
echo "=============================================== (null)"
./so_long
echo "=============================================== adfgd"
./so_long adfgd
echo "=============================================== adfgd.ber"
./so_long adfgd.ber
echo "=============================================== .ber"
./so_long .ber
echo "=============================================== file1.ber (1 C OUT)"
./so_long file1.ber
echo "=============================================== filee.ber (1 E OUT)"
./so_long filee.ber
echo "=============================================== test.ber (GOOD)"
./so_long "test.ber"
echo "=============================================== file.ber (GOOD)"
./so_long file.ber
