//#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main( int argc, char *argv[])
{
	char *python[3];
	int status;
	pid_t child;
	pid_t c;
	python[0] = "/usr/bin/python";
	python[1] = "getPicture.py";
	python[2] = NULL;
	
	if ((child = fork()) == 0 ) {
		
		execvp(python[0], python);
	
	
		fprintf(stderr, "Child process failed \n");
		exit(1);
	}
	else {
		if (child == (pid_t)(-1)) {
			fprintf(stderr, "Fork failed \n");
			exit(1);
		}
		else {
			c = wait(&status);
			//printf("Parent: child exited");
			printf("hi \n");
			status = 10;
			printf("test status %d  \n", status);
		}
	}
	/*
    GtkWidget *window, *image;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
    gtk_window_set_title(GTK_WINDOW(window), "Image");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    gtk_container_set_border_width(GTK_CONTAINER(window), 2);

    image = gtk_image_new_from_file("photo.jpg");
    gtk_container_add(GTK_CONTAINER(window), image);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
	*/

    return 0;
}
