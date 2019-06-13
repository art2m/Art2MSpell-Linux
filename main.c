#include <stdio.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdk.h>
#include "src/Art2MSpell.h"


int main(int argc, char **argv)
{
    /* Initialise GTK+ passing to it all command line arguments  */
    gtk_init(&argc, &argv);

    LoadArt2MSpellWindow();

    /* run the GTK+ main loop */
    gtk_main();
    return 0;
}
