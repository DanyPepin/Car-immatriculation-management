/**
 * \file Vehicule.h
 * \brief Declaration de la classe Vehicule
 * \date 2019-10-17
 * \author: Dany Pepin
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <iostream>
#include "Date.h"
#include "ContratException.h"

namespace saaq
{
/**
 * \class Vehicule
 * \brief Classe permettant de generer des objets Vehicule
 */
class Vehicule
{
public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
	virtual ~Vehicule(){};

	virtual Vehicule* clone() const=0;
	virtual double tarificationAnnuelle() const=0; // methode purement virtuel, doit seulement definir son implementation dans les classe derivee
	virtual std::string reqVehiculeFormate() const = 0; // accesseur

	const std::string& reqNiv() const;
	const std::string& reqImmatriculation() const;
	//void asgImmatriculation(const std::string& p_immatriculation); mis dans proteger

	bool operator==(const Vehicule& p_vehicule) const;

private:

	void verifieInvariant() const;

	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;

protected:
	void asgImmatriculation(const std::string& p_immatriculation);

};
} //namespace saaq


#endif /* VEHICULE_H_ */

