#include "filez.h"
#include <stdlib.h> // strtol()など。

// 大切な関数。（サンキュー、Ermelberさん！）
int hexToInt (const char* hex) {
	return (int)strtol(hex, NULL, 16);
}

// コマンドラインモード。
void command (char *filemei) {
	printf ("おっす、%s！\n", filemei);
	
	// ファイルを読んで。
	fr = fopen (filemei, "rb");
	char c;
	int bufr[14];
	long cur = ftell(fr);
	
	fseek (fr, 0, SEEK_SET);
	
	//while ((c = fgetc(fr)) != 0x00) {
	fread (bufr, sizeof(int), 14, fr);
		
	for (int i = 0; i < 14; i++) {
		printf ("%02X ", bufr[i]);
	}
	
	printf ("\n");
	
	fclose (fr);
}

// 「開く」と呼んだダイアログ。
void open_func (GtkWidget *widget, gpointer window) {
	GtkWidget *dialogue;
	FILE * pFile;
	
	dialogue = gtk_file_chooser_dialog_new("ファイルを開く",
		GTK_WINDOW(window),
		GTK_FILE_CHOOSER_ACTION_OPEN,
		GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
		GTK_STOCK_OK, GTK_RESPONSE_OK,
		NULL);
	
	gtk_widget_show_all(dialogue);
	
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialogue), g_get_home_dir());
	gint resp = gtk_dialog_run(GTK_DIALOG(dialogue));
	
	if (resp == GTK_RESPONSE_OK) {
		char *filename;
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogue));
		pFile = fopen(filename, "r");

		if (pFile != NULL) {
			passFilename = filename;
			g_print("\"%s\"を開くことが成功。\n", passFilename);
			
			isload = 1;
		}
		else {
			g_print("エラー：\"%s\"を開くことが失敗。\n");
		}

		if (isload == 1) {
			// 準備中。
			char mei;
			char moo;
			
			// ファイルを読んで。
			fr = fopen (passFilename, "rb");
			char c;
			int bufr[14];
			long cur = ftell(fr);
			
			fseek (fr, 0, SEEK_SET);
			
			//while ((c = fgetc(fr)) != 0x00) {
			fread (bufr, sizeof(int), 14, fr);
			
			fclose (fr);
			
			// ▶▶▶ウィール名。◀◀◀
			// 準備中。
			const char *wmei = "6B6172745F746972655F4D";
			char bufferm[11];
			char *dstm = bufferm;
			char *endm = bufferm + sizeof (bufferm);
			unsigned int um;
			
			// データ変換。
			while (dstm < endm && sscanf (wmei, "%2x", &um) == 1) {
				*dstm++ = um;
				wmei += 2;
			}
			
			// アプリに書き込み。
			gint tmp_pos = GTK_ENTRY (entryWN)->text_length;
			
			for (dstm = bufferm; dstm < endm; dstm++) {
				gtk_editable_insert_text (GTK_EDITABLE (entryWN), dstm, -1, &tmp_pos);
				gtk_editable_delete_text (GTK_EDITABLE (entryWN), 11, GTK_ENTRY (entryWN)->text_length);
				gtk_editable_select_region (GTK_EDITABLE (entryWN), 0, GTK_ENTRY (entryWN)->text_length);
			}
			
			// ▶▶▶ウィールの大きさ。◀◀◀
			// 準備中。
			
			// データ変換。
			char buf[4];
			const char *woo = "9A09";
			char woohoo[4];
			
			for (int i = 0; i < 4; i++) {
				woohoo[3] = woo[1];
				woohoo[2] = woo[0];
				woohoo[1] = woo[3];
				woohoo[0] = woo[2];
			}
			
			sprintf(buf,"%d",hexToInt(woohoo));
			
			// アプリに書き込み。
			gint tmp_pos2 = GTK_ENTRY (entryWS)->text_length;
			
			gtk_editable_insert_text (GTK_EDITABLE (entryWS), buf, -1, &tmp_pos2);
			gtk_editable_delete_text (GTK_EDITABLE (entryWS), 11, GTK_ENTRY (entryWS)->text_length);
			gtk_editable_select_region (GTK_EDITABLE (entryWS), 0, GTK_ENTRY (entryWS)->text_length);
			
			// ▶▶▶すべてのタイア。◀◀◀
			// データを集めて。
			
		}
		
		g_free(filename);
	}
	else {
		g_print("キャンセルを押した。\n");
	}
	
	gtk_widget_destroy(dialogue);
}

// 「保存」と呼んだダイアログ。
void save_func (GtkWidget *widget, gpointer window) {
	GtkWidget *dialogue;
	
	dialogue = gtk_file_chooser_dialog_new("名前を付けて保存",
		GTK_WINDOW(window),
		GTK_FILE_CHOOSER_ACTION_SAVE,
		GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
		GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
		NULL);
	
	gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialogue), TRUE);
	
	gint resp = gtk_dialog_run(GTK_DIALOG(dialogue));
	
	if (resp == GTK_RESPONSE_ACCEPT) {
		char *filename;
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogue));
		//save_to_file(filename);
		g_free(filename);
		
		// ターミナルで確認する。
		g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogue)));
	}
	else {
		g_print("キャンセルを押した。\n");
	}
	
	gtk_widget_destroy(dialogue);
}
