#!/bin/bash
norminette libft/* includes/* srcs/*
make
echo "=============================================== file4.berr"
./so_long maps/file4.berr
echo "=============================================== files3.ber"
./so_long maps/files3.ber
echo "=============================================== file5.ber"
./so_long maps/file5.ber
echo "=============================================== files2.ber"
./so_long maps/files2.ber
echo "=============================================== (null)"
./so_long
echo "=============================================== adfgd"
./so_long maps/adfgd
echo "=============================================== adfgd.ber"
./so_long maps/adfgd.ber
echo "=============================================== .ber"
./so_long maps/.ber
echo "=============================================== file1.ber (1 C OUT)"
./so_long maps/file1.ber
echo "=============================================== filee.ber (1 E OUT)"
./so_long maps/filee.ber
echo "=============================================== test.ber (GOOD)"
./so_long "maps/test.ber"
echo "=============================================== file.ber (GOOD)"
./so_long maps/file.ber
