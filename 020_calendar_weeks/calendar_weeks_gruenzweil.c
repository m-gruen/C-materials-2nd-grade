/*
 *   Mark Grünzweil, 2AHIF
 *   05.03.2024
 *   Kalenderwochen
 */

#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;

    printf("Bitte geben Sie das Datum ein (JJJJ MM TT): ");
    scanf("%d %d %d", &year, &month, &day);

    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900; // Jahr seit 1900
    timeinfo.tm_mon = month - 1;    // Monat von 0 bis 11
    timeinfo.tm_mday = day;         // Tag im Monat

    time_t time = mktime(&timeinfo);

    char calendarweek[3];
    strftime(calendarweek, sizeof(calendarweek), "%W", &timeinfo);

   printf("Das Datum %02d.%02d.%d liegt in der Kalenderwoche %s.\n", day, month, year, calendarweek);

    return 0;
}
