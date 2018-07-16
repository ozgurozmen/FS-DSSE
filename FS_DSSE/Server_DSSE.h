#ifndef SERVER_DSSE_H
#define SERVER_DSSE_H

#include <MasterKey.h>
#include <config.h>
#include <struct_MatrixType.h>

#include <zmq.hpp>
using namespace zmq;
class Server_DSSE
{
private:
    
    
    // Encrypted index
    MatrixType** I;
	
	string* D;
    TYPE_COUNTER* block_counter_arr;
	//Future work - make this boolean
	bool* keyword_state_arr;
    MatrixType** block_state_mat;

    MatrixType** I_search;
    MatrixType** I_update;
    
    MatrixType** block_state_mat_search;
    MatrixType** block_state_mat_update;
	
	TYPE_GOOGLE_DENSE_HASH_MAP T_W;
	
	unsigned char keyServer[16] = {0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81};
	unsigned char counterServer[16] = {0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0x00};
	
//	string encrypted_keyword_counter_arr[MATRIX_ROW_SIZE];
	unsigned char* encrypted_keyword_counter_arr;
	//unsigned char encrypted_keyword_counter_arr[MATRIX_ROW_SIZE*BLOCK_CIPHER_SIZE];
public:
    Server_DSSE();
    ~Server_DSSE();

    int getBlock_data(zmq::socket_t &socket, int dim);
    int updateBlock_data(zmq::socket_t &socket);
    int getEncrypted_data_structure(zmq::socket_t &socket);
    int getEncrypted_file(zmq::socket_t &socket);
    int searchKeyword(zmq::socket_t &socket);
    int deleteFile(zmq::socket_t &socket);
    
    
    int start();


    int loadState();
    int saveState();
    
    
    int loadData_from_file(int dim, TYPE_INDEX idx);
    int saveData_to_file(int dim, TYPE_INDEX idx);

};

#endif // SERVER_DSSE_H
