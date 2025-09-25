# _FS_FILTER_SECTION_SYNC_OUTPUT structure

## Description

The **FS_FILTER_SECTION_SYNC_OUTPUT** structure contains information describing the attributes of the section that is being created.

## Members

### `StructureSize`

The size of the structure.

### `SizeReturned`

The size of the structure which has been successfully populated with information on completion.

### `Flags`

Specifies the support for synchronization. The following values can be used:

| Name | Value |
| -- | -- |
| FS_FILTER_SECTION_SYNC_SUPPORTS_ASYNC_PARALLEL_IO | 0x00000001 |
| FS_FILTER_SECTION_SYNC_SUPPORTS_DIRECT_MAP_DATA | 0x00000002 |
| FS_FILTER_SECTION_SYNC_SUPPORTS_DIRECT_MAP_IMAGE | 0x00000004 |

### `DesiredReadAlignment`

Specifies the optimal size for efficient reads. Faults from the section will attempt, but not guarantee, to read in multiples of this size. This value should be a multiple of PAGE_SIZE.