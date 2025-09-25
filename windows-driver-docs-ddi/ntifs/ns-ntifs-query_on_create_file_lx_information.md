## Description

The **QUERY_ON_CREATE_FILE_LX_INFORMATION** structure is used to write a file's Linux metadata extended attributes when [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) is called with the **QoCFileLxInformation** flag set in the **InfoClassFlags** parameter.

## Members

### `EffectiveAccess`

The access rights of the file.

### `LxFlags`

The flags associated with FILE_STAT_LX_INFORMATION that specify which metadata fields are present in the file. Can be a bit mask of the following values:

| Flag | Value |
| ---- | ----- |
| LX_FILE_METADATA_HAS_UID (0x1) | The file has a user ID. |
| LX_FILE_METADATA_HAS_GID (0x2) | The file has a group ID. |
| LX_FILE_METADATA_HAS_MODE (0x4) | The file has mode information. |
| LX_FILE_METADATA_HAS_DEVICE_ID (0x8) | The file has a device ID. |
| LX_FILE_CASE_SENSITIVE_DIR (0x10) | The directory has case sensitivity information. |

### `LxUid`

The user ID of the file.

### `LxGid`

The group ID of the file.

### `LxMode`

The Linux file type and file system permissions. These values are defined in sys/stat.h in the Windows SDK. See [**FILE_STAT_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information) for more information.

### `LxDeviceIdMajor`

For device files (_S_IFCHR or S_IFBLK), specifies the device major number. For other file types, this field is not used.

### `LxDeviceIdMinor`

For device files (_S_IFCHR or S_IFBLK), specifies the device minor number. For other file types, this field is not used.

## Remarks

The file system allocates this structure and fills in the requested information, if supported, while it processes a file create. Filter Manager will free the allocated structure.

## See also

[**FILE_STAT_LX_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information)

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)