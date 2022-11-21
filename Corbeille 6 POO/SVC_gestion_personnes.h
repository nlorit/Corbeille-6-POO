#pragma once

#include"DAO.h"
#include"MAP_TBPERSONNE.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace ns_SVC {

	ref class SVC_gestion_personnes
	{
	private: 
		NS_DAO::DAO^ dao;
		NS_DAO::MAP_TBPERSONNE^ personne;
		DataSet^ ds;
	public: 
		SVC_gestion_personnes();
		DataSet^ listePersonnes(String^);
		int ajouter(String^, String^);
		void modifier(int, String^, String^);
		void supprimer(int);
	};

};