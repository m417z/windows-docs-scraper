## Description

The **QUERY_ON_CREATE_USN_INFORMATION** structure is used to write file information when [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) is called with the **QoCFileUsnInformation** flag set in the **InfoClassFlags** parameter.

## Members

### `Usn`

The USN (Update Sequence Number) for this file or directory.

### `FileReferenceNumber`

The 128-bit file ID (aka ordinal number) of the file or directory.

## Remarks

The system allocates this structure and the file system fills in the requested information, if supported, while it processes a file create. Filter Manager will eventually free the allocated structure.

## See also

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)