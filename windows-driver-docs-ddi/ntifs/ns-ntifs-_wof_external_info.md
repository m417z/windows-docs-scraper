# WOF_EXTERNAL_INFO structure

## Description

The **WOF_EXTERNAL_INFO** structure identifies a file backing provider and the overlay service version it supports.

## Members

### `Version`

The overlay service version. Set to WOF_CURRENT_VERSION.

### `Provider`

The identifier of the data source provider. Valid provider identifiers are WOF_PROVIDER_WIM for the Windows Image Format (WIM) provider, and WOF_PROVIDER_FILE for the individual compressed file provider. WOF_PROVIDER_WIM is available starting with Windows 8.1 Update, WOF_PROVIDER_FILE is available starting with Windows 10.

## See also

[**WOF_EXTERNAL_FILE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_external_file_id)

[**WOF_VERSION_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_wof_version_info)