//
// Created by art2m on 6/11/19.
//

#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdk.h>
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
    GtkWidget *btnOK;
    GtkWidget *btnCancel;
} BtnCont;

static struct ButtonBoxes
{
    GtkWidget *hbtnBox1;
    GtkWidget *hbtnBox2;
    GtkWidget *hbtnBox3;
} BtnBx;


// Widget deceleration.
GtkWidget *window;
GtkWidget *lblInfo;
GtkWidget *lstUser;
GtkListStore *userStore;


// Function deceleration.
static void AddWidgetsToWindow();

static void CreateSelectUserNameWindow();

static void CreateWidgets();

static void OnOKButton_Click(GObject *item, gpointer data);

static void OnCancelButton_Click(GObject *item, gpointer data);

static void PackUsersButtonBoxWithButtons();

static void PackUsersHorizontalBox();

static void PackUsersVerticalBox();

static void WidgetSignals();

static void CreateListBoxUser();

// Entry point for the select user name window creation.
int LoadSelectUserNameWindow()
{
    CreateSelectUserNameWindow();


    gtk_container_set_border_width(GTK_CONTAINER(window), 8);

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
    gtk_container_add(GTK_CONTAINER(window), PackBx.vBox1);
}

// Create the list box to hold all user names.
static void CreateListBoxUser()
{

}

// Create the select user name window.
static void CreateSelectUserNameWindow()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *) window, "Art2MSpell Main Window.");
    gtk_window_set_default_size((GtkWindow *) window, 400, 600);
    gtk_window_set_position((GtkWindow *) window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_resizable((GtkWindow *) window, FALSE);
}

// Create the widgets used in this window.
static void CreateWidgets()
{
    BtnCont.btnOK = gtk_button_new_with_label("OK");
    gtk_widget_set_size_request(BtnCont.btnOK, 90, 38);
    
    BtnCont.btnCancel = gtk_button_new_with_label("Cancel");
    gtk_widget_set_size_request(BtnCont.btnCancel, 90, 34);

    lblInfo = gtk_label_new("Select your user name from the list below.");

    lstUser = gtk_list_box_new();

    userStore = gtk_list_store_new(1, G_TYPE_STRING);

}

static void OnCancelButton_Click(GObject *item, gpointer data)
{

}

static void OnOKButton_Click(GObject *item, gpointer data)
{

}

static void PackUsersButtonBoxWithButtons()
{

}

static void PackUsersHorizontalBox()
{

}

static void PackUsersVerticalBox()
{

}

static void WidgetSignals()
{
    g_signal_connect(BtnCont.btnOK, "clicked", G_CALLBACK(OnOKButton_Click), NULL);
    g_signal_connect(BtnCont.btnCancel, "clicked", G_CALLBACK(OnCancelButton_Click), NULL);
}
