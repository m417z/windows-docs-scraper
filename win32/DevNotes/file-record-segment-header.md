# FILE\_RECORD\_SEGMENT\_HEADER structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Represents the file record segment. This is the header for each file record segment in the master file table (MFT).

## Members

**MultiSectorHeader**

The multisector header defined by the cache manager. The [**MULTI\_SECTOR\_HEADER**](https://learn.microsoft.com/windows/win32/devnotes/multi-sector-header) structure always contains the signature "FILE" and a description of the location and size of the update sequence array.

**Reserved1**

Reserved.

**SequenceNumber**

The sequence number. This value is incremented each time that a file record segment is freed; it is 0 if the segment is not used. The **SequenceNumber** field of a file reference must match the contents of this field; if they do not match, the file reference is incorrect and probably obsolete.

**Reserved2**

Reserved.

**FirstAttributeOffset**

The offset of the first attribute record, in bytes.

**Flags**

The file flags.

**FILE\_RECORD\_SEGMENT\_IN\_USE** (0x0001)

**FILE\_FILE\_NAME\_INDEX\_PRESENT** (0x0002)

**Reserved3**

Reserved.

**BaseFileRecordSegment**

A file reference to the base file record segment for this file. If this is the base file record, the value is 0. See [**MFT\_SEGMENT\_REFERENCE**](https://learn.microsoft.com/windows/win32/devnotes/mft-segment-reference).

**Reserved4**

Reserved.

**UpdateSequenceArray**

The update sequence array to protect multisector transfers of the file record segment.

## Remarks

Note that there is no associated header file for this structure.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

