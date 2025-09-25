## Description

The **CSV_DOWN_LEVEL_FILE_TYPE** enum identifies the type of the down-level Cluster Shared Volumes file system (CSVFS) file object.

## Constants

### `CsvDownLevelFileObject`

The file object corresponds to the file being opened on top of CSVFS by a user.

### `CsvCsvFsInternalFileObject`

The file object is an internal one that CSVFS opens. It might be shared between multiple top-level opens from the same node.

## See also

[**CSV_DOWN_LEVEL_OPEN_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-csv_down_level_open_ecp_context)