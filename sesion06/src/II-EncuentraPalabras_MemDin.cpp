/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 2 - Encontrar palabras            **/
/**                          memoria dinamica               **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 20;

/*******************************************************************************/

struct info_palabra {
	char ** inicio = new char * [MAX_PALABRAS];
	char ** fin = new char * [MAX_PALABRAS];
};

/*******************************************************************************/

int encuentra_palabras (info_palabra * &, const char * );
void muestra_palabras (info_palabra * & , const int );

/*******************************************************************************/

int main( void ){
	

	char la_cadena[MAX_CARACTERES];
	info_palabra * las_palabras = new info_palabra;

	int num_palabras;

	cout << "Introduce la cadena : ";
	cin.getline(la_cadena, MAX_CARACTERES);

	num_palabras = encuentra_palabras(las_palabras, la_cadena);

	cout << endl << la_cadena << endl;
	cout << endl << "Tiene " << num_palabras << " palabras." << endl;


	muestra_palabras (las_palabras, num_palabras);

	return 0;
	
}

/*******************************************************************************/
 

int encuentra_palabras (info_palabra * & palabras, const char * cadena){
	int n_palabras = 0;
	int i = 1;
	bool salir = false;

	if (cadena[0] != ' '){
		(palabras->inicio)[0] = (char *) cadena;
		n_palabras++;

		
		if (cadena[1] == ' '){
			(palabras->fin)[0] = (char *) &cadena[0];
		}
	}

	while( cadena[i] && !salir){
		
		if(n_palabras < MAX_PALABRAS){

			if (cadena [i] != ' ' &&
			   (cadena[i - 1] == ' ' || cadena[i + 1] == ' ' 
				                      || cadena[i + 1] == '\0' )){	
				
				if (cadena[i - 1] == ' '){
					(palabras->inicio)[n_palabras] = (char *) &cadena[i];
					n_palabras++;

				}
				if (cadena[i + 1] == ' ' || cadena[i + 1] == '\0' ) {
					(palabras->fin)[n_palabras - 1] = (char *) &cadena[i];	

				}
			}
			i++;
		}
		else{
				cerr << endl << "AVISO: Numero de palabras demasiado grande." << endl 
				     << "No se tendran en cuenta mas palabras" << endl;
				salir = true;
		}
	}

	return n_palabras;
}

/*******************************************************************************/

void muestra_palabras (info_palabra * & palabra, const int N_PALABRAS){
	for (int i = 0; i < N_PALABRAS; i++){
		int j = 0;
		cout << "La palabra " << i + 1 << " comienza por la letra " 
		     << *(palabra->inicio)[i] << " y finaliza con la letra "
			  << *(palabra->fin)[i] << endl;

		cout << "La palabra es " ;

		while ( (palabra->inicio)[i]+j <= (palabra->fin)[i] ){
			cout << *(palabra->inicio[i]+j);
			j++;
		}

		cout << endl;
	}
}