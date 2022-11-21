#pragma once

using namespace System;

namespace NS_DAO {

	ref class MAP_TBPERSONNE
	{
	private:
		int id_personne;
		String^ nom;
		String^ prenom;
	public:
		MAP_TBPERSONNE();
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);

		int get_id(void);
		void set_id(int);

		String^ get_nom(void);
		void set_nom(String^);

		String^ get_prenom(void);
		void set_prenom(String^);

	};

};