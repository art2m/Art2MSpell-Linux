//
// Created by art2m on 6/10/19.
//
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdk.h>
#include "Art2MSpell.h"
#include "SelectUserName.h"

static struct PackingBoxes
{
    GtkWidget *vBox1;
    GtkWidget *vBox2;
    GtkWidget *hbox1;
    GtkWidget *hbox2;

} PackBx;

static struct ButtonControls
{
    GtkWidget *btnExit;
    GtkWidget *btnUSelect;
} BtnCont;

static struct ButtonBoxes
{
    GtkWidget *hbtnBox1;
} BtnBx;

// Widget deceleration.
GtkWidget *btnExit;
GtkWidget *btnUAdd;
GtkWidget *btnUDelete;
GtkWidget *btnUEdit;
GtkWidget *btnUSelect;
GtkWidget *hbox1;
GtkWidget *hbox2;
GtkWidget *hbtnBox1;
GtkWidget *hbtnBox2;
GtkWidget *hbtnBox3;
GtkWidget *vBox1;
GtkWidget *vBox2;


// Widget deceleration.
GtkWidget *window;


// Function deceleration.
static void AddWidgetsToWindow();

static void CreateArt2mSpellMainWindow();

static void CreateWidgets();

static void OnAddNewUserButton_Click(GObject *item, gpointer data);

static void OnDeleteUserButton_Click(GObject *item, gpointer data);

static void OnEditUsersNameButton_Click(GObject *item, gpointer data);

static void OnExitApplicationButton_Click(GObject *item, gpointer data);

static void OnSelectUserButton_Click(GObject *item, gpointer data);

static void PackUsersButtonBoxWithButtons();

static void PackUsersHorizontalBox();

static void PackUsersVerticalBox();

static void WidgetSignals();


// Entry point 
int LoadArt2MSpellWindow()
{
    CreateArt2mSpellMainWindow();


    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    CreateWidgets();
    PackUsersButtonBoxWithButtons();
    PackUsersHorizontalBox();
    PackUsersVerticalBox();
    AddWidgetsToWindow();
    WidgetSignals();

    gtk_widget_show_all(window);
    return 0;
}

// Add all widgets to the window.
static void AddWidgetsToWindow()
{
    gtk_container_add(GTK_CONTAINER(window), vBox1);

}

// Create the Art2MSpell main window.
static void CreateArt2mSpellMainWindow()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *) window, "Art2MSpell Main Window.");
    gtk_window_set_default_size((GtkWindow *) window, 800, 600);
    gtk_window_set_position((GtkWindow *) window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_resizable((GtkWindow *) window, FALSE);
}

// Create the widgets used in this window.
static void CreateWidgets()
{
    btnUAdd = gtk_button_new_with_label("Add New User");
    gtk_widget_set_size_request(btnUAdd, 90, 38);

    btnUSelect = gtk_button_new_with_label("Select User");
    gtk_widget_set_size_request(btnUSelect, 90, 38);

    btnUEdit = gtk_button_new_with_label("Edit Name");
    gtk_widget_set_size_request(btnUEdit, 90, 38);

    btnUDelete = gtk_button_new_with_label("Delete User");
    gtk_widget_set_size_request(btnUDelete, 90, 38);

    btnExit = gtk_button_new_with_label("Exit");
    gtk_widget_set_size_request(btnExit, 90, 38);

    hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    vBox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    vBox2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    hbtnBox1 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    hbtnBox2 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    hbtnBox3 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
}


// Display the add new user window.
static void OnAddNewUserButton_Click(GObject *item, gpointer data)
{

}


// Display the edit user name window.
static void OnEditUsersNameButton_Click(GObject *item, gpointer data)
{

}

// Close the application.
static void OnExitApplicationButton_Click(GObject *item, gpointer data)
{
    gtk_main_quit();
}


// Display the delete user window.
static void OnDeleteUserButton_Click(GObject *item, gpointer data)
{

}

// Display the select user name window.
static void OnSelectUserButton_Click(GObject *item, gpointer data)
{
    LoadSelectUserNameWindow();
}

// Pack the button box with two user buttons.
static void PackUsersButtonBoxWithButtons()
{
    gtk_button_box_set_layout((GtkButtonBox *) hbtnBox1, GTK_BUTTONBOX_SPREAD);
    gtk_button_box_set_layout((GtkButtonBox *) hbtnBox2, GTK_BUTTONBOX_SPREAD);
    gtk_button_box_set_layout((GtkButtonBox *) (hbtnBox3), GTK_BUTTONBOX_END);

    gtk_box_pack_start(GTK_BOX(hbtnBox1), btnUAdd, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbtnBox1), btnUSelect, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(hbtnBox2), btnUEdit, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbtnBox2), btnUDelete, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(hbtnBox3), btnExit, TRUE, TRUE, 0);


}

// Pack users hbox1 with the button box.
static void PackUsersHorizontalBox()
{
    gtk_box_pack_start(GTK_BOX(hbox1), hbtnBox1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), hbtnBox2, TRUE, TRUE, 0);
}

// Pack the user vBox1 with user hbox1.
static void PackUsersVerticalBox()
{
    gtk_box_pack_start(GTK_BOX(vBox1), hbox1, FALSE, FALSE, 100);
    gtk_box_pack_start(GTK_BOX(vBox1), hbox2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vBox2), hbtnBox3, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(vBox1), vBox2, FALSE, FALSE, 10);
}

// Set all of the control signals.
static void WidgetSignals()
{
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(btnExit, "clicked", G_CALLBACK(OnExitApplicationButton_Click), NULL);
    g_signal_connect(btnUAdd, "clicked", G_CALLBACK(OnAddNewUserButton_Click), NULL);
    g_signal_connect(btnUDelete, "clicked", G_CALLBACK(OnDeleteUserButton_Click), NULL);
    g_signal_connect(btnUEdit, "clicked", G_CALLBACK(OnEditUsersNameButton_Click), NULL);
    g_signal_connect(btnUSelect, "clicked", G_CALLBACK(OnSelectUserButton_Click), NULL);
}
