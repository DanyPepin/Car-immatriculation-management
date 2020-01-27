/**
 * \file Propriétaire.h
 * \brief Declaration de la classe Proprietaire
 * \date 2019-11-09
 * \author: Dany Pepin
 */
#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_
#include "Vehicule.h"
#include <vector>

namespace saaq
{
/**
 * \class Propriétaire
 * Cette classe permet de faire la gestion des vehicule
 */
class Proprietaire
{
public:
	Proprietaire(const std::string& p_nom, const std::string& p_prenom);
	~Proprietaire();

	const std::string& reqNom() const;
	const std::string& reqPrenom() const;

	std::string reqProprietaireFormate() const;
	void ajouterVehicule(const Vehicule& p_nouveauVehicule);
	void supprimerVehicule(const std::string& p_niv);


private:
	void verifieInvariant() const;
	std::vector<Vehicule*> m_vVehicules;
	std::string m_nom;
	std::string m_prenom;
	const Proprietaire& operator= (const Proprietaire& p_proprietaire);
	Proprietaire(const Proprietaire& p_proprietaire);
	bool VehiculeEstDejaPresent(const std::string& p_niv) const;
};

}//namespace
#endif /* PROPRIÉTAIRE_H_ */
