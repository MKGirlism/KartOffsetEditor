// GTKライブラリー。
#include <gtk/gtk.h>
#include <glib.h>

// 普通ライブラリー。
#include <string.h>
#include <stdio.h>

// GTKウィジェット。
//// ラベル。
GtkWidget *labelWN, *labelWS, *labelKID, *labelLF, *labelRF, *labelLB, *labelRB, *labelKN;
GtkWidget *labelF;
//// コンボーボックスとウィンドウ。
GtkWidget *window, *fixed, *comboKN, *comboKID;
GtkWidget *entryWN, *entryWS;
//// スピンボックス。
GtkWidget *spinX, *spinY, *spinZ;
GtkWidget *spinLFX, *spinLFY, *spinLFZ;
GtkWidget *spinRFX, *spinRFY, *spinRFZ;
GtkWidget *spinLBX, *spinLBY, *spinLBZ;
GtkWidget *spinRBX, *spinRBY, *spinRBZ;
//// ボタン。
GtkWidget *buttonAku, *buttonHozon;
//// なんであることが知らない・・・
GtkAdjustment *adj;

// アプリをチート中。
char *passFilename;

// ファイル向け。
FILE *fr;
