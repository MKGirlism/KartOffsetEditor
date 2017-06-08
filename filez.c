#include "filez.h"
#include <stdio.h> // デバッグなど。

// 大切な関数。
int hex_to_int (char c) {
	int first = c / 16 - 3;
	int second = c % 16;
	int result = first*10 + second;
	if (result > 9) result--;
	
	return result;
}

int hex_to_ascii (char c, char d) {
	int high = hex_to_int (c) * 16;
	int low = hex_to_int (d);

	return high + low;
}

// 「開く」と呼んだダイアログ。
void open_func (GtkWidget *widget, gpointer window) {
	// テスト中。
	const char *tstr = "6B6172745F746972655F4D";
	int length = strlen(tstr);
	
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
		//	if (!readobjmodel (pFile, &objfile))
		//		exit (EXIT_FAILURE);
		//	renderobjmodel (&objfile);
			passFilename = filename;
			g_print("\"%s\"を開くことが成功。\n", passFilename);
		//	g_signal_connect(G_OBJECT(drawing_area), "realize",
		//		G_CALLBACK(realise), NULL);
			isload = 1;
		}
		else {
			g_print("エラー：\"%s\"を開くことが失敗。");
		}

		if (isload == 1) {
			int i;
			char buf = 0;
			gint tmp_pos = GTK_ENTRY (entryWN)->text_length;
			
			for (i = 0; i < length; i++) {
				if(i % 2 != 0) {
					// アプリのウィジェットを書き込み。
					//const char *st = hex_to_ascii (buf, tstr[i]);
					
					gtk_editable_insert_text (GTK_EDITABLE (entryWN), tstr, -1, &tmp_pos);
					gtk_editable_delete_text (GTK_EDITABLE (entryWN), length, GTK_ENTRY (entryWN)->text_length);
					gtk_editable_select_region (GTK_EDITABLE (entryWN), 0, GTK_ENTRY (entryWN)->text_length);
				}
				else {
					buf = tstr[i];
				}
			}
		}
		
		g_free(filename);
		
		// ターミナルで確認する。
		g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogue)));
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
