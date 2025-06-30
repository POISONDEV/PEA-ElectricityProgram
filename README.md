# Electricity Bill Calculator

A comprehensive C program for calculating electricity bills based on Thai electricity tariff rates for different customer types and usage patterns.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Customer Types](#customer-types)
- [Installation](#installation)
- [Usage](#usage)
- [Rate Types](#rate-types)
- [Program Structure](#program-structure)
- [Examples](#examples)
- [Technical Details](#technical-details)
- [Contributing](#contributing)

## 🔍 Overview

This program calculates electricity bills for various customer categories in Thailand, supporting multiple tariff structures including Regular Rate, Time-of-Use (TOU), and Time-of-Day (TOD) billing systems. It incorporates fuel tariff (Ft) charges, VAT calculations, and voltage-based pricing tiers.

## ✨ Features

- **Multi-customer support**: 8 different customer categories
- **Multiple rate structures**: Regular, TOU, and TOD rates
- **Voltage-based pricing**: Different rates for various voltage levels
- **Year-based calculations**: Support for years 2566-2568 (Buddhist calendar)
- **Comprehensive billing**: Includes base charges, fuel tariffs, and VAT
- **Interactive menu system**: User-friendly command-line interface

## 🏢 Customer Types

1. **House (บ้านอยู่อาศัย)**
   - Regular Rate & TOU Rate
   - Tiered pricing for different usage levels
   - Special rates for usage ≤150 kWh and >150 kWh

2. **Small Business (ธุรกิจขนาดเล็ก)**
   - Regular Rate & TOU Rate
   - Voltage options: 22-33 kV and <22 kV

3. **Medium Business (ธุรกิจขนาดกลาง)**
   - Regular Rate & TOU Rate
   - Voltage options: ≥60 kV, 22-33 kV, <22 kV
   - Includes demand charges and power factor penalties

4. **Large Business (ธุรกิจขนาดใหญ่)**
   - TOD Rate & TOU Rate
   - Voltage options: ≥69 kV, 22-33 kV, <22 kV
   - Complex demand and energy charge structures

5. **Specific Business (ธุรกิจเฉพาะ)**
   - Regular Rate & TOU Rate
   - Voltage options: ≥66 kV, 22-33 kV, <22 kV

6. **Non-profit Organization (องค์การไม่แสวงหากำไร)**
   - Regular Rate & TOU Rate
   - Special rates for non-profit entities

7. **Pump Water for Agriculture (สูบน้ำเพื่อการเกษตร)**
   - Regular Rate & TOU Rate
   - Agricultural-specific pricing structure

8. **Temporary Electricity (ไฟฟ้าชั่วคราว)**
   - Fixed rate structure for temporary connections

## 🚀 Installation

### Prerequisites
- GCC compiler or any C compiler
- Windows/Linux/macOS operating system

### Compilation
```bash
gcc -o electricity_calculator Miniproject.c
```

### Running the Program
```bash
./electricity_calculator
```

## 💻 Usage

1. **Start the program**
   ```
   ./electricity_calculator
   ```

2. **Select customer type** from the main menu (1-9)

3. **Choose rate type** (Regular/TOU/TOD depending on customer type)

4. **Enter required information**:
   - Year (2566/2567/2568)
   - Voltage level
   - Electricity usage amounts
   - Demand values (for applicable customer types)

5. **View calculated bill** with detailed breakdown

### Example Usage Flow
```
===== Electricity Type Menu =====
[1] House
[2] Small Business
[3] Medium Business
[4] Large Business
[5] Specific Business
[6] Non-profit organization
[7] Pump water for agriculture
[8] Temporary electricity
[9] Exit

Select Choice : 1

1.Regular Rate
2.TOU Rate
Select Type : 1

Select Year (2566/2567/2568) : 2568
Enter electricity usage (kWh): 250
```

## 📊 Rate Types

### Regular Rate
- Standard tiered pricing based on usage levels
- Fixed service charges
- Simple calculation structure

### Time-of-Use (TOU) Rate
- **On-Peak**: Higher rates during peak demand hours
- **Off-Peak**: Lower rates during low demand periods
- **Holiday**: Special rates for holidays and weekends

### Time-of-Day (TOD) Rate
- **On-Peak**: Peak demand periods
- **Partial-Peak**: Moderate demand periods
- **Off-Peak**: Low demand periods
- **Holiday**: Special holiday rates

## 🏗️ Program Structure

```
Miniproject.c
├── main()                    # Entry point
├── Menu()                    # Main menu system
├── Line()                    # UI formatting function
├── House()                   # Residential calculations
├── Small_Business()          # Small business calculations
├── Medium_Business()         # Medium business calculations
├── Large_Business()          # Large business calculations
├── Specific_Business()       # Specific business calculations
├── Nonprofit_organization()  # Non-profit calculations
├── Pump_Water()             # Agricultural calculations
└── Temporary_electricity()   # Temporary connection calculations
```

### Key Data Structures
```c
typedef struct {
    int year;    // Billing year (2566-2568)
    int vt;      // Voltage type
} voltage;
```

## 📈 Examples

### House - Regular Rate (≤150 kWh)
```
Input: 120 kWh, Year 2568
Output:
- Base Cost: 420.50 baht
- Ft Cost: 44.40 baht
- VAT (7%): 32.54 baht
- Total: 497.44 baht
```

### Small Business - TOU Rate
```
Input: On-Peak: 100 kWh, Off-Peak: 150 kWh, Holiday: 50 kWh
Voltage: 22-33 kV
Output:
- Service fee: 312.24 baht
- Energy charges calculated by time period
- Ft and VAT applied
```

## 🔧 Technical Details

### Voltage Classifications
- **High Voltage**: ≥69 kV, ≥66 kV, ≥60 kV
- **Medium Voltage**: 22-33 kV
- **Low Voltage**: <22 kV

### Rate Components
1. **Base Electricity Charge**
   - Service fees
   - Energy charges
   - Demand charges (where applicable)

2. **Fuel Tariff (Ft)**
   - Variable rate: 0.3672 baht/kWh (default)
   - Year-specific adjustments

3. **Value Added Tax (VAT)**
   - 7% on total base cost + Ft

### Calculation Formula
```
Total Bill = (Base Cost + Ft Cost) + VAT
VAT = (Base Cost + Ft Cost) × 0.07
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

### Code Style Guidelines
- Use descriptive variable names
- Comment complex calculations
- Follow existing indentation patterns
- Test with various input scenarios

## 📝 Notes

- This program uses the Buddhist calendar system (years 2566-2568 correspond to 2023-2025 CE)
- Rates and charges are based on Thai electricity tariff structures
- The program includes comprehensive error handling for invalid inputs
- All monetary values are calculated in Thai Baht (THB)

## 📞 Support

For questions or issues:
1. Check the code comments for calculation details
2. Verify input formats match expected ranges
3. Ensure proper selection of customer type and rate structure

---

**Note**: This calculator is designed for educational purposes and may require updates to reflect current electricity tariff rates.
