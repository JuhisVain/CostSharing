# CostSharing

A program to compute who pays what.

- Requires a version of QT.
- Compiles with make on linux.
- Run with ./CostSharing

Use:
1. Click on tab labeled '+' to add a bill.
2. Doubleclick on the created "Bill" tab to rename it.
3. Input names of payers at the bottom.
4. Click "add item" on top of bill tab.
5. Input item's name and price in their respective columns. 
6. The columns under the payers' names are for weights. Input 1 for a share or 0 for no share.
7. Create more bills and items as required.

Problems:
- Loading saved data will break if whitespace used in strings
