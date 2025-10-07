# DOC\_INFO\_2 structure

The **DOC\_INFO\_2** structure describes a document that will be printed.

## Members

**pDocName**

Pointer to a null-terminated string that specifies the name of the document.

**pOutputFile**

Pointer to a null-terminated string that specifies the name of an output file.

**pDatatype**

Pointer to a null-terminated string that identifies the type of data used to record the document.

**dwMode**

Informs the print spooler of the nature of the data to follow. If this value is zero, the print spooler treats the data sent by subsequent calls to [**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter) as a normal print job (whether or not it is spooled depends on the printer property). If this value is DI\_CHANNEL, only a communications channel is opened. In this case, the data passed into subsequent calls to **WritePrinter** is sent to the printer or subsequent calls to [**ReadPrinter**](https://learn.microsoft.com/windows/win32/printdocs/readprinter) retrieve data from the printer. This mode remains effective until [**EndDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-enddoc) is called.

**JobId**

Reserved for internal use; should be zero.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DOC\_INFO\_2W** (Unicode) and **\_DOC\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EndDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-enddoc)

[**ReadPrinter**](https://learn.microsoft.com/windows/win32/printdocs/readprinter)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

[**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter)

