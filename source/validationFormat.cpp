/**
 * \file validationFormat.cpp
 * \brief Implementation des methodes pour verifier un NIV et une plaque d'immatriculation
 * \date 2019-10-17
 * \author: Dany Pepin
 */
#include "validationFormat.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
namespace util{
/**
 * \brief methode qui permet de valider un numero d'immatriculation d'un vehicule promenade
 * \param[in] p_immatriculation qui correspond a un numero d'immatriculation d'un vehicule promenade
 */

bool validationImmatriculationPromenade (const std::string& p_immatriculation)
{

	//bool valide = false;

	if (p_immatriculation.size() == 4)
	{
		for (int i = 0; i < 4; i++){
			if (isdigit(p_immatriculation[i])){
				return false;
			}

		}
		return true;
	}

	else if (p_immatriculation.size() == 7)
	{
		int compteur1 = 0;
		for (int i = 0; i < 3; i++){
			if (isdigit(p_immatriculation[i])){
				compteur1++;
			}

		}
		if(compteur1 == 3 || compteur1 == 0){
			if (p_immatriculation[3] == ' ' || isalpha(p_immatriculation[3])){
						int compteur2 = 0;
						for (int i = 4; i < 7; i++){
							if (isdigit(p_immatriculation[i])){
								compteur2++;
							}

						}
						cout << compteur2;
						if (compteur2 == 3 || compteur2 == 0){
							return true;
						}else
							return false;
		}

		}
		else
		{
			if(compteur1 == 2 && p_immatriculation[0] == 'A'){
				if(p_immatriculation[3] == ' '){
					for (int i = 4; i < 7; i++){
						if (isdigit(p_immatriculation [i])){
							return false;

						}
					}
					return true;
				}
				return false;
			}
			return false;

		}

		}
		return false;
}

/**
 * \brief methode qui permet de valider un numero d'immatriculation d'un camion
 * \param[in] p_immatriculation qui correspond a un numero d'immatriculation d'un camion
 */
bool validationImmatriculationCamion (const std::string& p_immatriculation)
{
	if (p_immatriculation[0] == 'L'  && p_immatriculation.size() == 7)
	{
		for(int i = 1; i < 7; i++)
		{
			if (!isdigit(p_immatriculation[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


/**
 * \brief methode validerNiv qui permet de valider un numero d'identification du vehicule
 * \param[in] p_niv qui correspond a un numero d'identification du vehicule
 */

bool validerNiv (const std::string& p_niv){


	int valeurs[] = {1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, 3, 4, 5, 0, 7, 0, 9,
			2, 3, 4, 5, 6, 7, 8, 9};

	int poids[] = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};

	if (p_niv.size() != 17){
		return false;
	}
	else{
		int somme = 0;
		for (int i = 0; i < 17; i++){
			if (isdigit(p_niv[i])){
				somme = somme + p_niv[i]*poids[i];
			}
			else{
				if (p_niv[i] == 'I' || p_niv[i] == 'O' || p_niv[i] == 'Q'){
					return false;
				}
				else{
					somme = somme + valeurs[p_niv[i]-65]*poids[i];
				}
			}

		}
		cout << somme%11;
		if (somme%11 != 10){
			return true;
		}
		else{
			return false;
		}
	}




	return true;
}
}

