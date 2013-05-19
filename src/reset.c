extern void SystemInit(void);
extern void start(void);

void ResetHandler(void)
{
	//init();
	SystemInit();
	
	start();
	
	while(1) {
		;
	}
}
