#pragma once
#include <string.h>

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_DAO
{ 
	ref class DAO
	{
	private:
		String^ cnx;
		String^ SQL_request;
		SqlConnection^ SQLcnx;
		SqlCommand^ SQLcommand;
		SqlDataAdapter^ SQLdata;
		DataSet^ DS;
		void setSQL(String^);
	public:
		DAO();
		int actionRowsID(String^);
		void actionRows(String^);
		DataSet^ getRows(String^, String^);

	};

}
