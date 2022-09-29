*******************************************************
*  Name      :  Austin Long              
*  Class     :  CSC 2312 Section H01           
*  HW#       :  2 Part 3                
*  Due Date  :  Sept 20th, 2022
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Prompts the user to enter an initial deposit amount and select their annual interest rate
2. Generates a random monthly  withdrawal amount between $480 and $620. Calculates the interest
   compounded monthly after the withdrawal is made.
3. Repeats until the balance becomes $0 or the interest earned starts to outweigh the withdrawal amount.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Entire program written in int main(). Variables declared
   as needed.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully for dollar amounts under $9500 and/or interest
   rates less than 6%. If the initial deposit amount and/or the interest rate
   are too high, the interest rate formula causes the balance to go up and the program 
   loops forever. This is handle with a check that says if the interest earned that month is
   higher than the withdrawal amount for the month then a message is printed out and the program ends.
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server, windows console, and replit


*******************************************************
*  How to build and run the program
*******************************************************

1. Open the main.cpp file in replit and click run
2. Enter an initial deposit amount and desired interest rate

*******************************************************
* Output
*******************************************************
Test Run #1: Low Amounts - $3000 & 5%

How much would you like to deposit? 3000
You've deposited: $3000.00
In a perfect world, we can pick our interest rate. What annual interest rate would you like? 5
You've chosen an interest rate of 5.00% per year.
Give me a moment to find out how long before you go broke. Assuming you withdraw an amount between $480 to $620 each month
# of Month      Month/Year      Initial Balance         Withdrawal              Interest        New Balance
==========      ==========      ===============         ==========              ========        ===========
        1       January 2022    $3000.00                $596                    $122.99         $2526.99
        2       February 2022   $2526.99                $539                    $101.71         $2089.70
        3       March 2022      $2089.70                $565                    $78.01          $1602.71
        4       April 2022      $1602.71                $513                    $55.75          $1145.46
        5       May 2022        $1145.46                $582                    $28.83          $592.29
        6       June 2022       $592.29                 $557                    $1.81           $37.09
        7       July 2022       $37.09                  $37.09                  $0.00           $0.00
You have 7 months before you need to panhandle down Colfax.

Test Run #2: Low Initial Deposit ($3000) + High Interest Rate (20%)

How much would you like to deposit? 3000
You've deposited: $3000.00
In a perfect world, we can pick our interest rate. What annual interest rate would you like? 20
You've chosen an interest rate of 20.00% per year.
Give me a moment to find out how long before you go broke. Assuming you withdraw an amount between $480 to $620 each month
# of Month      Month/Year      Initial Balance         Withdrawal              Interest        New Balance
==========      ==========      ===============         ==========              ========        ===========
        1       January 2022    $3000.00                $604                    $525.66         $2921.66
        2       February 2022   $2921.66                $576                    $514.62         $2860.28
        3       March 2022      $2860.28                $609                    $493.91         $2745.19
        4       April 2022      $2745.19                $490                    $494.77         $2749.96
You're set for life, clearly this is a stable economic system.Interest rate of growth is greater than your monthly withdrawal amount, feel free to spend more.

Test Run #3: High Initial Deposit ($10000) + Low Interest Rate (3%)

How much would you like to deposit? 10000
You've deposited: $10000.00
In a perfect world, we can pick our interest rate. What annual interest rate would you like? 3
You've chosen an interest rate of 3.00% per year.
Give me a moment to find out how long before you go broke. Assuming you withdraw an amount between $480 to $620 each month
# of Month      Month/Year      Initial Balance         Withdrawal              Interest        New Balance
==========      ==========      ===============         ==========              ========        ===========
        1       January 2022    $10000.00               $538                    $287.80         $9749.80
        2       February 2022   $9749.80                $496                    $281.46         $9535.26
        3       March 2022      $9535.26                $560                    $272.99         $9248.25
        4       April 2022      $9248.25                $576                    $263.77         $8936.02
        5       May 2022        $8936.02                $620                    $252.94         $8568.96
        6       June 2022       $8568.96                $556                    $243.72         $8256.69
        7       July 2022       $8256.69                $488                    $236.29         $8004.98
        8       August 2022     $8004.98                $544                    $226.93         $7687.91
        9       September 2022  $7687.91                $539                    $217.44         $7366.35
        10      October 2022    $7366.35                $525                    $208.09         $7049.44
        11      November 2022   $7049.44                $534                    $198.17         $6713.61
        12      December 2022   $6713.61                $518                    $188.45         $6384.06
        1       January 2023    $6384.06                $562                    $359.55         $6181.61
        2       February 2023   $6181.61                $485                    $351.81         $6048.42
        3       March 2023      $6048.42                $579                    $337.77         $5807.19
        4       April 2023      $5807.19                $506                    $327.39         $5628.58
        5       May 2023        $5628.58                $591                    $311.11         $5348.68
        6       June 2023       $5348.68                $587                    $294.07         $5055.75
        7       July 2023       $5055.75                $619                    $274.00         $4710.75
        8       August 2023     $4710.75                $500                    $260.04         $4470.79
        9       September 2023  $4470.79                $534                    $243.12         $4179.92
        10      October 2023    $4179.92                $483                    $228.31         $3925.23
        11      November 2023   $3925.23                $577                    $206.78         $3555.01
        12      December 2023   $3555.01                $508                    $188.17         $3235.18
        1       January 2024    $3235.18                $572                    $250.48         $2913.66
        2       February 2024   $2913.66                $570                    $220.42         $2564.08
        3       March 2024      $2564.08                $620                    $182.84         $2126.92
        4       April 2024      $2126.92                $544                    $148.88         $1731.80
        5       May 2024        $1731.80                $483                    $117.45         $1366.25
        6       June 2024       $1366.25                $552                    $76.58          $890.83
        7       July 2024       $890.83                 $496                    $37.13          $431.97
        8       August 2024     $431.97                 $431.97                 $0.00           $0.00
You have 32 months before you need to panhandle down Colfax.

Test Run #4: High Initial Deposit ($10000) + High Interest Rate (6%)

How much would you like to deposit? 10000
You've deposited: $10000.00
In a perfect world, we can pick our interest rate. What annual interest rate would you like? 6
You've chosen an interest rate of 6.00% per year.
Give me a moment to find out how long before you go broke. Assuming you withdraw an amount between $480 to $620 each month
# of Month      Month/Year      Initial Balance         Withdrawal              Interest        New Balance
==========      ==========      ===============         ==========              ========        ===========
        1       January 2022    $10000.00               $557                    $582.42         $10025.42
You're set for life, clearly this is a stable economic system.Interest rate of growth is greater than your monthly withdrawal amount, feel free to spend more.
