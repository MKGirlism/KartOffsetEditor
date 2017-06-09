#include "getall.h" // 一番大切なヘッダー。
#include "filez.h" // ファイルダイアログ向け。

// コンボーボックスの使い方には、これは必要だ。
void getindex (GtkWidget *widget, gpointer window) {
	gint out = gtk_combo_box_get_active(GTK_COMBO_BOX(window));
	g_print("%d\n", out);
}

// 無論すべてはすごく大切になる...と思う。
int main (int argc, char *argv[]) {
	// GTKを開始。
	gtk_init(&argc, &argv);
	
	// ウィンドウ物。
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Kart Offset Editor v0.1");
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);
	gtk_window_resize(GTK_WINDOW(window), 974, 307);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	// レイアウトを樹立。
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);
	
	// ラベル物。
	labelWN = gtk_label_new("ウィール名");
	gtk_label_set_justify(GTK_LABEL(labelWN), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelWN, 0, 0);
	gtk_widget_set_size_request(labelWN, 97, 30);
	
	labelWS = gtk_label_new("ウィールの大きさ");
	gtk_label_set_justify(GTK_LABEL(labelWS), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelWS, 245, 0);
	gtk_widget_set_size_request(labelWS, 97, 30);
	
	labelKID = gtk_label_new("カートID");
	gtk_label_set_justify(GTK_LABEL(labelKID), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelKID, 450, 0);
	gtk_widget_set_size_request(labelKID, 97, 30);
	
	labelKN = gtk_label_new("キャラ名");
	gtk_label_set_justify(GTK_LABEL(labelKN), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelKN, 325, 40);
	gtk_widget_set_size_request(labelKN, 97, 30);
	
	labelLF = gtk_label_new("前左");
	gtk_label_set_justify(GTK_LABEL(labelLF), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelLF, 0, 40);
	gtk_widget_set_size_request(labelLF, 97, 30);
	
	labelRF = gtk_label_new("前右");
	gtk_label_set_justify(GTK_LABEL(labelRF), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelRF, 0, 80);
	gtk_widget_set_size_request(labelRF, 97, 30);
	
	labelLB = gtk_label_new("後ろ左");
	gtk_label_set_justify(GTK_LABEL(labelLB), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelLB, 0, 120);
	gtk_widget_set_size_request(labelLB, 97, 30);
	
	labelRB = gtk_label_new("後ろ右");
	gtk_label_set_justify(GTK_LABEL(labelRB), GTK_JUSTIFY_LEFT);
	gtk_fixed_put(GTK_FIXED(fixed), labelRB, 0, 160);
	gtk_widget_set_size_request(labelRB, 97, 30);
	
	// コンボーボクス物。
	comboKN = gtk_combo_box_new_text();
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x00 - マリオ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x01 - DK");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x02 - キノピオ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x03 - クッパ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x04 - ピーチ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x05 - ワリオ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x06 - ヨッシー");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x07 - ルイージ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x08 - カロン");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x09 - デイシー");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x0A - ワルイージ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x0B - HVC-012");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKN), "0x0C - ヘイホー");
	gtk_fixed_put(GTK_FIXED(fixed), comboKN, 410, 40);
	gtk_widget_set_size_request(comboKN, 250, 30);
	
	/*g_signal_connect(G_OBJECT(comboKN), "changed", 
		G_CALLBACK(decro7), (gpointer) labelDEC);*/
	
	comboKID = gtk_combo_box_new_text();
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x00 - スタンダードMR");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x01 - シューティング・スター");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x02 - Bダッシュ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x03 - スタンダードDK");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x04 - ワイルドライフ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x05 - ジャングルカーゴ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x06 - スタンダードKO");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x07 - マッシュ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x08 - フォー・ホイール・クレイドル");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x09 - スタンダードKP");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0A - ハリケーン");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0B - タイラント");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0C - スタンダードPC");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0D - ライトステップPC");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0E - ピアレス");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x0F - スタンダードWR");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x10 - ブルータル");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x11 - ドラゴンフライ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x12 - スタンダードYS");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x13 - エッグ・ワン");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x14 - キューカンバー");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x15 - スタンダードLG");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x16 - オバキューム");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x17 - ストリームライン");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x18 - スタンダードKA");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x19 - カロン・カノン");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1A - バニッシュ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1B - スタンダードDS");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1C - ライトステップDS");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1D - フラウリィ");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1E - スタンダードWL");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x1F - ゴールド・マンティス");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x20 - トリッパー");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x21 - スタンダードRB");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x22 - HVC-BLS");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x23 - HVC-LGS");
	gtk_combo_box_append_text(GTK_COMBO_BOX(comboKID), "0x24 - スタンダードHH");
	gtk_fixed_put(GTK_FIXED(fixed), comboKID, 530, 0);
	gtk_widget_set_size_request(comboKID, 250, 30);
	
	// エントリー物。
	entryWN = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entryWN), "");
	gtk_entry_set_editable(GTK_ENTRY(entryWN), TRUE);
	gtk_fixed_put(GTK_FIXED(fixed), entryWN, 85, 0);
	gtk_widget_set_size_request(entryWN, 107, 30);
	
	entryWS = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entryWS), "");
	gtk_entry_set_editable(GTK_ENTRY(entryWS), TRUE);
	gtk_fixed_put(GTK_FIXED(fixed), entryWS, 350, 0);
	gtk_widget_set_size_request(entryWS, 107, 30);
	
	/*g_signal_connect(G_OBJECT(entry), "key-release-event",
		G_CALLBACK(entryres), NULL);*/
	
	// スピンボタン物。
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLFX = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLFX), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLFX, 85, 40);
	gtk_widget_set_size_request(spinLFX, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLFY = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLFY), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLFY, 170, 40);
	gtk_widget_set_size_request(spinLFY, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLFZ = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLFZ), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLFZ, 255, 40);
	gtk_widget_set_size_request(spinLFZ, 77, 30);
	
	// --------------
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLBX = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLBX), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLBX, 85, 80);
	gtk_widget_set_size_request(spinLBX, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLBY = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLBY), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLBY, 170, 80);
	gtk_widget_set_size_request(spinLBY, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinLBZ = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinLBZ), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinLBZ, 255, 80);
	gtk_widget_set_size_request(spinLBZ, 77, 30);
	
	// --------------
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRFX = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRFX), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRFX, 85, 120);
	gtk_widget_set_size_request(spinRFX, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRFY = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRFY), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRFY, 170, 120);
	gtk_widget_set_size_request(spinRFY, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRFZ = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRFZ), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRFZ, 255, 120);
	gtk_widget_set_size_request(spinRFZ, 77, 30);
	
	// --------------
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRBX = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRBX), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRBX, 85, 160);
	gtk_widget_set_size_request(spinRBX, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRBY = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRBY), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRBY, 170, 160);
	gtk_widget_set_size_request(spinRBY, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinRBZ = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinRBZ), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinRBZ, 255, 160);
	gtk_widget_set_size_request(spinRBZ, 77, 30);
	
	// --------------
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinX = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinX), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinX, 350, 80);
	gtk_widget_set_size_request(spinX, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinY = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinY), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinY, 435, 80);
	gtk_widget_set_size_request(spinY, 77, 30);
	
	adj = (GtkAdjustment *) gtk_adjustment_new (0.0, -999999.0, 999999.0, 1.0, 5.0, 0.0);
	spinZ = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinZ), TRUE);
	gtk_fixed_put (GTK_FIXED (fixed), spinZ, 520, 80);
	gtk_widget_set_size_request(spinZ, 77, 30);
	
	// ボタン物。
	buttonAku = gtk_button_new_with_label("開く");
	gtk_fixed_put(GTK_FIXED(fixed), buttonAku, 350, 160);
	gtk_widget_set_size_request(buttonAku, 90, 30);
	gtk_widget_set_sensitive(buttonAku, TRUE);
	
	g_signal_connect(G_OBJECT(buttonAku), "clicked",
		G_CALLBACK(open_func), (gpointer) window);
	
	buttonHozon = gtk_button_new_with_label("保存");
	gtk_fixed_put(GTK_FIXED(fixed), buttonHozon, 450, 160);
	gtk_widget_set_size_request(buttonHozon, 90, 30);
	gtk_widget_set_sensitive(buttonHozon, TRUE);
	
	g_signal_connect(G_OBJECT(buttonHozon), "clicked",
		G_CALLBACK(save_func), (gpointer) window);
	
	// コードが古い。触りないでなさい！
	/*g_signal_connect(G_OBJECT(combod), "changed", 
		G_CALLBACK(val2ent7), (gpointer) entry);
	g_signal_connect(G_OBJECT(combob), "changed", 
		G_CALLBACK(becalc7), (gpointer) entry);
	g_signal_connect(G_OBJECT(combosh), "changed", 
		G_CALLBACK(shadow7), (gpointer) entry);
	g_signal_connect(G_OBJECT(combosp), "changed", 
		G_CALLBACK(special7), (gpointer) entry);*/
	
	// あたしの名前は。。。
	labelF = gtk_label_new("Made by MKGirlism. https://www.dshack.org");
	gtk_label_set_justify(GTK_LABEL(labelF), GTK_JUSTIFY_RIGHT);
	gtk_fixed_put(GTK_FIXED(fixed), labelF, 150, 200);
	gtk_widget_set_size_request(labelF, 400, 30);
	
	// 全て破壊して。
	g_signal_connect(G_OBJECT(window), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}
