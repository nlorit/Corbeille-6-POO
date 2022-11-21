#include "SVC_gestion_personnes.h"

namespace ns_SVC
{
	SVC_gestion_personnes::SVC_gestion_personnes()
	{
		this->dao = gcnew NS_DAO::DAO();
		this->personne = gcnew NS_DAO::MAP_TBPERSONNE();
		this->ds = gcnew DataSet();
	}

	DataSet^ SVC_gestion_personnes::listePersonnes(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->dao->getRows(this->personne->SELECT(), dataTableName);
		return ds;
	}

	int SVC_gestion_personnes::ajouter(String^ nom, String^ prenom)
	{
		int id_personne;
		this->personne->set_nom(nom);
		this->personne->set_prenom(prenom);
		id_personne = this->dao->actionRowsID(this->personne->INSERT());
		return id_personne;
	}
	void SVC_gestion_personnes::modifier(int id_personne, String^ nom, String^ prenom)
	{
		this->personne->set_id(id_personne);
		this->personne->set_nom(nom);
		this->personne->set_prenom(prenom);
		this->dao->actionRows(this->personne->UPDATE());
	}
	void SVC_gestion_personnes::supprimer(int id_personne)
	{
		this->personne->set_id(id_personne);
		this->dao->actionRows(this->personne->DELETE());
	}
}