# _QUERY_FILE_LAYOUT_OUTPUT structure

## Description

The **QUERY_FILE_LAYOUT_OUTPUT** structure serves as a header for the file layout entries that are returned from a [FSCTL_QUERY_FILE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-query-file-layout) request.

## Members

### `FileEntryCount`

The number of file entries that follow this structure.

### `FirstFileOffset`

The offset in the user buffer for the first file entry.

### `Flags`

Indicates the format of layout entries returned. Can be 0 or the following:

| Value | Meaning |
| --- | --- |
| **QUERY_FILE_LAYOUT_SINGLE_INSTANCED** | Single instances of stream and file layout entries are returned. When set, only one **STREAM_LAYOUT_ENTRY** structure is returned per stream and only one **FILE_LAYOUT_ENTRY** structure is returned per file. This flag is always set for NTFS. |

### `Reserved`

Reserved.

## Remarks

The file layout entries that follow the **QUERY_FILE_LAYOUT_OUTPUT** structure are determined by the flags set in the **Flags** member of [QUERY_FILE_LAYOUT_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_query_file_layout_input) provided as input to the [FSCTL_QUERY_FILE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-query-file-layout) request. A number of **FILE_LAYOUT_ENTRY** structures follow **QUERY_FILE_LAYOUT_OUTPUT**. Depending on the entries selected to return from a query, offsets in **FILE_LAYOUT_ENTRY** indicate where the additional informational entries are located in the user buffer.

The following entry structures are returned when their corresponding inclusion flag is set in the **Flags** member of [QUERY_FILE_LAYOUT_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_query_file_layout_input).

| Entry | Inclusion flag |
| --- | --- |
| **FILE_LAYOUT_NAME_ENTRY** | **QUERY_FILE_LAYOUT_INCLUDE_NAMES** |
| **FILE_LAYOUT_INFO_ENTRY** | **QUERY_FILE_LAYOUT_INCLUDE_EXTRA_INFO** |
| **STREAM_LAYOUT_ENTRY** | **QUERY_FILE_LAYOUT_INCLUDE_STREAMS** |
| **STREAM_EXTENT_ENTRY** | **QUERY_FILE_LAYOUT_INCLUDE_EXTENTS** |

When multiple entries of the same type exist for a single **FILE_LAYOUT_ENTRY** structure, each informational entry structure has an offset member that indicates the location of the next entry. The chain of entry structures continues until the value of the offset member is 0.

## See also

[FSCTL_QUERY_FILE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-query-file-layout)

[QUERY_FILE_LAYOUT_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_query_file_layout_input)