# ClfsSetLogFileInformation function

## Description

The **ClfsSetLogFileInformation** routine sets metadata and state information for a specified stream and its underlying physical log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `eInformationClass` [in]

A [CLFS_LOG_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_cls_log_information_class) value that specifies the class of information being set.

### `pinfoBuffer` [in]

A pointer to a buffer that supplies the log information. The structure of this buffer varies according to the class of information specified by *eInformationClass*. The following table shows the relationship between the information class and the buffer type.

| Value of eInformationClass | Type of buffer pointed to by *pinfoBuffer* |
| --- | --- |
| **ClfsLogBasicInformation** | [CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information) |
| **ClfsLogBasicInformationPhysical** | [CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information) |
| **ClfsLogNameInformation** | [CLFS_LOG_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_log_name_information) |
| **ClfsLogPhysicalNameInformation** | [CLFS_LOG_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_log_name_information) |
| **ClfsLogStreamIdentifierInformation** | [CLFS_STREAM_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_stream_id_information) |

### `cbBuffer` [in]

The size, in bytes, of the buffer pointed to by *pinfoBuffer*.

## Return value

**ClfsSetLogFileInformation** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information)

[CLFS_LOG_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_cls_log_information_class)

[CLFS_STREAM_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_stream_id_information)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)