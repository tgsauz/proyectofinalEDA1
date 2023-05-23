#include <stdio.h>
#include <string.h>

#define COLOR "\e[31m"
#define COLOR_OFF "\e[m"
#define TAM1 10
#define TAM2 30

struct comuna 
{
    char periodo[TAM1];
    char descripcion[TAM2];
    char mujeres[TAM1];
    char hombres[TAM1];
    char total[TAM1];
};

void lecturaCompletaFile(FILE *mainfile, int *cont, struct comuna *ptr);

int main() 
{
    char nuevoPeriodo[TAM1];
    char nuevoDescripcion[TAM2];
    char nuevoHombres[TAM1];
    char nuevoMujeres[TAM1]; 
    char nuevoTotal[TAM1];
    struct comuna input, *ptr, aux;
    ptr = &input;
    int cont = 1;
    unsigned int instancia_deseada = 2;
    int aux_cont, selector = 0, selectorTipoDato = 0;
    long posicion = 0;

    FILE *mainfile;

    mainfile = fopen("D:\\facustuff\\programacion\\proyectoFinalEda1\\alcobendas.bin", "rb+");

    if(mainfile == NULL)
    {

        printf("Error: archivo .bin no se puede abrir\n");
        return(0);

    }

    printf(COLOR "Bienvenido/a\n\n" COLOR_OFF);

    do
    {

        printf("Para mostrar las instancias de las comunas ingrese: '1'\n");
        printf("\n");
        printf("Para buscar una instancia en especifico el caracter: '2'\n");
        printf("\n");
        printf("Para editar una instancia ingrese el caracter: '3'\n");
        printf("\n");
        printf("Para detener el programa ingrese caracter: '9'\n");
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

        scanf("%d", &selector);
        switch (selector)
        {
            // Caso 2 Visualizacion
            case 1:
            
                //Lectura de archivo.
                lecturaCompletaFile(mainfile, &cont, ptr);
                aux_cont = cont;
                printf(COLOR "EXISTEN %d INSTANCIAS EN EL ARCHIVO \n\n" COLOR_OFF, (aux_cont - 1));
                rewind(mainfile);
                break;

            // Caso 2 Visualizacion especificada
            case 2:

                printf("Ingrese el " COLOR "NUMERO DE INSTANCIA " COLOR_OFF "que desea visualizar\n(Numero indicado en el titulo de la instancia)\n");
                scanf("%u", &instancia_deseada);

                //Calcular la distancia deseada en tamaño de memoria.
                posicion = sizeof(struct comuna) * (instancia_deseada - 1);
                fseek(mainfile, posicion, SEEK_SET);

                // Si la lectura de la instancia es correcta permite editarla, sino realiza rewind y avisa.
                if(fread(&input, sizeof(struct comuna), 1, mainfile) == 1)
                {
                    fseek(mainfile, posicion, SEEK_SET);
                    if(!feof(mainfile) && fread(ptr, sizeof(struct comuna), 1, mainfile) == 1)
                    {
                        printf(COLOR "INSTANCIA %d \n" COLOR_OFF, instancia_deseada);
                        printf("Periodo: %s\n", ptr->periodo);
                        printf("Descripcion: %s\n", ptr->descripcion);
                        printf("Mujeres: %s\n", ptr->mujeres);
                        printf("Hombres: %s\n", ptr->hombres);
                        printf("Total: %s\n", ptr->total);
                        printf("-----------------\n"); 

                    }
                }else {
                    printf("Error al seleccionar ubicacion\n\n");
                    rewind(mainfile);
                    break;
                }
                rewind(mainfile);
                break;

            // Caso 3 Edicion
            case 3:

                printf("Ingrese el " COLOR "NUMERO DE INSTANCIA " COLOR_OFF "que desea editar\n(Numero indicado en el titulo de la instancia)\n");
                scanf("%u", &instancia_deseada);

                //Calcular la distancia deseada en tamaño de memoria.
                posicion = sizeof(struct comuna) * (instancia_deseada - 1);
                fseek(mainfile, posicion, SEEK_SET);

                // Si la lectura de la instancia es correcta permite editarla, sino realiza rewind y avisa.
                if (fread(&input, sizeof(struct comuna), 1, mainfile) == 1)
                {
                    fseek(mainfile, posicion, SEEK_SET);
                    if(!feof(mainfile) && fread(ptr, sizeof(struct comuna), 1, mainfile) == 1)
                    {
                        printf(COLOR "\nINSTANCIA %d \n" COLOR_OFF, instancia_deseada);
                        printf("Periodo: %s\n", ptr->periodo);
                        printf("Descripción: %s\n", ptr->descripcion);
                        printf("Mujeres: %s\n", ptr->mujeres);
                        printf("Hombres: %s\n", ptr->hombres);
                        printf("Total: %s\n", ptr->total);
                        printf("-----------------\n\n");

                        printf("Elegir el " COLOR "DATO DE ESTRUCTURA" COLOR_OFF " desea editar\n\n");

                        printf("Para editar el dato " COLOR "PERIODO" COLOR_OFF " de la comuna ingrese: '1'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                        printf("Para editar el dato " COLOR "DESCRIPCION" COLOR_OFF " de la comuna ingrese: '2'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                        printf("Para editar el dato " COLOR "MUJERES" COLOR_OFF " de la comuna ingrese: '3'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                        printf("Para editar el dato " COLOR "HOMBRES" COLOR_OFF " de la comuna ingrese: '4'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                        printf("Para editar el dato " COLOR "TOTAL" COLOR_OFF " de la comuna ingrese: '5'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                        printf("Para detener la edicion de la comuna ingrese: '9'\n");
                        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

                        scanf("%d", &selectorTipoDato);

                        switch (selectorTipoDato)
                        {
                            // Edicion DATO PERIODO
                            case 1:

                                fseek(mainfile, posicion, SEEK_SET);
                                printf("EDITANDO DATO" COLOR " PERIODO\n" COLOR_OFF);


                                printf("Ingrese el nuevo valor del dato " COLOR "PERIODO\n" COLOR_OFF);
                                if (scanf(" %9[^\n]", nuevoPeriodo) != 1) {
                                    printf("Error al leer el nuevo valor del dato PERIODO\n");
                                    rewind(mainfile);
                                    break;
                                }
                                
                                aux = input;

                                strcpy(aux.periodo, nuevoPeriodo);

                                // Si la escritura es diferente al tamaño de struct, signfica q hubo un error
                                
                                if(fwrite(&aux, sizeof(struct comuna), 1, mainfile) != 1)
                                {

                                    printf( COLOR "ATENCION\n" COLOR_OFF "SE MODIFICO DE MANERA ERRONEA, POR FAVOR REVISAR\n");
                                    rewind(mainfile);

                                }else
                                {

                                    printf( COLOR "EDICION EXITOSA\n" COLOR_OFF);
                                    rewind(mainfile);

                                };
                                break;
                                
                                //Edicion DATO DESCRIPCION
                            case 2:

                                fseek(mainfile, posicion, SEEK_SET);
                                printf("EDITANDO DATO" COLOR " DESCRIPCION\n" COLOR_OFF);


                                printf("Ingrese el nuevo valor del dato " COLOR "DESCRIPCION\n" COLOR_OFF);
                                if (scanf(" %9[^\n]", nuevoDescripcion) != 1) {
                                    printf("Error al leer el nuevo valor del dato DESCRIPCION\n");
                                    rewind(mainfile);
                                    break;
                                }
                                
                                aux = input;

                                strcpy(aux.descripcion, nuevoDescripcion);

                                // Si la escritura es diferente al tamaño de struct, signfica q hubo un error
                                
                                if(fwrite(&aux, sizeof(struct comuna), 1, mainfile) != 1)
                                {

                                    printf( COLOR "ATENCION\n" COLOR_OFF "SE MODIFICO DE MANERA ERRONEA, POR FAVOR REVISAR\n");
                                    rewind(mainfile);

                                }else
                                {

                                    printf( COLOR "EDICION EXITOSA\n" COLOR_OFF);
                                    rewind(mainfile);

                                };
                                break;

                                
                                //Edicion DATO MUJERES
                            case 3:

                                fseek(mainfile, posicion, SEEK_SET);
                                printf("EDITANDO DATO" COLOR " MUJERES\n" COLOR_OFF);


                                printf("Ingrese el nuevo valor del dato " COLOR "MUJERES\n" COLOR_OFF);
                                if (scanf(" %9[^\n]", nuevoMujeres) != 1) {
                                    printf("Error al leer el nuevo valor del dato MUJERES\n");
                                    rewind(mainfile);
                                    break;
                                }
                                
                                aux = input;

                                strcpy(aux.mujeres, nuevoMujeres);

                                // Si la escritura es diferente al tamaño de struct, signfica q hubo un error
                                
                                if(fwrite(&aux, sizeof(struct comuna), 1, mainfile) != 1)
                                {

                                    printf( COLOR "ATENCION\n" COLOR_OFF "SE MODIFICO DE MANERA ERRONEA, POR FAVOR REVISAR\n");
                                    rewind(mainfile);

                                }else
                                {

                                    printf( COLOR "EDICION EXITOSA\n" COLOR_OFF);
                                    rewind(mainfile);

                                };
                                break;

                                //Edicion DATO HOMBRES
                            case 4:

                                fseek(mainfile, posicion, SEEK_SET);
                                printf("EDITANDO DATO" COLOR " HOMBRES\n" COLOR_OFF);


                                printf("Ingrese el nuevo valor del dato " COLOR "HOMBRES\n" COLOR_OFF);
                                if (scanf(" %9[^\n]", nuevoHombres) != 1) {
                                    printf("Error al leer el nuevo valor del dato HOMBRES\n");
                                    rewind(mainfile);
                                    break;
                                }
                                
                                aux = input;

                                strcpy(aux.hombres, nuevoHombres);

                                // Si la escritura es diferente al tamaño de struct, signfica q hubo un error
                                
                                if(fwrite(&aux, sizeof(struct comuna), 1, mainfile) != 1)
                                {

                                    printf( COLOR "ATENCION\n" COLOR_OFF "SE MODIFICO DE MANERA ERRONEA, POR FAVOR REVISAR\n");
                                    rewind(mainfile);

                                }else
                                {

                                    printf( COLOR "EDICION EXITOSA\n" COLOR_OFF);
                                    rewind(mainfile);

                                };
                                break;


                            //Edicion DATO TOTAL
                            case 5:

                                fseek(mainfile, posicion, SEEK_SET);
                                printf("EDITANDO DATO" COLOR " TOTAL\n" COLOR_OFF);


                                printf("Ingrese el nuevo valor del dato " COLOR "TOTAL\n" COLOR_OFF);
                                if (scanf(" %9[^\n]", nuevoTotal) != 1) {
                                    printf("Error al leer el nuevo valor del dato TOTAL\n");
                                    rewind(mainfile);
                                    break;
                                }
                                
                                aux = input;

                                strcpy(aux.total, nuevoTotal);

                                // Si la escritura es diferente al tamaño de struct, signfica q hubo un error
                                
                                if(fwrite(&aux, sizeof(struct comuna), 1, mainfile) != 1)
                                {

                                    printf( COLOR "ATENCION\n" COLOR_OFF "SE MODIFICO DE MANERA ERRONEA, POR FAVOR REVISAR\n");
                                    rewind(mainfile);

                                }else
                                {

                                    printf( COLOR "EDICION EXITOSA\n" COLOR_OFF);
                                    rewind(mainfile);

                                };
                                break;
                                
                            // SE SALE DEL SWITCH ANIDADO
                            case 9:

                                printf(COLOR "Finalizando edicion\n" COLOR_OFF);
                                rewind(mainfile);
                                break;

                            default:

                                printf("Ingrese un caracter valido\n\n");

                                printf("Para editar el dato " COLOR "PERIODO" COLOR_OFF " de la comuna ingrese: '1'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                printf("Para editar el dato " COLOR "DESCRIPCION" COLOR_OFF " de la comuna ingrese: '2'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                printf("Para editar el dato " COLOR "MUJERES" COLOR_OFF " de la comuna ingrese: '3'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                printf("Para editar el dato " COLOR "HOMBRES" COLOR_OFF " de la comuna ingrese: '4'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                printf("Para editar el dato " COLOR "TOTAL" COLOR_OFF " de la comuna ingrese: '5'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                printf("Para detener la edicion de la comuna ingrese: '9'\n");
                                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                                
                                scanf("%d", &selectorTipoDato);
                                break;
                        }

                    }

                } else {
                    printf("Error al seleccionar ubicacion\n\n");
                    rewind(mainfile);
                    break;
                };
                break;
                
            
            default:

                printf("Por favor, ingrese un " COLOR "NUMERO" COLOR_OFF " valido.\n");
                break;
        };
    } while(selector != 9);

    printf("Hasta luego" COLOR "Finalizando programa" COLOR_OFF);
    fclose(mainfile);
    return 0;
};

void lecturaCompletaFile(FILE *mainfile, int *cont, struct comuna *ptr)
{
    *cont = 1;
    while(!feof(mainfile) && fread(ptr, sizeof(struct comuna), 1, mainfile) == 1)
    {
        printf(COLOR "INSTANCIA %d \n" COLOR_OFF, *cont);
        printf("Periodo: %s\n", ptr->periodo);
        printf("Descripcion: %s\n", ptr->descripcion);
        printf("Mujeres: %s\n", ptr->mujeres);
        printf("Hombres: %s\n", ptr->hombres);
        printf("Total: %s\n", ptr->total);
        printf("-----------------\n");
        (*cont)++;
    }
}