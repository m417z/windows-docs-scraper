# FltRequestFileInfoOnCreateCompletion function

## Description

A minifilter calls **FltRequestFileInfoOnCreateCompletion** during file pre-create to request that the file system stores file information for retrieval during post create.

## Parameters

### `Filter`

Opaque filter pointer that uniquely identifies the minifilter driver.

### `Data`

Pointer to the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data representing the I/O create operation.

### `InfoClassFlags`

Flag bitmask indicating the type of file information that the file system should store for retrieval during post create. Can be any combination of the following flags:

| Flag | Meaning |
| ---- | ------- |
| **QoCFileStatInformation** (0x00000001) | If set, the file system will store file stat information in a [**QUERY_ON_CREATE_FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_stat_information) structure for retrieval. |
| **QoCFileLxInformation** (0x00000002) | If set, the file system will store extended Linux-like information in a [**QUERY_ON_CREATE_FILE_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_lx_information) structure for retrieval. |
| **QoCFileEaInformation** (0x00000004) | If set, the file system will store extended attributes (EA) in a [**QUERY_ON_CREATE_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_ea_information) structure for retrieval. |
| **QoCFileUsnInformation** (0x00000008) | If set, the file system will store USN information in a [**QUERY_ON_CREATE_USN_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_usn_information) structure for retrieval. |

## Return value

**FltRequestFileInfoOnCreateCompletion** can return one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | The file system successfully stored the requested file information. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltRequestFileInfoOnCreateCompletion** was unable to allocate sufficient memory in which to store the requested file information. |
| **STATUS_INVALID_PARAMETER_2** | The provided callback data object was not an IRP-based create operation. |

## Remarks

The minifilter can retrieve the file information by calling [**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex) or [**FltRetrieveFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletion) during post create. A minifilter's performance is typically better when it requests and retrieves file information in this manner, rather than querying file information at a later time.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltRetrieveFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)