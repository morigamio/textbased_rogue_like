#include <iostream>
#include <windows.h>

void setConsoleSize(short cols, short rows) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // Fenster erst klein machen, damit der Puffer schrumpfen darf
    SMALL_RECT minimal = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(h, TRUE, &minimal);

    // Puffergröße setzen
    COORD buffer = { cols, rows };
    SetConsoleScreenBufferSize(h, buffer);

    // Fenster auf gewünschte Größe
    SMALL_RECT window = { 0, 0, (short)(cols - 1), (short)(rows - 1) };
    SetConsoleWindowInfo(h, TRUE, &window);
}

int main() {

	// define console dimensions
    setConsoleSize(120, 40);
	std::cout << "Hello World!" << std::endl;
}


