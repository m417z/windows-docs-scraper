# DOC\_INFO\_3 structure

The **DOC\_INFO\_3** structure describes a document that will be printed.

## Members

**pDocName**

Pointer to a null-terminated string that specifies the name of the document.

**pOutputFile**

Pointer to a null-terminated string that specifies the name of an output file.

**pDatatype**

Pointer to a null-terminated string that identifies the type of data used to record the document.

**dwFlags**

Flags. Currently, it can be **NULL** or the following.

| Flag | Meaning |
|----------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| DI\_MEMORYMAP\_WRITE | Causes [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) to not use [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) and [**ScheduleJob**](https://learn.microsoft.com/windows/win32/printdocs/schedulejob) for local printing. |

## Remarks

The DI\_MEMORYMAP\_WRITE setting in **DOC\_INFO\_3** is an optimization. This allows GDI to map spool files in the application and speed up the recording.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DOC\_INFO\_3W** (Unicode) and **\_DOC\_INFO\_3A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob)

[**ScheduleJob**](https://learn.microsoft.com/windows/win32/printdocs/schedulejob)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

