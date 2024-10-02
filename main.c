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

    //Titulo

    printf("\n\t  Gestión de Calificaciones de Estudiantes por Asignatura\n");
    printf("\t--------------------------------------------------------------\n\n");
    

    //Inicialización
    
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del estudiante %d: ", i);
        fflush(stdin);
        fgets(estudiantes[i], 20, stdin);

    }
    
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese las calificaciones del estudiante %s\n", estudiantes[i]);
        for (int j = 0; j < 3; j++)
        {
        printf("Calificación %d: ", j);
        scanf("%f", &calificaciones[i][j]);   
        }
        printf("\n");
    }

    //Promedios

    float prom_personal[5], prom_asignatura[3];
    int j=0;

    for (int i = 0; i < 5; i++)
    {
        prom_personal[i] = (calificaciones[i][j]+calificaciones[i][j+1]+calificaciones[i][j+2])/3;

    }
    for (int i = 0; i < 3; i++)
    {
        prom_asignatura[i] = (calificaciones[j][i]+ calificaciones[j+1][i]+calificaciones[j+2][i]+calificaciones[j+3][i]+calificaciones[j+4][i])/5;

    }

    //Nota más alta o baja estudiante
    
    float high=0, less=10;

    for (int i = 0; i < 5; i++)
    {
        if(prom_personal[i] > high){
            high=prom_personal[i];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if(prom_personal[i] < less){
            less=prom_personal[i];
        }
    }

    //Nota más alta o baja asignatura
    
    float high1=0, less1=10;

    for (int i = 0; i < 3; i++)
    {
        if(prom_asignatura[i] > high1){
            high1=prom_asignatura[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if(prom_asignatura[i] < less1){
            less1=prom_asignatura[i];
        }
    }

    //determinar estudiantes aprobados
    int aprobados=0, reprobados=0;
    for (int i = 0; i < 5; i++)
    {
        if(prom_personal[i] >= 6.0){
            aprobados++;
        }else{
            reprobados++;
        }
    }
    
    //imprmir datos

    printf("\n\t--------------------------------------------------------------\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("El promedio del alumno %s es %.2f\n",estudiantes[i], prom_personal[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("El promedio de la asignatura %d es %.2f\n",i, prom_asignatura[i]);
    }

    printf("La calificación más alta de los estudiantes fue: %.1f\n", high);
    printf("La calificación más baja de los estudiantes fue: %.1f\n", less);

    printf("La calificación más alta de las asignaturas fue: %.1f\n", high1);
    printf("La calificación más alta de las asignaturas fue: %.1f\n", less1);

    printf("El numero de estudiantes aprobados es: %d\n", aprobados);
    printf("El numero de estudiantes reprobados es: %d\n", reprobados);

    return 0;
}