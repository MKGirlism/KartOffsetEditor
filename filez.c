#include "filez.h"
#include <stdlib.h> // strtol()など。

// 大切な関数。（サンキュー、Ermelberさん！）
int hexToInt (const char* hex) {
	return (int)strtol(hex, NULL, 16);
}

// コマンドラインモード。
void command (char *filemei) {
	int lang = 0, kyara = 0, kart = 0, wheelmei = 0;
	int kyaX, kyaY, kyaZ;
	int mahiX, mahiY, mahiZ, mamiX, mamiY, mamiZ, ushihiX, ushihiY, ushihiZ, ushimiX, ushimiY, ushimiZ;
	
	printf ("選んだファイルは %s と申します。\n", filemei);
	printf ("The selected file is called \"%s\".\n\n", filemei);
	
	printf ("言語を選択してください。\nPlease choose your language.\n");
	printf ("1) 日本語\t2) English\n");
	scanf ("%d", &lang);
	
	if (lang == 1) {
		printf ("\n日本語で続きましょう。\n\n");
		
		printf ("キャラクターを選択しなさい。\n");
		printf ("1) マリオ\n2) DK\n3) キノピオ\n4) クッパ\n5) ピーチ\n6) ワリオ\n7) ヨッシー\n8) ルイージ\n9) カロン\n10) デイジー\n11) ワルイージ\n12) HVC-012\n13) ヘイホー\n");
		scanf ("%d", &kyara);
		
		if (kyara < 1 || kyara > 13) {
			printf ("エラー：不明なキャラクターです。\n");
			exit(0);
		}
		
		printf ("\nカードを選択しなさい。\n");
		printf ("1) スタンダードMR\t\t20) エッグ・ワン\n2) シューティング・スター\t21) キューカンバー\n3) Bダッシュ\t\t\t22) スタンダードLG\n4) スタンダードDK\t\t23) オバキューム\n5) ワイルドライフ\t\t24) ストリームライン\n6) ジャングルカーゴ\t\t25) スタンダードKA\n7) スタンダードKO\t\t26) カロン・カノン\n8) マッシュ\t\t\t27) バニッシュ\n9) フォー・ホイール・クレイドル\t28) スタンダードDS\n10) スタンダードKP\t\t29) ライトステップDS\n11) ハリケーン\t\t\t30) フラウリィ\n12) タイラント\t\t\t31) スタンダードWL\n13) スタンダードPC\t\t32) ゴールド・マンティス\n14) ライトステップPC\t\t33) トリッパー\n15) ピアレス\t\t\t34) スタンダードRB\n16) スタンダードWR\t\t35) HVC-BLS\n17) ブルータル\t\t\t36) HVC-LGS\n18) ドラゴンフライ\t\t37) スタンダードHH\n19) スタンダードYS\n");
		scanf ("%d", &kart);
		
		if (kart < 1 || kart > 37) {
			printf ("エラー：不明なカードです。\n");
			exit(0);
		}
		
		printf ("\nウィール名を選択しなさい。\n");
		printf ("1) kart_tire_M\t2) kart_tire_S\t3) kart_tire_L\n");
		scanf ("%d", &wheelmei);
		
		printf ("\nキャラクターのX、Y、Zを書き込んでなさい。\n");
		printf ("X: ");
		scanf ("%d", &kyaX);
		printf ("Y: ");
		scanf ("%d", &kyaY);
		printf ("Z: ");
		scanf ("%d", &kyaZ);
		
		printf ("\nタイアのX、Y、Zを書き込んでなさい。\n");
		printf ("前左：\n");
		scanf ("%d", &mahiX);
		scanf ("%d", &mahiY);
		scanf ("%d", &mahiZ);
		
		printf ("\n前右：\n");
		scanf ("%d", &mamiX);
		scanf ("%d", &mamiY);
		scanf ("%d", &mamiZ);
		
		printf ("\n後ろ左：\n");
		scanf ("%d", &ushihiX);
		scanf ("%d", &ushihiY);
		scanf ("%d", &ushihiZ);
		
		printf ("\n後ろ右：\n");
		scanf ("%d", &ushimiX);
		scanf ("%d", &ushimiY);
		scanf ("%d", &ushimiZ);
		
		printf ("\nキャラクターは%d、カードは%d、ウィール名は%d。", kyara, kart, wheelmei);
		printf ("\nキャラーのポジション：%d、%d、%d", kyaX, kyaY, kyaZ);
		printf ("\n前左：%d、%d、%d", mahiX, mahiY, mahiZ);
		printf ("\n前右：%d、%d、%d", mamiX, mamiY, mamiZ);
		printf ("\n後ろ左：%d、%d、%d", ushihiX, ushihiY, ushihiZ);
		printf ("\n後ろ右：%d、%d、%d", ushimiX, ushimiY, ushimiZ);
		
		printf ("\n\n確認してください。保存しましょうか。\n");
		printf ("\n1) 保存\t2) キャンセル\n");
		
		printf ("\n今すぐ保存することが可能ではありません。次のリリースには可能でしょう。\n");
	}
	else if (lang == 2) {
		printf ("\nLet's continue in English.\n\n");
		
		printf ("Please choose a character.\n");
		printf ("1) Mario\n2) Donkey Kong\n3) Toad\n4) Bowser\n5) Peach\n6) Wario\n7) Yoshi\n8) Luigi\n9) Dry Bones\n10) Daisy\n11) Waluigi\n12) R.O.B.\n13) Shy Guy\n");
		scanf ("%d", &kyara);
		
		if (kyara < 1 || kyara > 13) {
			printf ("Error: Unknown character.\n");
			exit(0);
		}
		
		printf ("\nPlease choose a kart.\n");
		printf ("1) Standard MR\t\t20) Egg1\n2) Shooting Star\t21) Cucumber\n3) B Dasher\t\t22) Standard LG\n4) Standard DK\t\t23) Poltergust 4000\n5) Wild Life\t\t24) Streamliner\n6) Rambi Rider\t\t25) Standard DB\n7) Standard TD\t\t26) Dry Bomber\n8) Marshmellow\t\t27) Banisher\n9) 4 Wheel Cradle\t28) Standard DS\n10) Standard BW\t\t29) Light Dancer\n11) Hurricane\t\t30) Power Flower\n12) Tyrant\t\t31) Standard WL\n13) Standard PC\t\t32) Gold Mantis\n14) Light Tripper\t33) Zipper\n15) Royale\t\t34) Standard RB\n16) Standard WR\t\t35) ROB-BLS\n17) Brute\t\t36) ROB-LGS\n18) Dragonfly\t\t37) Standard HH\n19) Standard YS\n");
		scanf ("%d", &kart);
		
		if (kart < 1 || kart > 37) {
			printf ("Error: Unknown kart.\n");
			exit(0);
		}
		
		printf ("\nPlease choose the wheel name.\n");
		printf ("1) kart_tire_M\t2) kart_tire_S\t3) kart_tire_L\n");
		scanf ("%d", &wheelmei);
		
		printf ("\nPlease fill in the X, Y, Z for the character.\n");
		printf ("X: ");
		scanf ("%d", &kyaX);
		printf ("Y: ");
		scanf ("%d", &kyaY);
		printf ("Z: ");
		scanf ("%d", &kyaZ);
		
		printf ("\nPlease fill in the X, Y, Z for the tyres.\n");
		printf ("Front-Left: \n");
		scanf ("%d", &mahiX);
		scanf ("%d", &mahiY);
		scanf ("%d", &mahiZ);
		
		printf ("\nFront-Right: \n");
		scanf ("%d", &mamiX);
		scanf ("%d", &mamiY);
		scanf ("%d", &mamiZ);
		
		printf ("\nBack-Left: \n");
		scanf ("%d", &ushihiX);
		scanf ("%d", &ushihiY);
		scanf ("%d", &ushihiZ);
		
		printf ("\nBack-Right: \n");
		scanf ("%d", &ushimiX);
		scanf ("%d", &ushimiY);
		scanf ("%d", &ushimiZ);
		
		printf ("\nCharacter is %d, kart is %d, wheel name is %d.", kyara, kart, wheelmei);
		printf ("\nCharacter position: %d, %d, %d", kyaX, kyaY, kyaZ);
		printf ("\nFront-Left: %d, %d, %d", mahiX, mahiY, mahiZ);
		printf ("\nFront-Right: %d, %d, %d", mamiX, mamiY, mamiZ);
		printf ("\nBack-Left: %d, %d, %d", ushihiX, ushihiY, ushihiZ);
		printf ("\nBack-Right: %d, %d, %d", ushimiX, ushimiY, ushimiZ);
		
		printf ("\n\nPlease confirm. Want to save it?\n");
		printf ("\n1) Save\t2) Cancel\n");
		
		printf ("\nRight now, saving is not possible. It will come in the next release.\n");
	}
	else {
		printf ("\nわからなかった。申し訳ありません。\nI don't understand. Sorry.\n");
	}
	
	// ファイルを読んで。
	fr = fopen (filemei, "rb");
	char c;
	int bufr[99];
	long cur = ftell(fr);
	
	fseek (fr, 0L, SEEK_SET);
	
	while ((c = fgetc(fr)) != EOF) {
		fread (bufr, sizeof(int), 11, fr);
		//printf ("%02X ", bufr);
		printf ("%s", bufr);
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
			char moo;
			
			// ファイルを読んで。
			fr = fopen (passFilename, "rb");
			char c;
			int bufr[99];
			//char buffy[99];
			long cur = ftell(fr);
			
			fseek (fr, 0L, SEEK_SET);
			//gint tmp_pos = GTK_ENTRY (comboWN)->text_length;
			
			//sprintf (buffy, "%s", bufr);
			
			//while ((c = fgetc(fr)) != EOF) {
			//	fread (bufr, sizeof(int), 11, fr);
			//	gtk_editable_insert_text (GTK_EDITABLE (entryWN), buffy, -1, &tmp_pos);
			//	gtk_editable_delete_text (GTK_EDITABLE (entryWN), 11, GTK_ENTRY (entryWN)->text_length);
			//	gtk_editable_select_region (GTK_EDITABLE (entryWN), 0, GTK_ENTRY (entryWN)->text_length);
			//}
			
			//fclose (fr);
			
			// ▶▶▶ウィール名。◀◀◀
			// アプリに書き込み。
			gtk_combo_box_set_active (GTK_COMBO_BOX(comboWN), 0);
			
			// ▶▶▶ウィールの大きさ。◀◀◀
			// 準備中。
			
			// データ変換。
			char buf[99];
			fseek (fr, 17, SEEK_SET);
			fread (buf, sizeof(int), 8, fr);
			const char *woo = buf;//"9A09";
g_print (" Hex: %02X \n", woo);
g_print (" Int: %d\n", woo);
g_print ("Char: %c\n", woo);
			char woohoo[8];
			
			for (int i = 0; i < 8; i++) {
				woohoo[7] = woo[1];
				woohoo[6] = woo[0];
				woohoo[5] = woo[3];
				woohoo[4] = woo[2];
				woohoo[3] = woo[5];
				woohoo[2] = woo[4];
				woohoo[1] = woo[7];
				woohoo[0] = woo[6];
			}
			
			sprintf (buf, "%d", hexToInt(woohoo));
			
			// アプリに書き込み。
			gint tmp_pos2 = GTK_ENTRY (entryWS)->text_length;
			
			gtk_editable_insert_text (GTK_EDITABLE (entryWS), buf, -1, &tmp_pos2);
			gtk_editable_delete_text (GTK_EDITABLE (entryWS), 11, GTK_ENTRY (entryWS)->text_length);
			gtk_editable_select_region (GTK_EDITABLE (entryWS), 0, GTK_ENTRY (entryWS)->text_length);
			
			// ▶▶▶タイアのXYZ。◀◀◀
			// データを集めて。
			
			fclose (fr);
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
