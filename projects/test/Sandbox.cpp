#include <CpEngine.h>

class Sandbox : public cp::CApplication
{
public:
};

int main()
{
	Sandbox* sb = new Sandbox();
	sb->run();
	
	/*
	cp::render::CAppWindow app;

	if (app.init())
	{
		while (app.isRunning())
		{
			app.broadcast();	
		}
	}
	*/

	SAFE_DELETE(sb);

	return 0;
}