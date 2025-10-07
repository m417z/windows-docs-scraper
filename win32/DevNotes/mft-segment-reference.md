# MFT\_SEGMENT\_REFERENCE structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Represents an address in the master file table (MFT). The address is tagged with a circularly reused sequence number that is set at the time the MFT segment reference was valid.

## Members

**SegmentNumberLowPart**

The low part of the segment number.

**SegmentNumberHighPart**

The high part of the segment number.

**SequenceNumber**

The nonzero sequence number. The value 0 is reserved.

## Remarks

Note that there is no associated header file for this structure.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

The **FILE\_REFERENCE** data type is defined as follows.

``` syntax
typedef MFT_SEGMENT_REFERENCE FILE_REFERENCE, *PFILE_REFERENCE;
```

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

