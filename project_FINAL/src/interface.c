#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *combobox;
    GtkListStore *liststore;
    GtkCellRenderer *cell;
    GtkTreeIter iter;

    gtk_init(&argc, &argv);

    // Create window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ComboBox Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create combo box
    combobox = gtk_combo_box_new_with_model(GTK_TREE_MODEL(liststore));

    // Create list store with one string column
    liststore = gtk_list_store_new(1, G_TYPE_STRING);

    // Add items to the liststore
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Homme", -1);

    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Femme", -1);

    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Autre", -1);

    // Create a cell renderer and add it to the ComboBox
    cell = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combobox), cell, TRUE);
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combobox), cell, "text", 0, NULL);

    // Show the combo box
    gtk_container_add(GTK_CONTAINER(window), combobox);
    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}
