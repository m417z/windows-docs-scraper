## Description

The **QUERY_ON_CREATE_EA_INFORMATION** structure is used to write file information when [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) is called with the **QoCFileEaInformation** flag set in the **InfoClassFlags** parameter.

## Members

### `EaBufferSize`

Size, in bytes, of the buffer that **EaBuffer** points to.

### `EaBuffer`

A list of [**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information) structures with extended attribute (EA) information.

## Remarks

The file system allocates this structure and fills in the requested information, if supported, while it processes a file create. Filter Manager will free the allocated structure.

## See also

[**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)