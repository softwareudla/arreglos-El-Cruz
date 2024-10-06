/*Descripción del Problema:

Una escuela desea implementar un programa en C que le permita gestionar las calificaciones de un grupo de estudiantes en varias asignaturas. 
Además de gestionar las calificaciones, el programa debe calcular y mostrar información relevante como el promedio de calificaciones por 
estudiante y por asignatura, la calificación más alta y baja, y cuántos estudiantes aprobaron cada asignatura.

Instrucciones para el Desarrollo del Programa:

El número de estudiantes será 5 y de asignaturas 3.
El programa debe ser capaz de realizar las siguientes tareas:
    Calcular el promedio de calificaciones para cada estudiante.
    Calcular el promedio por asignatura.
    Encontrar la calificación más alta y baja por estudiante y por asignatura.
    Determinar cuántos estudiantes aprobaron o reprobaron cada asignatura. (Nota aprobatoria ≥ 6).*/

#include <stdio.h>

int main() {
    
    //Definición de matrices
    char estudiantes[5][20];
    float calificaciones[5][3];

    // Título
    printf("\n\t  Gestión de Calificaciones de Estudiantes por Asignatura\n");
    printf("\t--------------------------------------------------------------\n\n");
    printf("Materia 1: Historia\n");
    printf("Materia 2: Matemáticas\n");
    printf("Materia 3: Biología\n\n");

    // Inicialización de nombres y calificaciones
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fflush(stdin);
        fgets(estudiantes[i], 20, stdin);
    }
    
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("Ingrese las calificaciones del estudiante %s\n", estudiantes[i]);
        for (int j = 0; j < 3; j++) {
            do {
                printf("Calificación %d (0 - 10): ", j + 1);
                scanf("%f", &calificaciones[i][j]);

                // Validación de la calificación
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Error: La calificación debe estar entre 0 y 10. Inténtelo nuevamente.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);   
        }
        printf("\n");
    }

    // Cálculo de promedios
    float prom_personal[5], prom_asignatura[3];

    for (int i = 0; i < 5; i++) {
        prom_personal[i] = (calificaciones[i][0] + calificaciones[i][1] + calificaciones[i][2]) / 3;
    }

    for (int i = 0; i < 3; i++) {
        prom_asignatura[i] = (calificaciones[0][i] + calificaciones[1][i] + calificaciones[2][i] + calificaciones[3][i] + calificaciones[4][i]) / 5;
    }

    // Nota más alta y baja por estudiante
    float high = 0, less = 10;
    
    for (int i = 0; i < 5; i++) {
        if (prom_personal[i] > high) {
            high = prom_personal[i];
        }
        if (prom_personal[i] < less) {
            less = prom_personal[i];
        }
    }

    // Nota más alta y baja por asignatura
    float high1 = 0, less1 = 10;

    for (int i = 0; i < 3; i++) {
        if (prom_asignatura[i] > high1) {
            high1 = prom_asignatura[i];
        }
        if (prom_asignatura[i] < less1) {
            less1 = prom_asignatura[i];
        }
    }

    // Determinar estudiantes aprobados y reprobados
    int aprobados = 0, reprobados = 0;
    
    for (int i = 0; i < 5; i++) {
        if (prom_personal[i] >= 6.0) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    // Imprimir datos
    printf("\n\t--------------------------------------------------------------\n\n");

    for (int i = 0; i < 5; i++) {
        printf("El promedio del alumno %s es %.2f\n", estudiantes[i], prom_personal[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("El promedio de la asignatura %d es %.2f\n", i + 1, prom_asignatura[i]);
    }

    printf("\nLa calificación más alta de los estudiantes fue: %.1f\n", high);
    printf("La calificación más baja de los estudiantes fue: %.1f\n", less);

    printf("La calificación más alta de las asignaturas fue: %.1f\n", high1);
    printf("La calificación más baja de las asignaturas fue: %.1f\n", less1);

    printf("\nEl número de estudiantes aprobados es: %d\n", aprobados);
    printf("El número de estudiantes reprobados es: %d\n", reprobados);

    return 0;
}