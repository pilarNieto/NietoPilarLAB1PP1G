#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "brand.h"
#include "colors.h"


int esNumerica(char cadena[])
{
    int ret=-1;
    int i=0;

    if(cadena!=NULL)
    {
    while(cadena[i]!='\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        break;
        i++;
    }
    if(cadena[i]=='\0')
    ret=1;
    }
    return ret;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    	{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo, int reintentos)
{

int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo){
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}
int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

void strlwrLinux(char* cadena)
{
    int i= 0;

    while(cadena[i] != '\0')
    {
      cadena[i] = tolower(cadena[i]);
      i++;
    }
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{

            if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int validateOption(char* option)
{
    int isFine = 0;
    char auxChar = ' ';

    auxChar = *option;
    while(auxChar != 'n' && auxChar != 's')
    {
        printf("Error en la opción! Reingrese por favor: ");
        fflush(stdin);
        scanf("%c", &auxChar);
    }
    if(auxChar == 's' || auxChar == 'n')
    {
        *option = auxChar;
        isFine = 1;
    }
    return isFine;
}

int validateBrand(eMarcas marcas[], int tamMarca, int idParameter)
{
    int isFine = 0;
    for (int i = 0; i < tamMarca; i++)
    {
        if (marcas[i].id == idParameter)
        {
            isFine = 1;
            break;
        }
    }
    return isFine;
}

int validateColor(eColor colores[], int tamColor, int idParameter)
{
    int isFine = 0;
    for (int i = 0; i < tamColor; i++)
    {
        if (colores[i].id == idParameter)
        {
            isFine = 1;
            break;
        }
    }
    return isFine;
}

int validateModel(int validateModel)
{
    int isFine = 1;
    if(validateModel < 1930 || validateModel > 2020)
    {
        isFine = 0;
    }
    return isFine;
}

int validatePatent(int patenteParametro)
{
    int isFine = 1;
    if(patenteParametro < 100000 || patenteParametro > 999999)
    {
        isFine = 0;
    }
    return isFine;
}

int validateDay(int dayParameter)
{
    int isFine = 1;
    if (dayParameter < 1 || dayParameter > 31)
    {
        isFine = 0;
    }
    return isFine;
}

int validateMonth(int monthParameter)
{
    int isFine = 1;
    if (monthParameter < 1 || monthParameter > 12)
    {
        isFine = 0;
    }
    return isFine;
}

int validateYear(int yearParameter)
{
    int isFine = 1;
    if (yearParameter < 1900 || yearParameter > 2020)
    {
        isFine = 0;
    }
    return isFine;
}
int getStringTelefono(char *pResultado,
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            //retorna cadena si es realizada con éxito.
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                if(esNumerica(buffer)!=1)//Si es igual a 1 es que es numerico.
                {
                    strncpy(pResultado,buffer,maximo+1);
                    retorno = 0;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >=0);
    }
    return retorno;
}
char getSexo(char *pResultado,
             char *pMensaje,
             char *pMensajeError,
             char minimo,
             char maximo,
             int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    char buffer;

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%c",&buffer)==1)
            {
                if(buffer == 'f' || buffer == 'm')
                {
                    retorno = 0;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}
int isAlphaNumeric(char str[])
{

    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
                &&(str[i] < 'a' || str[i] > 'z')
                &&(str[i] < 'A' || str[i] > 'Z')
                &&(str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int validateService(eServicio servicios[], int tamServicio, int servicioParametro)
{
    int isFine = 0;
        for (int i = 0; i < tamServicio; i++)
    {
        if (servicios[i].id == servicioParametro)
        {
            isFine = 1;
            break;
        }
    }
    return isFine;
}

