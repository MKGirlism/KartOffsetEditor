# Kart Offset Editor
Change kartoffsetdata.bin for Mario Kart DS. (Work in process!)

Made by Yami (MKGirlism) from https://www.dshack.org.<br />
NOTE: This is a non-working prototype for now, please understand.

This is a complete rewrite of Szymbar15's "TooLazyToKeepDoingItByHand" (https://github.com/szymbar15/TooLazyToKeepDoingItByHand) in C, and for Linux.

To use this tool on Windows 10 Anniversary Update or later, follow this tutorial:<br />
https://www.dshack.org/forum.php?page=thread&tid=348

Compiling on Linux (requires GTK+ 2.24):<br />
gcc -o kartoffset *.c \`pkg-config --libs --cflags gtk+-2.0\`

Running on Linux:<br />
chmod 777 kartoffset<br />
./kartoffset

<img src="http://www.mkgirlism.jp/files/images/kartoffseteditor1.png" /><br />
<img src="http://www.mkgirlism.jp/files/images/kartoffseteditor2.png" />
