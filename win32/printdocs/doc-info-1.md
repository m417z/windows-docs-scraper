# DOC\_INFO\_1 structure

The **DOC\_INFO\_1** structure describes a document that will be printed.

## Members

**pDocName**

Pointer to a null-terminated string that specifies the name of the document.

**pOutputFile**

Pointer to a null-terminated string that specifies the name of an output file. To print to a printer, set this to **NULL**.

**pDatatype**

Pointer to a null-terminated string that identifies the type of data used to record the document. You can retrieve a list of the data type strings supported by a printer by calling [EnumPrintProcessorDatatypes](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DOC\_INFO\_1W** (Unicode) and **\_DOC\_INFO\_1A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

