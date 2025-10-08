# ATTRIBUTE\_LIST\_ENTRY structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Represents an entry in the attribute list.

## Members

**AttributeTypeCode**

The attribute type code.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **$STANDARD\_INFORMATION**<br>0x10 | File attributes (such as read-only and archive), time stamps (such as file creation and last modified), and the hard link count.<br> |
| **$ATTRIBUTE\_LIST**<br>0x20 | A list of attributes that make up the file and the file reference of the MFT file record in which each attribute is located.<br> |
| **$FILE\_NAME**<br>0x30 | The name of the file, in Unicode characters.<br> |
| **$OBJECT\_ID**<br>0x40 | An 16-byte object identifier assigned by the link-tracking service.<br> |
| **$VOLUME\_NAME**<br>0x60 | The volume label. Present in the $Volume file.<br> |
| **$VOLUME\_INFORMATION**<br>0x70 | The volume information. Present in the $Volume file.<br> |
| **$DATA**<br>0x80 | The contents of the file.<br> |
| **$INDEX\_ROOT**<br>0x90 | Used to implement filename allocation for large directories.<br> |
| **$INDEX\_ALLOCATION**<br>0xA0 | Used to implement filename allocation for large directories.<br> |
| **$BITMAP**<br>0xB0 | A bitmap index for a large directory.<br> |
| **$REPARSE\_POINT**<br>0xC0 | The reparse point data.<br> |

**RecordLength**

The size of this structure, plus the optional name buffer, in bytes.

**AttributeNameLength**

The size of the optional attribute name, in characters. If a name exists, this value is nonzero and the structure is followed immediately by a Unicode string of the specified number of characters.

**AttributeNameOffset**

Reserved.

**LowestVcn**

The lowest virtual cluster number (VCN) for this attribute. This member is zero unless the attribute requires multiple file record segments and unless this entry is a reference to a segment other than the first one. In this case, this value is the lowest VCN that is described by the referenced segment.

**SegmentReference**

The master file table (MFT) segment in which the attribute resides. See [**MFT\_SEGMENT\_REFERENCE**](https://learn.microsoft.com/windows/win32/devnotes/mft-segment-reference).

**Reserved**

Reserved.

**AttributeName**

The start of the optional attribute name.

## Remarks

The attributes list is an ordered list of quadword-aligned **ATTRIBUTE\_LIST\_ENTRY** structures. This list is ordered first by the attribute type code and then by the attribute name (if present). No two attributes can have the same type code, name, and lowest VCN. Therefore, there can be at most one attribute for each type code without a name.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

Note that there is no associated header file for this structure.

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

