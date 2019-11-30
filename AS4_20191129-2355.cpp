#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <string>
#define SERVER "localhost"

#define ROOT_USER "root"
#define STRONG_USER "Strong"
#define MEDIUM_USER "Medium"
#define WEAK_USER "Weak"

#define ROOT_PASSWORD "coursework"
#define STRONG_PASSWORD "password3"
#define MEDIUM_PASSWORD "password2"
#define WEAK_PASSWORD "password1"

#define DATABASE "assignment4"

using namespace std;

int main () {
	MYSQL *connect;
	connect=mysql_init(NULL);
	if(!connect) {
		cout << "MySQL Initialization failed;";
		return 1;
	}
	
	connect=mysql_real_connect(connect, SERVER, ROOT_USER, ROOT_PASSWORD, DATABASE, 0, NULL, 0);
	
	if (connect) {
		cout << "connection Succeeded\n";
	} else {
		cout << "connection failed\n";
		exit(1);
	}
	
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	unsigned mysqlInt1 = mysql_query (connect, "insert into instructor (ID, name, dept_name,salary) values (1,'a','a',1)");
	//unsigned mysqlInt = mysql_query (connect,"select * from instructor where dept_name = 'Physics';");
	cout << mysqlInt1 << endl;

	if (mysqlInt1 == 1){
		cout << "Insufficient authorization level. Delete operation failed." << endl;
	}
	unsigned int i =0;
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);
	while ((row = mysql_fetch_row(res_set)) != NULL){
		cout << row[i] << "\t";
		cout << row[i+1] << "\n";
	}
	
	mysql_close (connect);
	return 0;
}
