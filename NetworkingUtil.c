#include <stdio.h>
#include <stdlib.h>

int main(){
	int choice;
	char cmd[100], link[100];
	
	do{
		printf("\n===== Networking Utilities in Linux =====\n");
		printf("\n1. ifconfig (To check IP configuration).");
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
				printf("\n--- ifconfig help ---\n");
				system("ifconfig --help");
				
				printf("\n--- ifconfig execution ---\n");
				system("ifconfig");
				
				break;
				
			case 2:
				printf("\n--- ping help ---\n");
				system("ping --help");
				
				printf("\n--- ping execution ---\n");
				
				printf("\nEnter the link of the website to check connectivity (EXAMPLE: www.google.com): ");
				scanf("%99s", link);
				
				snprintf(cmd,sizeof(cmd),"ping %s",link);
				system(cmd);
				
				break;
				
			case 3:
				printf("\n--- netstat help ---\n");
				system("netstat --help");
				
				printf("\n--- netstat execution ---\n");
				system("netstat");
				
				break;
				
			case 4:
				printf("\n--- nslookup help ---\n");
				printf("\nUsage:\n");
                printf(" nslookup [domain_name]\n\n");
                printf("Common Options:\n");
                printf(" -type=<record_type>   Query a specific DNS record (A, MX, NS, etc.)\n");
                printf(" -port=<port>          Use specified DNS server port\n");
                printf(" -timeout=<seconds>    Set query timeout\n");
                printf(" -retry=<count>        Number of retries\n");
                printf(" -debug                Display debugging information\n");
                printf(" -query=<type>         Specify query type\n");
				
				printf("\n--- nslookup execution ---\n");
				
				printf("\nEnter the link of the website to check connectivity (EXAMPLE: www.google.com): ");
				scanf("%99s", link);
				
				snprintf(cmd,sizeof(cmd),"nslookup %s",link);
				system(cmd);
				
				break;
				
			case 5:
				printf("\n--- hostname help ---\n");
				system("hostname -help");
				
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
