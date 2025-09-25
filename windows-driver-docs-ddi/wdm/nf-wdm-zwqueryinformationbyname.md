## Description

**ZwQueryInformationByName** returns the requested information about a file specified by file name.

## Parameters

### `ObjectAttributes` [in]

Pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that contains the file's attributes, including file name.

### `IoStatusBlock` [out]

Pointer an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure containing the caller's I/O status.

### `FileInformation` [out]

Pointer to the caller-supplied buffer in which to return the requested information about the file. The structure of the buffer is determined by the *FileInformationClass* parameter.

### `Length` [in]

Length, in bytes, of the buffer that *FileInformation* points to.

### `FileInformationClass` [in]

A [FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) value that identifies the type of file information to return in the buffer that *FileInformation* points to. *FileInformationClass* can be one of the following values.

| FILE_INFORMATION_CLASS Value | Type of Information to Return |
| ---------------------------- | ----------------------------- |
| **FileStatInformation** (68) | [FILE_STAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information). Available starting with Windows 10, version 1709. |
| **FileStatLxInformation** (70) | [FILE_STAT_LX_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information). Available starting with Windows 10 April 2018 Update. |
| **FileCaseSensitiveInformation** (71) | [FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information). Available starting with Windows 10 April 2018 Update. |

## Return value

**ZwQueryInformationByName** returns STATUS_SUCCESS upon successful completion; otherwise it returns an error code, such as one of the following.

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_INVALID_PARAMETER | The *FileInformationClass* parameter contains an invalid value. |
| STATUS_INFO_LENGTH_MISMATCH | The buffer size specified by *Length* is not large enough to contain the requested information. |

## Remarks

**ZwQueryInformationByName** queries and returns the requested information about the file. It does so without opening the actual file, making it more efficient than [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryinformationfile), which requires a file open (and subsequent file close).

Callers of **ZwQueryInformationByName** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information)

[FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[FILE_STAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information)

[FILE_STAT_LX_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information)

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryinformationfile)