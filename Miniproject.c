#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int vt;
} voltage;

float electamount, sum, basecost, fttotal, vat, onpeakd, offpeakd, onpeak, offpeak, holidayd, holiday, react;
const float ft = 0.3672;

Line(int count) //Create Lines
{
	int i;

	printf("\n------------------------------------------\n");
	for(i=1;i<=count;i++)
		printf("-");
	printf("\n");

}

Menu () { //Main Menu
    int choice, type;

    do {
    printf("===== Electricity Type Menu =====");
    printf("\n[1] House\n[2] Small Business\n[3] Medium Business\n[4] Large Business\n[5] Specific Business\n[6] Non-profit organization\n[7] Pump water for agriculture\n[8] Temporary electricity\n[9] Exit\n");
        printf("Select Choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                House(&type);
                break;
            case 2:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Small_Business(&type);
                break;
            case 3:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Medium_Business(&type);
                break;
            case 4:
                printf("\n1.TOD Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Large_Business(&type);
                break;
            case 5:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Specific_Business(&type);
                break;
            case 6:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Nonprofit_organization(&type);
                break;
            case 7:
                printf("\n1.Regular Rate\n2.TOU Rate\n");
                printf("Select Type : ");
                scanf("%d", &type);
                Pump_Water(&type);
                break;
            case 8:
                Temporary_electricity();
                break;
            case 9:
                printf("\n\t\t\t\t\tThank You For Use Program!!!\n\n");
                system("pause");
                break;
            default:
                printf("Please Select Menu Again");
        }
        printf("\n");
    } while (choice != 9);
}

int main() {
    
    Menu();

    return 0;
}

House (int *type) {

    voltage vt;

    printf("Select Year (2566/2567/2568) : ");
    scanf("%d", &vt.year);

    if (*type == 1) { //Menu 1.1
        int choice;
        float totalBill;
    
        printf("\n=== Normal ===\n");
        printf("1. kWh <= 150\n");
        printf("2. kWh > 150\n");
        printf("Select: ");
        scanf("%d", &choice);

        printf("Enter electricity usage (kWh): ");
        scanf("%f", &electamount);

        if (choice == 1 && electamount <= 150) {
            float baseCost = 0.0;
            float ftCost, vat;

            if (electamount <= 15) {
                baseCost = electamount * 2.3488;
            } else if (electamount <= 25) {
                baseCost = 15 * 2.3488 + (electamount - 15) * 2.9882;
            } else if (electamount <= 35) {
                baseCost = 15 * 2.3488 + 10 * 2.9882 + (electamount - 25) * 3.2405;
            } else if (electamount <= 100) {
                baseCost = 15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + (electamount - 35) * 3.6237;
            } else if (electamount <= 150) {
                baseCost = 15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + (electamount - 100) * 3.7171;
            } else if (electamount <= 400) {
                baseCost = 15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171 + (electamount - 150) * 4.2218;
            } else {
                baseCost = 15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171 + 250 * 4.2218 + (electamount - 400) * 4.4217;
            }

            baseCost += 8.19;
            if (vt.year == 2568) {
                fttotal = electamount * 0.37;
            } else if (vt.year == 2567) {
                fttotal = electamount * 0.40;
            } else if (vt.year == 2566) {
                fttotal = electamount * 0.93;
            }

            vat = (baseCost + fttotal) * 0.07;
            totalBill = baseCost + fttotal + vat;
            
            printf("\n=== Electricity Bill (≤ 150 kWh) ===\n");
        } 
        else if (choice == 2 && electamount > 150) {
            if (electamount <= 150) {
                totalBill = electamount * 3.2482;
            } else if (electamount <= 400) {
                totalBill = (150 * 3.2482) + ((electamount - 150) * 4.2218);
            } else {
                totalBill = (150 * 3.2482) + (250 * 4.2218) + ((electamount - 400) * 4.4217);
            }
        
            totalBill += 38.22;
            printf("\n=== Electricity Bill (> 150 kWh) ===\n");
        } 
        else {
            printf("Invalid kWh range for this option.\n");
            return;
        }
        printf("Total cost: %.2f baht\n", totalBill);
    } else if (*type == 2) { // Menu 1.2
        int voltageLevel;
        float onpeak, offpeak, holiday;

        printf("\n=== TOU ===\n");
        printf("1. Voltage 22 - 33 kV\n");
        printf("2. lower than voltage 22 kV\n");
        printf("Select: ");
        scanf("%d", &voltageLevel);
    
        if (voltageLevel != 1 && voltageLevel != 2) {
            printf("Invalid selection.\n");
            return;
        }
    
        printf("Enter electricity usage during On-Peak hours (kWh): ");
        scanf("%f", &onpeak);
        printf("Enter electricity usage during Off-Peak hours (kWh): ");
        scanf("%f", &offpeak);
        printf("Enter electricity usage during Holiday hours (kWh): ");
        scanf("%f", &holiday);
    
        float onPeakRate, offPeakRate, serviceCharge;
        float baseCost, ftCost, vat, totalBill;

        if (vt.year == 2568) {
            fttotal = electamount * 0.37;
        } else if (vt.year == 2567) {
            fttotal = electamount * 0.40;
        } else if (vt.year == 2566) {
            fttotal = electamount * 0.93;
        }

        if (voltageLevel == 1) { // แรงดัน 22 – 33 kV
            onPeakRate = 5.1135;
            offPeakRate = 2.6037;
            serviceCharge = 312.24;
        } else { // แรงดันต่ำกว่า 22 kV
            onPeakRate = 5.7982;
            offPeakRate = 2.6369;
            serviceCharge = 38.22;
        }

        baseCost = (onpeak * onPeakRate) + (offpeak * offPeakRate) + (holiday * offPeakRate) + serviceCharge;
        ftCost = (onpeak + offpeak + holiday) * fttotal;
        vat = (baseCost + ftCost) * 0.07;
        totalBill = baseCost + ftCost + vat;
    
        printf("\n=== Electricity Bill (TOU) ===\n");
        printf("Total cost: %.2f baht\n", totalBill);
    }
}

Small_Business(int *type) {
	
	voltage datedata;
    float offpeak, onpeak;

    if (*type == 1) { //Menu 2.1
        printf("Select Year (2566/2567/2568) : ");
        scanf("%d", &datedata.year);
        printf("Voltage Type (1. 22-33 kWh 2. < 22 kWh) : ");
        scanf("%d", &datedata.vt);
        printf("Electricity amount : ");
        scanf("%f", &electamount);
        
        basecost = 3.2484 * electamount;
		fttotal = ft * electamount;
        
        if (datedata.vt == 1) {
        	
        	vat = (312.24 + basecost + fttotal) * 0.07;
        	
            if ((datedata.year == 2568)) {
                sum = (312.24+basecost) + fttotal + vat;
            }else if (datedata.year == 2567) {
				sum = (312.24+basecost) + fttotal + vat;
            }else if (datedata.year == 2566) {
				sum = (312.24+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", 312.24 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }else if (datedata.vt == 2) { //Menu 2.2
        	
        	vat = (46.16 + basecost + fttotal)*0.07;
            if (datedata.year == 2568) {
				sum = (46.16+basecost) + fttotal + vat;
            }else if (datedata.year == 2567) {
				sum = (46.16+basecost) + fttotal + vat;
            }else if (datedata.year == 2566) {
				sum = (46.16+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 46.16 baht\n");
    		printf("Total cost: %.2f baht\n", 46.16 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }
    }else if (*type == 2) {
    	printf("Select Year (2566/2567/2568) : ");
        scanf("%d", &datedata.year);
        printf("Voltage Type (1. 22-33 kWh 2. < 22 kWh) : ");
        scanf("%d", &datedata.vt);
        printf("Electricity consumption during On-Peak period : ");
        scanf("%f", &onpeak);
        printf("Electricity consumption during Off-Peak period : ");
        scanf("%f", &offpeak);
        printf("Electricity consumption during Holiday period : ");
        scanf("%f", &electamount);
        
        basecost = (5.7982 * onpeak) + (2.6369 * offpeak) + (2.6369 * electamount);
        fttotal = (onpeak + offpeak + electamount) * ft;
        
        if (datedata.vt == 1) {
        	vat = (312.24 + basecost + fttotal) * 0.07;
            if ((datedata.year == 2568)) {
                sum = (312.24+basecost) + fttotal + vat;
            }else if (datedata.year == 2567) {
				sum = (312.24+basecost) + fttotal + vat;
            }else if (datedata.year == 2566) {
				sum = (312.24+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", 312.24 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }else if (datedata.vt == 2) {
        	vat = (46.16 + basecost + fttotal)*0.07;
            if (datedata.year == 2568) {
				sum = (46.16+basecost) + fttotal + vat;
            }else if (datedata.year == 2567) {
				sum = (46.16+basecost) + fttotal + vat;
            }else if (datedata.year == 2566) {
				sum = (46.16+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 46.16 baht\n");
    		printf("Total cost: %.2f baht\n", 46.16 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }
    }
}

Medium_Business(int *type) {
	voltage vt;
    float max, onpeak, offpeak, reactive, demand, power, onpeakd, offpeakd, holiday;

    if (*type == 1) { //Menu 3.1
        printf("Select Year (2566/2567/2568) : ");
        scanf("%d", &vt.year);
        printf("Voltage Type (1. >= 60 kwh 2. 22-33 kWh 3. < 22 kWh) : ");
        scanf("%d", &vt.vt);
        printf("Peak Electricity Demand : ");
        scanf("%f", &max);
        printf("Reactive Power Demand : ");
        scanf("%f", &reactive);
        printf("Electricity amount : ");
        scanf("%f", &electamount);
        
		fttotal = ft * electamount;
        power = 56.07 * (reactive - 1);
        
        
        if (vt.vt == 1) {

            basecost = 3.1097 * electamount;
            demand = 175.70 * max;
            vat = (demand + 312.24 + basecost + power + fttotal) * 0.07;
        	
            if ((vt.year == 2568)) {
                sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2567) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2566) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
            printf("Electrical Demand Value: 175.70 baht\n");
            printf("Electrical Energy Value: %.2f baht\n", basecost);
            printf("Power Factor Value\n");
            printf("Billable Kilovar Quantity : %d kVAr\n", reactive-1);
            printf("Total Amount: %.2f baht\n", power);
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", demand + 312.24 + basecost + power + fttotal);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);

        } else if (vt.vt == 2) {
        	
            basecost = 3.1471 * electamount;
        	demand = 196.26 * max;
            vat = (demand + 312.24 + basecost + power + fttotal) * 0.07;
        	
            if ((vt.year == 2568)) {
                sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2567) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2566) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
            printf("Electrical Demand Value: 196.26 baht\n");
            printf("Electrical Energy Value: %.2f baht\n", basecost);
            printf("Power Factor Value\n");
            printf("Billable Kilovar Quantity : %d kVAr\n", reactive-1);
            printf("Total Amount: %.2f baht\n", power);
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", demand + 312.24 + basecost + power + fttotal);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        } else if (vt.vt == 3) {
        	
            basecost = 3.1751 * electamount;
        	demand = 221.50 * max;
            vat = (demand + 312.24 + basecost + power + fttotal) * 0.07;
        	
            if ((vt.year == 2568)) {
                sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2567) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }else if (vt.year == 2566) {
				sum = (demand + 312.24 + basecost + power) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
            printf("Electrical Demand Value: 221.50 baht\n");
            printf("Electrical Energy Value: %.2f baht\n", basecost);
            printf("Power Factor Value\n");
            printf("Billable Kilovar Quantity : %d kVAr\n", reactive-1);
            printf("Total Amount: %.2f baht\n", power);
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", demand + 312.24 + basecost + power + fttotal);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }
    }else if (*type == 2) { //Menu 3.2
    	printf("Select Year (2566/2567/2568) : ");
        scanf("%d", &vt.year);
        printf("Voltage Type (1. >= 69 kwh 2. 22-33 kWh 3. < 22 kWh) : ");
        scanf("%d", &vt.vt);
        printf("On-Peak Electrical Power Demand : ");
        scanf("%f", &onpeakd);
        printf("Off-Peak Electrical Power Demand : ");
        scanf("%f", &offpeakd);
        printf("Holiday Electrical Power Demand : ");
        scanf("%f", &holiday);
        printf("Electricity consumption during On-Peak period : ");
        scanf("%f", &onpeak);
        printf("Electricity consumption during Off-Peak period : ");
        scanf("%f", &offpeak);
        printf("Electricity consumption during Holiday period : ");
        scanf("%f", &electamount);
        printf("Reactive Power Demand : ");
        scanf("%f", &reactive);
        
        
        fttotal = 1.10;
        
        if (vt.vt == 1) {

        	vat = (312.24 + basecost + fttotal) * 0.07;
            basecost = (4.1025 * onpeak) + (2.5849 * offpeak) + (74.14 * onpeakd) + (0	* offpeakd) + (2.5849 * electamount);

            if ((vt.year == 2568)) {
                sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2567) {
				sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2566) {
				sum = (312.24+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", 312.24 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }else if (vt.vt == 2) {

        	vat = (312.24 + basecost + fttotal)*0.07;
            basecost = (4.1839 * onpeak) + (2.6037 * offpeak) + (132.93 * onpeakd) + (0	* offpeakd) + (3.18 * electamount);

            if (vt.year == 2568) {
				sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2567) {
				sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2566) {
				sum = (312.24+basecost) + fttotal + vat;
            }
            Line(45);
    		printf("\nPart 1 Base electricity charge\n");
    		printf("Service fee: 312.24 baht\n");
    		printf("Total cost: %.2f baht\n", 312.24 + basecost);

    		printf("\nPart 2 Variable electricity cost (Ft)\n");
    		printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

    		printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    		printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    		printf("\n=== Total electricity bill ===\n");
    		printf("= %.2f baht\n", sum);
    		Line(45);
        }else if (vt.vt == 3) {

            basecost = (4.3297 * onpeak) + (2.6369 * offpeak) + (210.00	 * onpeakd) + (0	* offpeakd) + (3.21 * electamount);
            vat = (312.24 + basecost + fttotal)*0.07;

            if (vt.year == 2568) {
                sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2567) {
                sum = (312.24+basecost) + fttotal + vat;
            }else if (vt.year == 2566) {
                sum = (312.24+basecost) + fttotal + vat;
            }
            Line(45);
            printf("\nPart 1 Base electricity charge\n");
            printf("Service fee: 312.24 baht\n");
            printf("Total cost: %.2f baht\n", 312.24 + basecost);

            printf("\nPart 2 Variable electricity cost (Ft)\n");
            printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

            printf("\nPart 3 Value Added Tax (VAT 7%)\n");
            printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

            printf("\n=== Total electricity bill ===\n");
            printf("= %.2f baht\n", sum);
            Line(45);
        }
    }
}

Large_Business(int *type) {

    voltage data;
    int vttype;
    float holiday, partialpeakd, reactive, FT_CHARGE_RATE = 9.18, holidayd, basecost;
    
    if (*type == 1) { //Menu 4.1 TOD

        printf("\nSelect Voltage type:\n");
        printf("1: 69kV and above\n");
        printf("2: 22-33kV\n");
        printf("3: below 22kV\n");
        printf("Select type : ");
        scanf("%d", &vttype);

        printf("Enter On Peak demand (kW): ");
        scanf("%f", &onpeakd);
    
        printf("Enter Partial Peak demand (kW): ");
        scanf("%f", &partialpeakd);
    
        printf("Enter Off Peak demand (kW): ");
        scanf("%f", &offpeakd);
    
        printf("Enter Holiday demand (kW): ");
        scanf("%f", &holidayd);
    
        printf("Enter Reactive Power (kVAr): ");
        scanf("%f", &reactive);
    
        printf("Enter On Peak Usage (units): ");
        scanf("%d", &onpeak);
    
        printf("Enter Off Peak Usage (units): ");
        scanf("%d", &offpeak);
    
        printf("Enter Holiday Usage (units): ");
        scanf("%d", &holiday);

        float onPeakRate, partialPeakRate, offPeakRate, holidayRate, energyRate;
        float serviceRate = 312.24; // Fixed service charge
        float vatPercent = 7.0;     // VAT percentage
    
    // Set rates based on voltage type
        switch(vttype) {
            case 1: // 69kV and above
                onPeakRate = 224.30;
                partialPeakRate = 29.91;
                offPeakRate = 0.00;
                holidayRate = 20.00;
                energyRate = 3.2484;
                break;
            case 2: // 22-33kV
                onPeakRate = 285.05;
                partialPeakRate = 58.88;
                offPeakRate = 0.00;
                holidayRate = 25.00;
                energyRate = 3.2730;
                break;
            case 3: // Below 22kV
                onPeakRate = 332.71;
                partialPeakRate = 68.22;
                offPeakRate = 0.00;
                holidayRate = 30.00;
                energyRate = 3.2830;
                break;
            default:
                onPeakRate = 224.30;
                partialPeakRate = 29.91;
                offPeakRate = 0.00;
                holidayRate = 20.00;
                energyRate = 3.2484;
        }

        basecost = 312.24 + (onPeakRate * onpeakd) + (partialPeakRate * partialpeakd) + (offPeakRate * offpeakd) + (holidayRate * holidayd);
        fttotal = basecost * ft;
        vat = (basecost + fttotal) * 0.07;
        float total_cost = basecost + fttotal + vat;
    
        Line(45);
        printf("\nPart 1 Base electricity charge\n");
        printf("Service fee: 312.24 baht\n");
        printf("Total cost: %.2f baht\n", basecost);

        printf("\nPart 2 Variable electricity cost (Ft)\n");
        printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, fttotal);

        printf("\nPart 3 Value Added Tax (VAT 7%)\n");
        printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

        printf("\n=== Total electricity bill ===\n");
        printf("= %.2f baht\n", total_cost);
        Line(45);
        
    } else if (*type == 2) { //Menu 4.2 TOU

        printf("\nSelect Year (1: 2566, 2: 2567, 3: 2568): ");
        scanf("%d", &data.year);

        printf("\nSelect Voltage type:\n");
        printf("1: 69kV and above\n");
        printf("2: 22-33kV\n");
        printf("3: below 22kV\n");
        printf("Select type : ");
        scanf("%d", &vttype);

        // Input Demands and Usage
        printf("On-Peak Electrical Power Demand : ");
        scanf("%f", &onpeakd);
        printf("Partial Peak Electrical Power Demand : ");
        scanf("%f", &partialpeakd);
        printf("Off-Peak Electrical Power Demand : ");
        scanf("%f", &offpeakd);
        printf("Reactive Power Demand (kVar) : ");
        scanf("%f", &reactive);
        printf("Electricity amount : ");
        scanf("%f", &electamount);

        // Perform Calculations
        float demand_charge = onpeakd * 74.14;
        float energy_charge = electamount * 4.1025;
        float vat = (312.24 + demand_charge + energy_charge) * 0.07;
        float total_charge = demand_charge + energy_charge + 312.24 + vat;

        // Display Results
        printf("\n===== Calculation Results =====\n");
        printf("Demand Charge: %.2f Baht\n", demand_charge);
        printf("Energy Charge: %.2f Baht\n", energy_charge);
        printf("Ft Charge: %.2f Baht\n", FT_CHARGE_RATE);
        printf("Service Charge: 312.24 Baht\n");
        printf("VAT (7%%): %.2f Baht\n", vat);
        printf("Total Charge: %.2f Baht\n", total_charge);
    }
}

Specific_Business(int *type) {
    voltage vt;
    float max, react, totalBill;
    printf("Select Voltage Type (1. >= 66 kV 2. 22-33 kV 3. < 22 kv) : ");
    scanf("%d", &vt.vt);

    if (*type == 1) { //Menu 5.1

        if (vt.vt == 1) {
            printf("Enter Peak Electric Demand : ");
            scanf("%f", &max);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);
            printf("Enter Electric Usage : ");
            scanf("%f", &electamount);

            float peak = max * 74.14, reactive = react * 56.07, elect = electamount * 4.1025;
            float basecost = 312.24 + peak + reactive + elect, fttotal = electamount * 0.37, vat = (basecost+0.37)*0.07;
            float totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f", totalBill);

        } else if (vt.vt == 2) {
            printf("Enter Peak Electric Demand : ");
            scanf("%f", &max);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);
            printf("Enter Electric Usage : ");
            scanf("%f", &electamount);

            float peak = max * 132.93, reactive = react * 56.07, elect = electamount * 4.1839;
            float basecost = 312.24 + peak + reactive + elect, fttotal = electamount * 0.37, vat = (basecost+0.37)*0.07;
            float totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f", totalBill);
        } else if (vt.vt == 3) {
            printf("Enter Peak Electric Demand : ");
            scanf("%f", &max);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);
            printf("Enter Electric Usage : ");
            scanf("%f", &electamount);

            float peak = max * 210.00, reactive = react * 56.07, elect = electamount * 4.3297;
            float basecost = 312.24 + peak + reactive + elect, fttotal = electamount * 0.37, vat = (basecost+0.37)*0.07;
            float totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f", totalBill);
        }
    } else if (*type == 2) { //Menu 5.2
        if (vt.vt == 1) {
            printf("Enter On-Peak Demand : ");
            scanf("%f", &onpeakd);
            printf("Enter Off-Peak Demand : ");
            scanf("%f", &offpeakd);
            printf("Enter Holiday Electric Demand : ");
            scanf("%f", &holidayd);
            printf("Enter On-Peak Amount : ");
            scanf("%f", &onpeak);
            printf("Enter Off-Peak Amount : ");
            scanf("%f", &offpeak);
            printf("Enter Holiday Amount : ");
            scanf("%f", &holiday);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);

            basecost = 312.24 + ((onpeakd*onpeak)*220.56) + (offpeakd * offpeak) + ((holiday*holidayd)*3.1097) + (react * 56.07);
            fttotal = (holiday*holidayd)*ft;
            vat = (basecost + ft) * 0.07;
            totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f baht", totalBill);
        } else if (vt.vt == 2) {
            printf("Enter On-Peak Demand : ");
            scanf("%f", &onpeakd);
            printf("Enter Off-Peak Demand : ");
            scanf("%f", &offpeakd);
            printf("Enter Holiday Electric Demand : ");
            scanf("%f", &holidayd);
            printf("Enter On-Peak Amount : ");
            scanf("%f", &onpeak);
            printf("Enter Off-Peak Amount : ");
            scanf("%f", &offpeak);
            printf("Enter Holiday Amount : ");
            scanf("%f", &holiday);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);

            basecost = 312.24 + ((onpeakd*onpeak)*256.07) + (offpeakd * offpeak) + ((holiday*holidayd)*3.1471) + (react * 56.07);
            fttotal = (holiday*holidayd)*ft;
            vat = (basecost + ft) * 0.07;
            totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f baht", totalBill);
        } else if (vt.vt == 3) {
            printf("Enter On-Peak Demand : ");
            scanf("%f", &onpeakd);
            printf("Enter Off-Peak Demand : ");
            scanf("%f", &offpeakd);
            printf("Enter Holiday Electric Demand : ");
            scanf("%f", &holidayd);
            printf("Enter On-Peak Amount : ");
            scanf("%f", &onpeak);
            printf("Enter Off-Peak Amount : ");
            scanf("%f", &offpeak);
            printf("Enter Holiday Amount : ");
            scanf("%f", &holiday);
            printf("Enter Reactive Electric Demand : ");
            scanf("%f", &react);

            basecost = 312.24 + ((onpeakd*onpeak)*276.64) + (offpeakd * offpeak) + ((holiday*holidayd)*3.1751) + (react * 56.07);
            fttotal = (holiday*holidayd)*ft;
            vat = (basecost + ft) * 0.07;
            totalBill = basecost + fttotal + vat;

            printf("Total Bill : %.2f baht", totalBill);
        }
    }
}

Nonprofit_organization (int *type) {
    int units, voltageLevel;
    double baseCharge, electricityRate, ftRate = 0.37, vatRate = 0.07, demand, max;

    if (*type == 1) {
        printf("=== Select Voltage Level ===\n");
        printf("1. Voltage 69 kilovolts and above\n");
        printf("2. Voltage 22-33 kilovolts\n");
        printf("3. Voltage below 22 kilovolts\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &voltageLevel);

        switch (voltageLevel) {
            case 1:
                electricityRate = 3.4149;
                baseCharge = 312.24;
                break;
            case 2:
                electricityRate = 3.5849;
                baseCharge = 312.24;
                break;
            case 3:
                electricityRate = 0;
                baseCharge = 20.00;
                break;
            default:
                printf("Invalid choice.\n");
                return 1;
        }

        printf("Enter electricity usage (units): ");
        scanf("%d", &units);
    
        double baseElectricityCost = baseCharge + (units * electricityRate);
    
        double ftCost = units * ftRate;
    
        double vat = (baseElectricityCost + ftCost) * vatRate;
    
        double totalCost = baseElectricityCost + ftCost + vat;
    
        printf("\n=== Electricity Bill Calculation ===\n");
        printf("Base Service Charge: %.2f Baht\n", baseCharge);
        printf("Electricity Cost: %.2f Baht\n", baseElectricityCost);
        printf("Fuel Tariff (Ft): %.2f Baht\n", ftCost);
        printf("VAT (7%%): %.2f Baht\n", vat);
        printf("Total Electricity Bill: %.2f Baht\n", totalCost);
    } else if (*type == 2) {
        printf("=== Select Voltage Level ===\n");
        printf("1. Voltage 69 kilovolts and above\n");
        printf("2. Voltage 22-33 kilovolts\n");
        printf("3. Voltage below 22 kilovolts\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &voltageLevel);

        switch (voltageLevel) {
            case 1:
                demand = 74.14;
                electricityRate = 4.1025;
                baseCharge = 312.24;
                break;
            case 2:
                demand = 132.93;
                electricityRate = 4.1839;
                baseCharge = 312.24;
                break;
            case 3:
                demand = 210.00;
                electricityRate = 4.3297;
                baseCharge = 312.24;
                break;
            default:
                printf("Invalid choice.\n");
                return 1;
        }
        printf("Enter On-Peak Demand : ");
        scanf("%f", &onpeakd);
        printf("Enter Off-Peak Demand : ");
        scanf("%f", &offpeakd);
        printf("Enter Holiday Electric Demand : ");
        scanf("%f", &holidayd);
        printf("Enter On-Peak Amount : ");
        scanf("%f", &onpeak);
        printf("Enter Off-Peak Amount : ");
        scanf("%f", &offpeak);
        printf("Enter Holiday Amount : ");
        scanf("%f", &holiday);
        printf("Enter Reactive Electric Demand : ");
        scanf("%f", &react);

        float basecost = 312.24 + ((onpeakd*onpeak)*220.56) + (offpeakd * offpeak) + ((holiday*holidayd)*3.1097) + (react * 56.07);
        float fttotal = (holiday*holidayd)*ft;
        float vat = (basecost + ft) * 0.07;
        float totalBill = basecost + fttotal + vat;

        printf("Total Bill : %.2f", totalBill);
    }
}

Pump_Water(int *type) {
    if (*type == 1) {
        char type_electricity[100] = "Type 7.1 for agricultural water pumping"; 
        char month[20] = "March"; 
        int year = 2568;
        float ft_rate = 36.72; 
        int usage = 0; 
        float rate_first_100 = 2.0889; 
        float rate_over_100 = 3.2405;  
        float service_charge = 115.16; 
        float energy_cost = 0.0;
        float ft_cost = 0.0;
        float total_cost = 0.0;

        printf("\n=== Agricultural Water Pumping (Normal Rate) ===\n");
        printf("Enter electricity usage (units): ");
        scanf("%d", &usage);

        if (usage <= 100) {
            energy_cost = usage * rate_first_100;
        } else {
            energy_cost = 100 * rate_first_100 + (usage - 100) * rate_over_100;
        }

        ft_cost = (float)usage * ft_rate / 100.0;
        total_cost = energy_cost + ft_cost + service_charge;

        printf("\n------------------------------------\n");
        printf("Electricity Type: %s\n", type_electricity);
        printf("Month: %s Year: %d\n", month, year);
        printf("Electricity Usage: %d units\n", usage);
        printf("Electricity Cost (excluding Ft): %.2f Baht\n", energy_cost);
        printf("Ft Cost: %.2f Baht\n", ft_cost);
        printf("Service Charge: %.2f Baht\n", service_charge);
        printf("------------------------------------\n");
        printf("Total Electricity Cost: %.2f Baht\n", total_cost);
        printf("------------------------------------\n");

    } else if (*type == 2) { 
        char type_electricity[100] = "Type 7.2 Agricultural Water Pumping (TOU Rate)";
        char month[20] = "March";
        int year = 2568;
        float ft_rate = 36.72;
        float service_charge = 204.07;
        int choice;
        float on_peak_demand = 0.0;
        float off_peak_demand = 0.0;
        float holiday_demand = 0.0;
        float on_peak_usage = 0.0;
        float off_peak_usage = 0.0;
        float holiday_usage = 0.0;
        float on_peak_demand_rate, off_peak_demand_rate, on_peak_energy_rate, off_peak_energy_rate;
        float demand_charge, energy_charge, total_usage, ft_cost, subtotal, tax, total_cost;
        float tax_rate = 0.07;

        printf("\nSelect Voltage Type:\n");
        printf("1. 22-33 kV\n");
        printf("2. Less than 22 kV\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("\nEnter Electricity Usage Details:\n");
            printf("Enter On Peak Demand (kW): ");
            scanf("%f", &on_peak_demand);
            printf("Enter Off Peak Demand (kW): ");
            scanf("%f", &off_peak_demand);
            printf("Enter Holiday Demand (kW): ");
            scanf("%f", &holiday_demand);
            printf("Enter On Peak Usage (Units): ");
            scanf("%f", &on_peak_usage);
            printf("Enter Off Peak Usage (Units): ");
            scanf("%f", &off_peak_usage);
            printf("Enter Holiday Usage (Units): ");
            scanf("%f", &holiday_usage);

            if (choice == 1) { 
                on_peak_demand_rate = 132.93;
                off_peak_demand_rate = 0.0;
                on_peak_energy_rate = 4.1839;
                off_peak_energy_rate = 2.6037;
            } else {
                on_peak_demand_rate = 210.00;
                off_peak_demand_rate = 0.0;
                on_peak_energy_rate = 4.3297;
                off_peak_energy_rate = 2.6369;
            }

        
            demand_charge = (on_peak_demand * on_peak_demand_rate) + 
                          (off_peak_demand * off_peak_demand_rate);

            energy_charge = (on_peak_usage * on_peak_energy_rate) + 
                          (off_peak_usage * off_peak_energy_rate) + 
                          (holiday_usage * on_peak_energy_rate);

            total_usage = on_peak_usage + off_peak_usage + holiday_usage;
            ft_cost = total_usage * ft_rate / 100.0;
            subtotal = demand_charge + energy_charge + ft_cost + service_charge;
            tax = subtotal * tax_rate;
            total_cost = subtotal + tax;

           
            printf("\n------------------------------------\n");
            printf("Estimation Results\n");
            printf("------------------------------------\n");
            printf("\nPart 1: Base Electricity Cost\n");
            printf("Service Charge: %.2f Baht\n", service_charge);
            printf("Demand Charge: %.2f Baht\n", demand_charge);
            printf("Energy Charge: %.2f Baht\n", energy_charge);
            printf("Total Base Cost: %.2f Baht\n", demand_charge + energy_charge + service_charge);
            printf("\nPart 2: Variable Electricity Cost (Ft)\n");
            printf("Electricity Energy x Ft Value: %.2f Baht\n", ft_cost);
            printf("\nPart 3: Value Added Tax 7%%\n");
            printf("(Base Electricity Cost + Ft) x 7/100: %.2f Baht\n", tax);
            printf("\nTotal Electricity Bill: %.2f Baht\n", total_cost);
            printf("------------------------------------\n");
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } else {
        printf("Invalid type selection. Please choose 1 for Normal Rate or 2 for TOU Rate.\n");
    }
}


Temporary_electricity() { //Menu 8
    voltage vt;
    int electamount;
    double base_cost, ft_total, vat, total_cost;

    printf("Select Year (2566/2567/2568) : ");
    scanf("%d", &vt.year);

    printf("\n=== Temporary electricity ===\n");
    printf("Electricity users have a quantity of electricity usage : ");
    scanf("%d", &electamount);

    base_cost = electamount * 6.8025;
    ft_total = electamount * ft;
    vat = (base_cost + ft_total) * 0.07;
    total_cost = base_cost + ft_total + vat;

	Line(45);
    printf("\nPart 1 Base electricity charge\n");
    printf("Service fee: 0 baht\n");
    printf("Total cost: %.4f baht\n", base_cost);

    printf("\nPart 2 Variable electricity cost (Ft)\n");
    printf("Electrical energy quantity x Ft value (%.2f): %.2f baht\n", ft, ft_total);

    printf("\nPart 3 Value Added Tax (VAT 7%)\n");
    printf("(Base electricity cost + Ft cost) x 7/100: %.2f baht\n", vat);

    printf("\n=== Total electricity bill ===\n");
    printf("= %.2f baht\n", total_cost);
    Line(45);
}

void calculate_22_24_kv(float on_peak_demand, float off_peak_demand, float holiday_demand, float on_peak_usage, float off_peak_usage, float holiday_usage, float ft_rate, float service_charge) {
    float on_peak_demand_rate = 132.93;
    float off_peak_demand_rate = 0.0;
    float on_peak_energy_rate = 4.1839;
    float off_peak_energy_rate = 2.6037;
    float tax_rate = 0.07;

    float demand_charge = (on_peak_demand * on_peak_demand_rate) + (off_peak_demand * off_peak_demand_rate);

    float energy_charge = (on_peak_usage * on_peak_energy_rate) + (off_peak_usage * off_peak_energy_rate) + (holiday_usage * on_peak_energy_rate);

    float total_usage = on_peak_usage + off_peak_usage + holiday_usage;
    float ft_cost = total_usage * ft_rate / 100.0;

    float subtotal = demand_charge + energy_charge + ft_cost + service_charge;

    float tax = subtotal * tax_rate;

    float total_cost = subtotal + tax;

    printf("\n------------------------------------\n");
    printf("Estimation Results\n");
    printf("------------------------------------\n");
    printf("7.1 Normal Rate\n");
    printf("\nPart 1: Base Electricity Cost\n");
    printf("Service Charge: %.2f Baht\n", service_charge);
    printf("Total Base Electricity Cost: %.2f Baht\n", subtotal - ft_cost - tax); 
    printf("\nPart 2: Variable Electricity Cost (Ft)\n");
    printf("Electricity Energy x Ft Value: %.2f Baht\n", ft_cost);
    printf("\nPart 3: Value Added Tax 7%%\n");
    printf("(Base Electricity Cost + Ft) x 7/100: %.2f Baht\n", tax);
    printf("\nTotal Electricity Bill: %.2f Baht\n", total_cost);
    printf("------------------------------------\n");
}

void calculate_less_than_22_kv(float on_peak_demand, float off_peak_demand, float holiday_demand, float on_peak_usage, float off_peak_usage, float holiday_usage, float ft_rate, float service_charge) {
    float on_peak_demand_rate = 210.00;
    float off_peak_demand_rate = 0.0;
    float on_peak_energy_rate = 4.3297;
    float off_peak_energy_rate = 2.6369;
    float tax_rate = 0.07;

    float demand_charge = (on_peak_demand * on_peak_demand_rate) + (off_peak_demand * off_peak_demand_rate);

    float energy_charge = (on_peak_usage * on_peak_energy_rate) + (off_peak_usage * off_peak_energy_rate) + (holiday_usage * on_peak_energy_rate);

    float total_usage = on_peak_usage + off_peak_usage + holiday_usage;
    float ft_cost = total_usage * ft_rate / 100.0;

    float subtotal = demand_charge + energy_charge + ft_cost + service_charge;

    float tax = subtotal * tax_rate;

    float total_cost = subtotal + tax;

    printf("\n------------------------------------\n");
    printf("Estimation Results\n");
    printf("------------------------------------\n");
    printf("7.1 Normal Rate\n");
    printf("\nPart 1: Base Electricity Cost\n");
    printf("Service Charge: %.2f Baht\n", service_charge);
    printf("Total Base Electricity Cost: %.2f Baht\n", subtotal - ft_cost - tax); // Adjusted to match image
    printf("\nPart 2: Variable Electricity Cost (Ft)\n");
    printf("Electricity Energy x Ft Value: %.2f Baht\n", ft_cost);
    printf("\nPart 3: Value Added Tax 7%%\n");
    printf("(Base Electricity Cost + Ft) x 7/100: %.2f Baht\n", tax);
    printf("\nTotal Electricity Bill: %.2f Baht\n", total_cost);
    printf("------------------------------------\n");
}
