#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink("tuberia");

    /* crear el FIFO */
    if (mkfifo("tuberia", 0666) < 0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if ((fd = open("tuberia", O_RDONLY)) < 0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        // Imprimir el texto en la pantalla
        printf("%s\n", buffer);
    }
    close(fd);
    unlink("tuberia");
    printf("Fin del juego.Logger terminado.\n");
    return(0);
}
