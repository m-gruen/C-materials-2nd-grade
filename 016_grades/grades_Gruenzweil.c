/*
 *   Mark Gruenzweil, 2 AHIF
 *   27.02.2024
 *   Berechnung von Notendurchschnitten mittels Strukturen
 */

/*
Übung 25: Zeugnisnoten; Folgende Funktionen sind zu realisieren:

a) Eingabe: Einlesen von Name, DNote, MNote, ENote;

b) ErfolgErmitteln: Berechnen ob: nicht bestanden, bestanden, guter Erfolg, ausgezeichnerter Erfolg

c) Ausgabe: folgende Werte ausgeben: Name, DNote, MNote, ENote und Erfolg;



Zusatzaufgabe:

d) Erweitern Sie das Programm so, dass mit einem "array" von Schülern gearbeitet wird.

e) Berechnen Sie für diese Klasse die Durchschnittsnote pro Gegenstand

Anmerkung: Alle Werte sollen als Parameter in einer einzigen Struktur übergeben werden.
*/

#include <stdio.h>

struct student
{
    char name[50];
    int dNote;
    int mNote;
    int eNote;
};

double calculateAverage(struct student s)
{
    return ((double)(s.dNote + s.mNote + s.eNote) / 3.0);
}

char *calculateSuccess(struct student s)
{
    int average = calculateAverage(s);

    if (s.dNote == 5 || s.mNote == 5 || s.eNote == 5)
    {
        return "nicht bestanden";
    }
    else if (s.dNote == 4 || s.mNote == 4 || s.eNote == 4)
    {
        return "bestanden";
    }
    else if (average < 2 && average > 1.5)
    {
        return "guter Erfolg";
    }
    else if (average <= 1.5)
    {
        return "ausgezeichneter Erfolg";
    }
    else
    {
        return "bestanden";
    }
}

int calculateClassAveragePerSubject(struct student students[], double *mAverage, double *dAverage, double *eAverage)
{
    double dNoteSum = 0, mNoteSum = 0, eNoteSum = 0;

    for (int i = 0; i < 3; i++)
    {
        dNoteSum += students[i].dNote;
        mNoteSum += students[i].mNote;
        eNoteSum += students[i].eNote;
    }

    *mAverage = mNoteSum / 3.0;
    *dAverage = dNoteSum / 3.0;
    *eAverage = eNoteSum / 3.0;

    return 0;
}

int main()
{
    // Basisaufgabe
    printf("Basisaufgabe\n");

    struct student s1;

    printf("Name: ");
    scanf("%s", s1.name);
    printf("Deutsch: ");
    scanf("%d", &s1.dNote);
    printf("Mathe: ");
    scanf("%d", &s1.mNote);
    printf("Englisch: ");
    scanf("%d", &s1.eNote);

    printf("\nAusgabe:\n");
    printf("Name: %s\nDeutsch: %d Mathe: %d Englisch: %d\nErfolg: %s", s1.name, s1.dNote, s1.mNote, s1.eNote, calculateSuccess(s1));

    // Zusatzaufgabe
    printf("\n\nZusatzaufgabe\n");

    struct student students[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Name %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Deutsch %d: ", i + 1);
        scanf("%d", &students[i].dNote);
        printf("Mathe %d: ", i + 1);
        scanf("%d", &students[i].mNote);
        printf("Englisch %d: ", i + 1);
        scanf("%d", &students[i].eNote);
    }

    double mAverage = 0, dAverage = 0, eAverage = 0;

    calculateClassAveragePerSubject(students, &mAverage, &dAverage, &eAverage);

    printf("\nAusgabe:\n");
    printf("Durchschnitt Deutsch: %f\nDurchschnitt Mathe: %f\nDurchschnitt Englisch: %f\n", dAverage, mAverage, eAverage);
}
