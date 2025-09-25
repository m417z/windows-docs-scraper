# FltRetrieveFileInfoOnCreateCompletion function

## Description

**FltRetrieveFileInfoOnCreateCompletion** retrieves the requested file information during file post create. Use [FltRetrieveFileInfoOnCreateCompletionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex) to get an NTSTATUS code along with the requested information.

## Parameters

### `Filter` [in]

Opaque filter pointer that uniquely identifies the minifilter driver.

### `Data` [in]

Pointer to the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data representing the I/O operation.

### `InfoClass` [in]

Flag that indicates the type of information to return. Note that flags cannot be combined. Can be one of the following values:

| Flag | Meaning |
| ---- | ------- |
| **QoCFileStatInformation** (0x00000001) | The file system will return file stat information in a [**QUERY_ON_CREATE_FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_stat_information) structure. |
| **QoCFileLxInformation** (0x00000002) | The file system will return extended Linux-like information in a [**QUERY_ON_CREATE_FILE_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_lx_information) structure. |
| **QoCFileEaInformation** (0x00000004) | The file system will return extended attributes (EA) in a [**QUERY_ON_CREATE_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_ea_information) structure. |
| **QoCFileUsnInformation** (0x00000008) | The file system will return USN information in a [**QUERY_ON_CREATE_USN_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_usn_information) structure. |
| **QoCFileSecurityInformation** (0x00000010) | The file system will return file security information in a [**QUERY_ON_CREATE_SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_security_information) structure. |

### `Size` [out]

Pointer to a ULONG that specifies the size, in bytes, of the buffer that this function returns.

## Return value

**FltRetrieveFileInfoOnCreateCompletion** returns a pointer to a buffer with the requested file information. The structure within the buffer is determined by the value of *InfoClass*. If the file system processes the request but can't find the requested file information, this parameter is set to NULL.

## Remarks

A minifilter must call **FltRequestFileInfoOnCreateCompletion** during file pre-create to specify which file information the file system should track.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltRequestFileInfoOnCreateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[FltRetrieveFileInfoOnCreateCompletionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)