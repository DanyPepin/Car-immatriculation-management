/**
 * \file Proprietaire.cpp
 * \brief Implantation de la classe Proprietaire
 * \date 2019-11-09
 * \author: Dany Pepin
 */
#include <sstream>
#include "Proprietaire.h"
#include <vector>
#include <string>
#include "VehiculeException.h"
#include "ContratException.h"
namespace saaq
{
/**
 * \brief Constructeur de la classe Proprietaire avec parametres permettant de creer des objets Proprietaire
 * \param[in] p_nom le nom du proprietaire du vehicule
 * \param[in] p_prenom le prenom du proprietaire du vehicule
 * \pre p_nom ne doit pas etre vide
 * \pre p_prenom ne doit pas etre vide
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 */
saaq::Proprietaire::Proprietaire(const std::string& p_nom,
		const std::string& p_prenom) : m_nom(p_nom), m_prenom(p_prenom)
{
	PRECONDITION(!(p_nom.empty()));
	PRECONDITION(!(p_prenom.empty()));
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	INVARIANTS();
}
/**
 * \brief Constructeur copie de la classe Proprietaire permettant de faire une copie en profondeur
 * \param[in] un proprietaire de vehicule
 */
saaq::Proprietaire::Proprietaire(const Proprietaire& p_proprietaire) : m_vVehicules(p_proprietaire.m_vVehicules.size()), m_nom(p_proprietaire.m_nom), m_prenom(p_proprietaire.m_prenom)
{
	std::vector<Vehicule*>::const_iterator ivv;
	for (ivv = m_vVehicules.begin(); ivv != m_vVehicules.end(); ++ ivv)
	{
		delete *ivv;

	}
}
/**
 * \brief Destructeur de la classe Proprietaire
 */
saaq::Proprietaire::~Proprietaire()
{
	for (int i = 0; i < int(m_vVehicules.size()); i++)
	{
		delete m_vVehicules[i];
	}
}

/**
 * \brief surcharge de l'operateur =
 * \param[in] p_proprietaire un proprietaire de vehicule
 *
 */
const Proprietaire& saaq::Proprietaire::operator =(
		const Proprietaire& p_proprietaire)
{
	if (this != & p_proprietaire)
	{
		for (int i = 0; i < int(m_vVehicules.size()); i++)
		{
			delete m_vVehicules[i];
		}

		for (std::size_t i = 0; i < p_proprietaire.m_vVehicules.size(); i++)
		{
			m_vVehicules[i] = p_proprietaire.m_vVehicules[i];
		}

	}
	return *this;
}
/**
 * \brief Accesseur sur le nom du proprietaire du vehicule
 * \return le nom du proprietaire
 */
const std::string& saaq::Proprietaire::reqNom() const
{
	return m_nom;
}
/**
 * \brief Accesseur sur le prenom du proprietaire du vehicule
 * \return le prenom du proprietaire
 */
const std::string& saaq::Proprietaire::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief affiche les informations de tous les Vehicules du Proprietaire et retour dans un string formatee
 * \return les informations de tos les Vehicule du Proprietaire
 */
std::string saaq::Proprietaire::reqProprietaireFormate() const
{
	std::ostringstream os;
	os << "Proprietaire" << std::endl
	<< "-------------------" << std::endl
	<< "Nom     :  " << m_nom << std::endl
	<< "Prenom  :  " << m_prenom << std::endl
	<< "-------------------" << std::endl;
	for (int i = 0; i < int(m_vVehicules.size()); i++)
	{
		os << (m_vVehicules[i])->reqVehiculeFormate() << std::endl
				<<"-------------------" << std::endl;
	}
	return os.str();
}
/**
 * \brief Ajoute un vehicule au vecteur de vehicules si celui-ci n'est pas deja present
 * Sinon une exception du type VehiculeDejaPresentException sera lancer.
 * \param[in] p_nouveauVehicule un vehicule qui sera ajouter au vecteur de vehicules
 */
void saaq::Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
{
	PRECONDITION(!(Proprietaire::VehiculeEstDejaPresent(p_nouveauVehicule.reqNiv())));
	try
	{
		if(Proprietaire::VehiculeEstDejaPresent(p_nouveauVehicule.reqNiv()))
		{
			throw VehiculeDejaPresentException(p_nouveauVehicule.reqVehiculeFormate());
		}
		m_vVehicules.push_back(p_nouveauVehicule.clone());
	}
	catch(VehiculeDejaPresentException& e)
	{
		e.what();
	}

}

/**
 * \brief verifie les invariants de la classe Proprietaire
 */
void saaq::Proprietaire::verifieInvariant() const
{
	INVARIANT(!(m_nom.empty()));
	INVARIANT(!(m_prenom.empty()));
}
/**
 * \brief Methode qui permet de verifier si Proprietaire a deja ce vehicule
 * \param[in] p_niv le numero d'identification du vehicule
 * \return Un booleen True si le vehicule existe deja, false si il n'est pas deja present
 */
bool saaq::Proprietaire::VehiculeEstDejaPresent(const std::string& p_niv) const
{
	std::vector<Vehicule*>::const_iterator ivv;
	for (ivv = m_vVehicules.begin(); ivv != m_vVehicules.end(); ++ivv)
	{
		if ((*ivv)->reqNiv() == p_niv)
		{
			return true;
		}
	}
	return false;

}
/**
 * \brief Supprime le vehicule dont le numero d'identification du vehicule est recu en parametre
 * S'il n'y a pas de vehicule qui possede ce numero dans le dossier du proprietaire,
 * une exception VehiculeAbsentException est lancer.
 * param[in] le numero d'identification du vehicule
 */
void Proprietaire::supprimerVehicule(const std::string& p_niv)
{
	PRECONDITION(Proprietaire::VehiculeEstDejaPresent(p_niv));

	try
	{
		if (!VehiculeEstDejaPresent(p_niv))
		{
			throw VehiculeAbsentException("Il n'y a pas de vehicule qui possede ce numero dans le dossier");
		}
		else
		{
			std::vector<Vehicule*>::const_iterator ivv;
			for(ivv = m_vVehicules.begin(); ivv != m_vVehicules.end(); ++ivv)
			{
				if((*ivv)->reqNiv() == p_niv)
				{
					delete (*ivv);
					ivv = m_vVehicules.erase(ivv);
					break;
				}
			}
		}
	}
	catch(VehiculeAbsentException& e)
	{
		e.what();
	}
	POSTCONDITION(!Proprietaire::VehiculeEstDejaPresent(p_niv));
	INVARIANTS();
}

}
