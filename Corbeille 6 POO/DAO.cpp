#include "DAO.h"

namespace NS_DAO {

	DAO::DAO()
	{
		this->SQL_request = "";
		this->cnx = "Data Source = PC-DE-NATHAN\\SQLEXPRESS;"+
			"Initial Catalog = Corbeille6POO;"+
			" Persist Security Info = True;"+
			" User ID = CNX_CO6; "+
			"Password = corbeille";
		this->SQLcnx = gcnew SqlConnection(this->cnx);
		this->SQLcommand = gcnew SqlCommand(this->SQL_request,this->SQLcnx);
		this->SQLcommand->CommandType = CommandType::Text;
	};
	
	int DAO::actionRowsID(String^ SQL_request) {
		int id;
		this->setSQL(SQL_request);
		this->SQLcommand->CommandText = this->SQL_request;
		this->SQLcnx->Open();
		id = Convert::ToInt32(this->SQLcommand->ExecuteScalar());
		this->SQLcnx->Close();
		return id;
	}

	void DAO::setSQL(String^ SQL_request) {
		if (SQL_request == "RIEN" || SQL_request == "") {
			this->SQL_request = "RIEN";
		}
		else {
			this->SQL_request = SQL_request;
		}
	}
	void DAO::actionRows(String^ SQL_request)
	{
		this->setSQL(SQL_request);
		this->SQLcommand->CommandText = this->SQL_request;
		this->SQLcnx->Open();
		this->SQLcommand->ExecuteNonQuery();
		this->SQLcnx->Close();
	}
	DataSet^ DAO::getRows(String^ SQL_request, String^ dataTableName)
	{
		this->setSQL(SQL_request);
		this->SQLdata = gcnew SqlDataAdapter(this->SQLcommand);
		this->SQLcommand->CommandText = this->SQL_request;
		this->DS = gcnew DataSet();
	//	this->DS->Clear();
		this->SQLdata->Fill(this->DS, dataTableName);
		return this->DS;
	}
}
