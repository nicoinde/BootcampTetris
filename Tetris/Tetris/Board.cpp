#include "SFML\Graphics.hpp"
#include "Tetromino.cpp"

int** tablero=0;
class Board {
public:
	Board() {
		tablero = new int*[22];
		for (int fila = 0; fila < 22; fila++)
		{
			tablero[fila] = new int[14];
			for (int col = 0; col < 14; col++)
			{
				tablero[fila][col] = 0;
			}
		}
	}

	int** getTablero()
	{
	return tablero;
	}
	void setTablero(int** tab) {
		tablero = tab;
	}

	//Board por referencia para actualizar el tablero en Main, y devuelve bool para saber si hubo colision, 
	//x e y son las coordenadas de la esquina sup Izquierda del Tetromino 4x4
	bool asentar(Board &tab, Tetromino &pieza, int x, int y) 
	{
		int** tabAux = tab.getTablero();
		//int** forma = pieza.cargarForma();
		int forma[4][4];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				forma[i][j] = pieza.cargarForma()[i][j];
			}
		}
		for (int i = 3; i >= 0; i++)	
		{
			for (int j = 3; j >= 0; j++)
			{
				int aux = tabAux[x + (3 - i)][y + (3 - j)];
				if (aux == 0) {
					if (forma[i][j] == 1) {
						tablero[x + (3 - i)][y + (3 - j)] = pieza.getType();
					}
				}
				else {
					if (forma[i][j] == 1) {
						return false;
					}
				}
			}
		}
		tab.setTablero(tabAux);
	}
};