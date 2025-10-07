# PRINTPROCESSOR_CAPS_2 structure

Represents printer capability information.

## Members

**dwLevel**

A value that indicates the structure's version number.

**dwNupOptions**

A bit mask representing the various numbers of document pages the printer can print on a single side of a physical sheet. The least significant bit represents one document page per side, the next bit represents 2 document pages per side, and so on. For example, 0x0000810B indicates the printer supports 1, 2, 4, 9, and 16 document pages per physical side.

**dwPageOrderFlags**

A flag value that indicates the order in which pages will be printed. It can be **NORMAL\_PRINT**, **REVERSE\_PRINT**, or **BOOKLET\_PRINT**.

**dwNumberOfCopies**

The maximum number of copies the printer can handle.

**dwNupDirectionCaps**

The available patterns when multiple document pages are printed on the same side of a sheet of paper. The possible flags are the following:

| Value | Meaning |
|---------------------------|-----------------------------------------------------------------------------------------------------|
| PPCAPS\_RIGHT\_THEN\_DOWN | Pages appear in rows from right to left, each subsequent row below its predecessor. |
| PPCAPS\_DOWN\_THEN\_RIGHT | Pages appear in columns from top to bottom, each subsequent column to the right of its predecessor. |
| PPCAPS\_LEFT\_THEN\_DOWN | Pages appear in rows from left to right, each subsequent row below its predecessor. |
| PPCAPS\_DOWN\_THEN\_LEFT | Pages appear in columns from top to bottom, each subsequent column to the left of its predecessor. |

**dwNupBorderCaps**

Can be only PPCAPS\_BORDER\_PRINT, indicating that, when multiple document pages are being printed on a single side of a physical sheet, the printer can be told whether or not to print a border around the imageable area of each document page.

**dwBookletHandlingCaps**

Can only be PPCAPS\_BOOKLET\_EDGE, indicating that the printer can print booklet style.

**dwDuplexHandlingCaps**

| Value | Meaning |
|-----------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PPCAPS\_REVERSE\_PAGES\_FOR\_REVERSE\_DUPLEX | When printing in reverse order and duplexing, the processor can print swap the order of each pair of pages, so instead of printing in order 4,3,2,1, they will print in the order 3,4,1,2. |
| PPCAPS\_DONT\_SEND\_EXTRA\_PAGES\_FOR\_DUPLEX | When duplexing, the Print Processor can be told not to send an extra page when there is an odd number of document pages. The processor will honor the value as best it can, but in cases where preventing an extra blank page would cause improper output, the extra pages may still be sent. |

**dwScalingCaps**

Can only be PPCAPS\_SQUARE\_SCALING, indicating that the printer can scale the page image.

## Remarks

Values for all structure members are supplied by the **GetPrintProcessorCapabilities** function, which is documented in the Windows Driver Kit.

When an application calls [**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata), the spooler calls a print processor's **GetPrintProcessorCapabilities** function and specifies a value name that has a format of **PrintProcCaps\_***datatype*, where *datatype* is the name of an input data type.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

* [Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)
* [Print Spooler API structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)
* [GetPrinterData](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata)