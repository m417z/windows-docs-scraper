# EPrintXPSJobProgress enumeration

Specifies what the spooler is currently doing as it processes an XPS print job.

## Constants

**kAddingDocumentSequence**

A document sequence is about to be added to the XPS job.

**kDocumentSequenceAdded**

A document sequence has been added to the XPS job.

**kAddingFixedDocument**

A fixed document is about to be added to the XPS job.

**kFixedDocumentAdded**

A fixed document has been added to the XPS job.

**kAddingFixedPage**

A page is about to be added to the XPS job.

**kFixedPageAdded**

A page has been added to the XPS job.

**kResourceAdded**

A resource had been added to the XPS job.

**kFontAdded**

A font has been added to the XPS job.

**kImageAdded**

An image has been added to the XPS job.

**kXpsDocumentCommitted**

The data for the XPS job has been committed.

## Remarks

This enumeration is primarily used as a parameter for the [**ReportJobProcessingProgress**](https://learn.microsoft.com/windows/win32/printdocs/reportjobprocessingprogress) function.

These values can refer to either the spooling or the rendering phase of a print job.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

