## Description

The **MOVE_FILE_DATA** structure contains input data for the [**FSCTL_MOVE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_move_file) control code.

## Members

### `FileHandle`

Handle to the file to be moved.

### `StartingVcn`

A VCN (cluster number relative to the beginning of a file) of the first cluster to be moved.

### `StartingLcn`

An LCN (cluster number on a volume) to which the VCN is to be moved.

### `ClusterCount`

The count of clusters to be moved.

## See also

[**FSCTL_MOVE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_move_file)