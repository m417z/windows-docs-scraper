## Description

The **STARTING_VCN_INPUT_BUFFER** structure contains the starting virtual cluster number (VCN) for the [**FSCTL_GET_RETRIEVAL_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_retrieval_pointers) control code.

## Members

### `StartingVcn`

The VCN at which the operation will begin enumerating extents in the file. This value may be rounded down to the first VCN of the extent in which the specified extent is found.

## See also

[**FSCTL_GET_RETRIEVAL_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_retrieval_pointers)