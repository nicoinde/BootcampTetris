
/*struct marco
{
	int forma[4][4];
}pos0, pos1, pos2, pos3;*/
int pos0[4][4];
int pos1[4][4];
int pos2[4][4];
int pos3[4][4];
int currentPos;
int type;

class Tetromino {

public:	
	Tetromino();
	~Tetromino() {
		/*delete pos0;
		delete pos1;
		delete pos2;
		delete pos3;*/
		
	}
	int getCurrentPos() {
		return currentPos;
	}
	int** cargarForma() {
		int** forma = 0;
		forma = new int*[4];
		for (int i = 0; i < 4; i++)
		{	
			forma[i] = new int[4];
			for (int j = 0; j < 4; j++)
			{
				switch (currentPos) {
				case 0: forma[i][j] = pos0[i][j]; break;
				case 1: forma[i][j] = pos1[i][j]; break;
				case 2: forma[i][j] = pos2[i][j]; break;
				case 3: forma[i][j] = pos3[i][j]; break;
				}
				
			}
		}
		return forma;
	}
	
	

	/*int** getForma() {
		int** forma;
		switch (currentPos) {
		case 0: forma = cargarForma(pos0); break;
		case 1: forma = cargarForma(pos1); break;
		case 2: forma = cargarForma(pos2); break;
		case 3: forma = cargarForma(pos3); break;
		}
		return forma;
	}*/


	int getType() {
		return type;
	}
};