#include "CEngine.h"
#include "CAppWindow.h"

int main()
{
	Initialise();

	cp::render::CAppWindow app;

	if (app.init())
	{
		while (app.isRunning())
		{
			app.broadcast();	
		}
	}

	return 0;
}