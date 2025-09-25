# LOOKUP_STREAM_FROM_CLUSTER_ENTRY structure

## Description

Returned from the
[FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster) control
code. Zero or more of these structures follow the
[LOOKUP_STREAM_FROM_CLUSTER_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-lookup_stream_from_cluster_output)
structure in the output buffer returned.

## Members

### `OffsetToNext`

Offset in bytes from the beginning of this structure to the next
**LOOKUP_STREAM_FROM_CLUSTER_ENTRY**
structure returned. If there are no more entries, this value is zero.

### `Flags`

Flags describing characteristics about this stream. The value will consist of one or more of these values.
At least one of the **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_*** values that fall
within the **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK** (0xff000000) will be set;
one or more of the other flag values may be set.

| Value | Meaning |
| --- | --- |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE**<br><br>0x00000001 | The stream is part of the system pagefile. |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET**<br><br>0x00000002 | The stream is locked from defragmentation. The **HandleInfo** member of the [MARK_HANDLE_INFO structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-mark_handle_info) for this stream has the **MARK_HANDLE_PROTECT_CLUSTERS** flag set. |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE**<br><br>0x00000004 | The stream is part of a file that is internal to the filesystem. |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE**<br><br>0x00000008 | The stream is part of a file that is internal to TxF. |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA**<br><br>0x01000000 | The stream is part of a $DATA attribute for the file (data stream). |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX**<br><br>0x02000000 | The stream is part of the $INDEX_ALLOCATION attribute for the file. |
| **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM**<br><br>0x03000000 | The stream is part of another attribute for the file. |

### `Reserved`

This value is reserved and is currently zero.

### `Cluster`

This is the cluster that this entry refers to. It will be one of the clusters passed in the input
structure.

### `FileName`

A **NULL**-terminated Unicode string containing the path of the object relative to
the root of the volume. This string will refer to the attribute or stream represented by the cluster. This
string is not limited by **MAX_PATH** and may be up to 32,768 characters (65,536 bytes) in
length. Not all of the filenames returned can be opened; some are internal to NTFS and always opened
exclusively. The string returned includes the full path including filename, stream name, and attribute type name
in the form
"*full*\*path*\*to*\*file*\*filename.ext*:*streamname*:*typename*".

## Remarks

The name in the **FileName** member can be very long and in a format not recognized by
a customer with the stream name and attribute type name following the filename. While it's appropriate to log the
entire filename for diagnostic purposes, if it is to be presented to an end-user it should be reformatted to be
more understandable (for example, remove the attribute type name and if the **Flags**
member has any flag other than **LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA** set then
an appropriate message should be displayed.

## See also

[FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster)

[LOOKUP_STREAM_FROM_CLUSTER_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-lookup_stream_from_cluster_output)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)