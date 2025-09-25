## Description

Identifies the type of file information that [GetFileInformationByName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getfileinformationbyname) should retrieve.

## Constants

### `FileStatByNameInfo`

Minimal stat info should be queried. See [FILE_STAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information).

### `FileStatLxByNameInfo`

Additional (Linux-oriented) stat info should be queried. See [FILE_STAT_LX_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information).

### `FileCaseSensitiveByNameInfo`

Info about case-sensitivity should be queried. See [FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information).

### `FileStatBasicByNameInfo`

Extended stat info should be queried. See [FILE_STAT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_stat_basic_information).

### `MaximumFileInfoByNameClass`

This value is used for validation. Supported values are less than this value.

## Remarks

## See also

- [GetFileInformationByName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getfileinformationbyname)
- [FILE_STAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information)
- [FILE_STAT_LX_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_lx_information)
- [FILE_CASE_SENSITIVE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_case_sensitive_information)
- [FILE_STAT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_stat_basic_information)