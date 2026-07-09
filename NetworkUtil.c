#include <stdio.h>
#include <stdlib.h>

int main(){
	int choice;
	char cmd[100], link[100];
	
	do{
		printf("\n===== Networking Utilities in Windows =====\n");
		printf("\n1. ipconfig (To check IP configuration).");
		printf("\n2. ping (To check connectivity between network).");
		printf("\n3. netstat (To display active connections).");
		printf("\n4. nslookup (To check the IP address of a DNS).");
		printf("\n5. hostname (To display the name of the device hostname).");
		printf("\n6. Exit from program.");	
		printf("\n============================================\n");
		
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\n--- ipconfig help ---\n");
				system("ipconfig /?");
				
				printf("\n--- ipconfig execution ---\n");
				system("ipconfig");
				
				break;
				
			case 2:
				printf("\n--- ping help ---\n");
				system("ping /?");
				
				printf("\n--- ping execution ---\n");
				
				printf("\nEnter the link of the website to check connectivity (EXAMPLE: www.google.com): ");
				scanf("%99s", link);
				
				snprintf(cmd,sizeof(cmd),"ping %s",link);
				system(cmd);
				
				break;
				
			case 3:
				printf("\n--- netstat help ---\n");
				system("netstat /?");
				
				printf("\n--- netstat execution ---\n");
				system("netstat");
				
				break;
				
			case 4:
				printf("\n--- nslookup help ---\n");
				system("nslookup /?");
				
				printf("\n--- nslookup execution ---\n");
				
				printf("\nEnter the link of the website to check connectivity (EXAMPLE: www.google.com): ");
				scanf("%99s", link);
				
				snprintf(cmd,sizeof(cmd),"nslookup %s",link);
				system(cmd);
				
				break;
				
			case 5:
				printf("\n--- hostname help ---\n");
				system("hostname /?");
				
				printf("\n--- hostname execution ---\n");
				system("hostname");
				
				break;
				
			case 6:
				printf("\nExiting from program...");
				break;
				
			default:
				printf("\nInvalid Choice...");				
		}
	}while(choice!=6);
	
	return 0;
	
}
