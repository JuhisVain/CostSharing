# CostSharing

A program to compute who pays what.

- Requires a version of QT.
- Compiles with make on linux.
- Run with ./CostSharing

#

Use:
1. Click on tab labeled '+' to add a bill.
2. Doubleclick on the created "Bill" tab to rename it.
3. Input names of payers at the bottom.
4. Select payer of bill from combobox.
5. Click "add item" on top of bill tab.
6. Input item's name and price in their respective columns. 
7. The columns under the payers' names are for weights. Input 1 for a share or 0 for no share.
8. Create more bills and items as required.
9. Click "calculate" button. Total <b>owed</b> money shows up on last line.

#

- The total owed is global among all bills, meaning the same line will appear on all bills.
- A negative total means that the user is owed money.
- The fractions are fractions of cents/pennies/smallmoneyunits so not of
particular interest unless you're running a bank
- Don't run a bank with this
- Fractions are always added to total so if a fraction is negative it is in fact subtracted.

#

Jane is owed 2653 - 3/4 small money units.
That is 26 big moneys and 52.25 small moneys.
![Alt text](/other/SS.png "Screenshot")

