#include "head.h"

void jidianqi_a()
{
	HC138(5);
	if(refer == 20)
	{
		jidianqi = 1;
		BUZZ = 1;
	}
	else
	{
		jidianqi = 0;
		BUZZ = 0;
	}
	HC138(0);
}
