# WOF_VERSION_INFO structure

## Description

The **WOF_VERSION_INFO** structure contains the version corresponding to the driver supporting a given provider.

## Members

### `WofVersion`

The version of the WOF driver. This value includes the major and minor version numbers of the operating system in the high-order word, and the build number of the operating system in the low-order word. The major version can be extracted with HIBYTE(HIWORD(**WofVersion**)); the minor version can be extracted with LOBYTE(HIWORD(**WofVersion**)); the build number can be extracted with LOWORD(**WofVersion**).

## See also

[**FSCTL_GET_WOF_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-wof-version)

[**WOF_EXTERNAL_FILE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_file_id)

[**WOF_EXTERNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_info)