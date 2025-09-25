# ClfsQueryLogFileInformation function

## Description

The **ClfsQueryLogFileInformation** routine returns metadata and state information for a specified CLFS stream or its underlying physical log or both.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `eInformationClass` [in]

A value from the [CLFS_LOG_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_cls_log_information_class) enumeration that specifies the type of information being requested.

### `pinfoInputBuffer`

Optional input buffer which is required for some information classes.

### `cbinfoInputBuffer`

Length in bytes of pinfoInputBuffer.

### `pinfoBuffer` [out]

A pointer to a buffer that receives the log information. The structure of this buffer depends on the value of *eInformationClass*. The following table shows the relationship between the information class and the data type of the buffer.

| Value of *eInformationClass* | Type of buffer pointed to by *pinfoBuffer* |
| --- | --- |
| **ClfsLogBasicInformation** | [CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information) |
| **ClfsLogBasicInformationPhysical** | [CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information) |
| **ClfsLogNameInformation** | [CLFS_LOG_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_log_name_information) |
| **ClfsLogPhysicalNameInformation** | [CLFS_LOG_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_log_name_information) |
| **ClfsLogStreamIdentifierInformation** | [CLFS_STREAM_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_stream_id_information) |

### `pcbInfoBuffer`

Length in bytes of the incoming information buffer.

## Return value

**ClfsQueryLogFileInformation** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsSetLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetlogfileinformation)