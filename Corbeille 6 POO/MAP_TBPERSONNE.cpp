#include "MAP_TBPERSONNE.h"

namespace NS_DAO 
{
	MAP_TBPERSONNE::MAP_TBPERSONNE()
	{
		this->id_personne = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}
	int MAP_TBPERSONNE::get_id(void)
	{
		return this->id_personne;
	}
	void MAP_TBPERSONNE::set_id(int id)
	{
		this->id_personne = id;
	}
	String^ MAP_TBPERSONNE::get_nom(void)
	{
		return this->nom;
	}
	void MAP_TBPERSONNE::set_nom(String^ sNom)
	{
		this->nom = sNom;
	}
	String^ MAP_TBPERSONNE::get_prenom(void)
	{
		return this->prenom;
	}
	void MAP_TBPERSONNE::set_prenom(String^ sPrenom)
	{
		this->prenom = sPrenom;
	}

	String^ MAP_TBPERSONNE::SELECT()
	{
		return "SELECT id_personne, nom, prenom " +
			"FROM TB_PERSONNE";
	}

	String^ MAP_TBPERSONNE::INSERT()
	{
		return "INSERT INTO TB_PERSONNE " +"(nom, prenom) " +
			"VALUES('" + this->get_nom() + "', '" + this->get_prenom() + "');SELECT @@IDENTITY;";
	}

	String^ MAP_TBPERSONNE::DELETE()
	{
		return "DELETE FROM TB_PERSONNE " +
			"WHERE(id_personne = " + this->get_id() + ");";
	}
	String^ MAP_TBPERSONNE::UPDATE()
	{
		return "UPDATE TB_PERSONNE " +
			"SET nom = '" + this->get_nom() + "', prenom = '" + this->get_prenom() + "' " +
			"WHERE(id_personne = " + this->get_id() + ");";

	}
}