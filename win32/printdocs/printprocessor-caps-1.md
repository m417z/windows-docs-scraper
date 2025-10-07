# PRINTPROCESSOR\_CAPS\_1 structure

The **PRINTPROCESSOR\_CAPS\_1** structure is the format for the printer capability information that is returned by the [**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata) function in the buffer specified by the *pData* variable.

## Members

**dwLevel**

The structure's version number. This value must be 1.

**dwNupOptions**

A bit mask representing the various numbers of document pages the printer can print on a physical page. The least significant bit represents 1 document page per page, the next bit represents 2 document pages per page, and so on. For example, 0x0000810B indicates the printer supports 1, 2, 4, 9, and 16 document pages per physical page.

**dwPageOrderFlags**

The order in which pages will be printed. This value can be NORMAL\_PRINT, REVERSE\_PRINT, or BOOKLET\_PRINT.

**dwNumberOfCopies**

The maximum number of copies the printer can handle.

## Remarks

Values for all structure members are supplied by the [**GetPrintProcessorCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winsplp/nf-winsplp-getprintprocessorcapabilities) function, which is documented in the Windows Driver Kit (WDK).

The spooler calls a print processor's [**GetPrintProcessorCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winsplp/nf-winsplp-getprintprocessorcapabilities) function when an application calls [**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata), specifying a value name with a format of PrintProcCaps\_*datatype*, where *datatype* is the name of an input data type.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata)

