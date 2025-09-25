# CSV_CONTROL_OP enumeration

## Description

Specifies the type of CSV control operation to use with the [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_csv_control) control code.

## Constants

### `CsvControlStartRedirectFile:0x02`

Start file redirection.

### `CsvControlStopRedirectFile:0x03`

Stop file redirection.

### `CsvControlQueryRedirectState:0x04`

Search for state redirection. When this value is specified, the [CSV_QUERY_REDIRECT_STATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_redirect_state) structure must also be used.

### `CsvControlQueryFileRevision:0x06`

Search for file revision. When this value is specified, the [CSV_QUERY_FILE_REVISION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_file_revision) structure must also be used.

### `CsvControlQueryMdsPath:0x08`

### `CsvControlQueryFileRevisionFileId128:0x09`

### `CsvControlQueryVolumeRedirectState:0x0a`

### `CsvControlEnableUSNRangeModificationTracking:0x0d`

### `CsvControlMarkHandleLocalVolumeMount:0x0e`

### `CsvControlUnmarkHandleLocalVolumeMount:0x0f`

### `CsvControlGetCsvFsMdsPathV2:0x12`

### `CsvControlDisableCaching:0x13`

### `CsvControlEnableCaching:0x14`

#### - CsvControlMdsPath

Search for MDS path. When this value is specified, the [CSV_QUERY_MDS_PATH](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_mds_path) structure must also be used.

## Remarks

An alternative to calling the [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_csv_control) control code with this enumeration is to use the [CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_control_param) structure, which encapsulates a member of this enumeration type.

## See also

* [CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_control_param)
* [CSV_QUERY_FILE_REVISION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_file_revision)
* [CSV_QUERY_MDS_PATH](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_mds_path)
* [CSV_QUERY_REDIRECT_STATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_redirect_state)
* [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_csv_control)
* [File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)