## Description

**SHUFFLE_FILE_DATA** is the input structure for the [**FSCTL_SHUFFLE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_shuffle_file) control code.

## Members

### `StartingOffset`

Cluster-aligned byte offset of the base of the contiguous region from which to add or remove data in the file passed with the FS control code.

### `Length`

Cluster-aligned length in bytes of the data to be added or removed. **Length** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| Greater than 0 | Add the allocation to the file. |
| Less than 0 | Remove the allocation from the file. |
| 0 | Do nothing. |

### `Flags`

Bitwise OR of flags for the shuffle operation. **Flags** be the following value.

| Value | Meaning |
| ----- | ------- |
| SHUFFLE_FILE_FLAG_SKIP_INITIALIZING_NEW_CLUSTERS (0x001) | Valid only when adding allocation. When set, free clusters are allocated and added but have arbitrary initial contents (they are not zero-initialized). |

## See also

[**FSCTL_SHUFFLE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_shuffle_file)