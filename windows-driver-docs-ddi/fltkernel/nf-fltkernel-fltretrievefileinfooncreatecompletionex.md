# FltRetrieveFileInfoOnCreateCompletionEx function

## Description

**FltRetrieveFileInfoOnCreateCompletionEx** queries for the specified file information upon file creation completion.

## Parameters

### `Filter` [in]

Opaque filter pointer that uniquely identifies the minifilter driver. It is returned by [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter), and remains constant as long as the minifilter driver is loaded.

### `Data` [in]

Pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data representing the I/O operation.

### `InfoClass` [in]

Flag that indicates the type of file information to return. Note that flags cannot be combined. Can be one of the following values:

| Flag | Meaning |
| ---- | ------- |
| **QoCFileStatInformation** (0x00000001) | The file system will return file stat information in a [**QUERY_ON_CREATE_FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_stat_information) structure. |
| **QoCFileLxInformation** (0x00000002) | The file system will return extended Linux-like information in a [**QUERY_ON_CREATE_FILE_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_lx_information) structure. |
| **QoCFileEaInformation** (0x00000004) | The file system will return extended attributes (EA) in a [**QUERY_ON_CREATE_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_ea_information) structure. |
| **QoCFileUsnInformation** (0x00000008) | The file system will return USN information in a [**QUERY_ON_CREATE_USN_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_usn_information) structure. |
| **QoCFileSecurityInformation** (0x00000010) | The file system will return file security information in a [**QUERY_ON_CREATE_SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_security_information) structure. |

### `RetInfoSize` [out]

Pointer to a ULONG that receives the size, in bytes, of the buffer that **RetInfoBuffer** points to.

### `RetInfoBuffer` [out]

Receives a pointer to the requested **InfoClass** structure. If the file system is able to process the request but can't find the requested file information, this parameter is set to NULL.

## Return value

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | The file system successfully returned the requested file information. |
| **STATUS_NOT_FOUND** | The file system processed the request, but the requested information was not present on the file, or the file system does not recognize the information request in *InfoClass*. The caller should not use traditional file system APIs to request the information. |
| **STATUS_NOT_SUPPORTED** | The file system was unable to retrieve the requested information. This error occurs when the file system doesn't support the information request or associated ECP, or because [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) wasn't called during file pre-creation. The caller should instead use traditional file system APIs to retry requesting the information. |
| **STATUS_UNSUCCESSFUL** | The file system received an error while trying to retrieve the requested information. The caller can try requesting the information by way of normal file system APIs, but that will likely fail. |

## Remarks

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) and **FltRetrieveFileInfoOnCreateCompletionEx** allow a minifilter to get information about a file during file create, thus avoiding the performance cost of a later query that would require a stack traversal.

- In pre-create, the minifilter makes one call to [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) with a combination of input **InfoClassFlags** that identify the requested information.
- The file system allocates the appropriate structure(s) and fills in the requested information, if supported, while it processes the create.
- In post-create, the minifilter calls **FltRetrieveFileInfoOnCreateCompletionEx** to get the information it requested in the pre-create call. If the minifilter requested more than one info type, it must call **FltRetrieveFileInfoOnCreateCompletionEx** once for each info type. For example:

``` c

// Pre-create:
NTSTATUS status;
status = FltRequestFileInfoOnCreateCompletion( Filter,
                                               CallbackData,
                                               QoCFileStatInformation
                                                | QoCFileLxInformation
                                                | QoCFileEaInformation
                                                | QoCFileUsnInformation );

// Post-create:
NTSTATUS status;
ULONG fileStatSize, fileLxSize, fileEaSize;
QUERY_ON_CREATE_FILE_STAT_INFORMATION* fileStatInfo;
QUERY_ON_CREATE_FILE_LX_INFORMATION* fileLxInfo;
QUERY_ON_CREATE_EA_INFORMATION* fileEaInfo;
QUERY_ON_CREATE_USN_INFORMATION* fileUsnInfo;
QUERY_ON_CREATE_SECURITY_INFORMATION* fileSecurityInfo;

status = FltRetrieveFileInfoOnCreateCompletionEx( Filter,
                                                  CallbackData,
                                                  QoCFileStatInformation,
                                                  &fileStatSize,
                                                  &fileStatInfo );
status = FltRetrieveFileInfoOnCreateCompletionEx( Filter,
                                                  CallbackData,
                                                  QoCFileLxInformation,
                                                  &fileLxSize,
                                                  &fileLxInfo );
status = FltRetrieveFileInfoOnCreateCompletionEx( Filter,
                                                  CallbackData,
                                                  QoCFileEaInformation,
                                                  &fileEaSize,
                                                  &fileEaInfo );
status = FltRetrieveFileInfoOnCreateCompletionEx( Filter,
                                                  CallbackData,
                                                  QoCFileUsnInformation,
                                                  &fileUsnInfo,
                                                  &fileUsnInfo );
status = FltRetrieveFileInfoOnCreateCompletionEx( Filter,
                                                  CallbackData,
                                                  QoCFileSecurityInformation,
                                                  &fileSecurityInfo,
                                                  &fileSecurityInfo);
```

Once **FltRetrieveFileInfoOnCreateCompletionEx** returns, a minifilter can write into the buffer that **RetInfoBuffer** points to. Any filters above that minifilter will see the changes if they call **FltRetrieveFileInfoOnCreateCompletionEx** on the modified information type.

## See also

[**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**QUERY_ON_CREATE_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_ea_information)

[**QUERY_ON_CREATE_FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_stat_information)

[**QUERY_ON_CREATE_FILE_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_on_create_file_lx_information)