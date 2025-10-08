# PRINTER\_INFO\_7 structure

The **PRINTER\_INFO\_7** structure specifies directory services printer information. Use this structure with the [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) function to publish a printer's data in the directory service (DS), or to update or remove a printer's published data from the DS. Use this structure with the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function to determine whether a printer is published in the DS.

## Members

**pszObjectGUID**

A pointer to a null-terminated string containing the GUID of the directory service print queue object associated with a published printer. Use the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function to retrieve this GUID.

Before calling [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter), set **pszObjectGUID** to **NULL**.

**dwAction**

Indicates the action for the [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) function to perform. For the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function, this member indicates whether the specified printer is published. This member can be a combination of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DSPRINT\_PENDING**<br>0x80000000 | [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter): Indicates that the system is attempting to complete a publish or unpublish operation started by a [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) call.<br> [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter): This value is not valid. <br> |
| **DSPRINT\_PUBLISH**<br>0x00000001 | [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter): Publishes the printer's data in the DS.<br> [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter): Indicates the printer is published. <br> |
| **DSPRINT\_REPUBLISH**<br>0x00000008 | [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter): The DS data for the printer is unpublished and then published again, refreshing all properties in the published printer. Re-publishing also changes the GUID of the published printer.<br> [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter): Never returns this value. <br> |
| **DSPRINT\_UNPUBLISH**<br>0x00000004 | [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter): Removes the printer's published data from the DS.<br> [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter): Indicates the printer is not published. <br> |
| **DSPRINT\_UPDATE**<br>0x00000002 | [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter): Updates the printer's published data in the DS.<br> [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter): Never returns this value. <br> |

## Remarks

The **PRINTER\_INFO\_7** structure is used in a [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) call to publish printer information to the directory service. The published data includes all values and data for the specified printer found under the SPLDS\_SPOOLER\_KEY, SPLDS\_DRIVER\_KEY, or SPLDS\_USER\_KEY keys created by [**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex).

For [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter), *pszObjectGUID* should be set to **NULL**. For [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter), *pszObjectGUID* returns the GUID of the directory services print queue object associated with a published printer. You can use this GUID with Active Directory Services Interface (ADSI) methods to retrieve published data for the printer. However, the recommended method for retrieving published data is to call the [**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_7W** (Unicode) and **\_PRINTER\_INFO\_7A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

