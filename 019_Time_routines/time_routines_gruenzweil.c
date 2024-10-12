/*
*   Mark Gruenzweil, 2AHIF
*   05.03.2024
*   Zeitroutinen (localtime())
*/

#include <stdio.h>
#include <time.h>

int main() {
    // Zeitstruktur initialisieren
    time_t aktuelle_zeit;
    struct tm *zeitinfo;

    // Aktuelle Zeit abrufen
    time(&aktuelle_zeit);

    // Zeit in lokale Zeit umwandeln
    zeitinfo = localtime(&aktuelle_zeit);

    // Ausgabe der Zeit
    printf("Aktuelle Zeit und Datum: %s", asctime(zeitinfo));

    return 0;
}
