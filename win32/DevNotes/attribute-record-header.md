# ATTRIBUTE\_RECORD\_HEADER structure

\[This structure is valid only for version 3 of NTFS volumes; it may be altered in future versions.\]

Represents an attribute record.

## Members

**TypeCode**

The attribute type code.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **$STANDARD\_INFORMATION**<br>0x10 | File attributes (such as read-only and archive), time stamps (such as file creation and last modified), and the hard link count.<br> |
| **$ATTRIBUTE\_LIST**<br>0x20 | A list of attributes that make up the file and the file reference of the MFT file record in which each attribute is located.<br> |
| **$FILE\_NAME**<br>0x30 | The name of the file, in Unicode characters.<br> |
| **$OBJECT\_ID**<br>0x40 | A 64-byte object identifier assigned by the link-tracking service.<br> |
| **$VOLUME\_NAME**<br>0x60 | The volume label. Present in the $Volume file.<br> |
| **$VOLUME\_INFORMATION**<br>0x70 | The volume information. Present in the $Volume file.<br> |
| **$DATA**<br>0x80 | The contents of the file.<br> |
| **$INDEX\_ROOT**<br>0x90 | Used to implement filename allocation for large directories.<br> |
| **$INDEX\_ALLOCATION**<br>0xA0 | Used to implement filename allocation for large directories.<br> |
| **$BITMAP**<br>0xB0 | A bitmap index for a large directory.<br> |
| **$REPARSE\_POINT**<br>0xC0 | The reparse point data.<br> |

**RecordLength**

The size of the attribute record, in bytes. This value reflects the required size for the record variant and is always rounded to the nearest quadword boundary.

**FormCode**

The attribute form code.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **RESIDENT\_FORM**<br>0x00 | The value is contained in the file record and immediately follows the attribute record header.<br> |
| **NONRESIDENT\_FORM**<br>0x01 | The value is contained in other sectors on the disk.<br> |

**NameLength**

The size of the optional attribute name, in characters, or 0 if there is no attribute name. The maximum attribute name length is 255 characters.

**NameOffset**

The offset of the attribute name from the start of the attribute record, in bytes. If the **NameLength** member is 0, this member is undefined.

**Flags**

The attribute flags.

**ATTRIBUTE\_FLAG\_COMPRESSION\_MASK** (0x00FF)

**ATTRIBUTE\_FLAG\_SPARSE** (0x8000)

**ATTRIBUTE\_FLAG\_ENCRYPTED** (0x4000)

**Instance**

The unique instance for this attribute in the file record.

**Form**

If the **FormCode** member is RESIDENT\_FORM, the union is a **Resident** structure. If **FormCode** is NONRESIDENT\_FORM, the union is a **Nonresident** structure.

**Resident**

**ValueLength**

The size of the attribute value, in bytes.

**ValueOffset**

The offset to the value from the start of the attribute record, in bytes.

**Reserved**

Reserved.

**Nonresident**

**LowestVcn**

The lowest virtual cluster number (VCN) covered by this attribute record.

**HighestVcn**

The highest VCN covered by this attribute record.

**MappingPairsOffset**

The offset to the mapping pairs array from the start of the attribute record, in bytes. For more information, see Remarks.

**Reserved**

Reserved.

**AllocatedLength**

The allocated size of the file, in bytes. This value is an even multiple of the cluster size. This member is not valid if the **LowestVcn** member is nonzero.

**FileSize**

The file size (highest byte that can be read plus 1), in bytes. This member is not valid if **LowestVcn** is nonzero.

**ValidDataLength**

The valid data length (highest initialized byte plus 1), in bytes. This value is rounded to the nearest cluster boundary. This member is not valid if **LowestVcn** is nonzero.

**TotalAllocated**

The total allocated for the file (the sum of the allocated clusters).

## Remarks

Note that there is no associated header file for this structure.

This structure definition is valid only for major version 3 and minor version 0 or 1, as reported by [**FSCTL\_GET\_NTFS\_VOLUME\_DATA**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data).

Attribute records are always aligned on a quadword boundary.

If the attribute is nonresident, the attribute record header contains a list of retrieval information that provides a mapping between VCN and logical cluster number (LCN) for the attribute. If the retrieval information does not fit in the base file segment, it can be stored in an external file record segment by itself. If it still does not fit into one external file record segment, there is a provision in the attribute list to contain multiple entries for an attribute that requires additional retrieval information.

The mapping pairs array is stored in a compressed form and assumes that the information is decompressed and cached by the system. It consists of a series of NextVcn/CurrentLcn pairs. For example, if a file has a single run of 8 clusters starting at LCN 128 and the file starts at LowestVcn 0, then the mapping pairs array has just one entry, which is NextVcn=8 and CurrentLcn=128. The array is a byte stream that stores the changes to the working variables when processed sequentially. The byte stream is to be interpreted as a zero-terminated stream of triples, as follows:

count byte = *v* + (*l* \* 16)

where *v* is the number of changed low-order VCN bytes and *l* is the number of changed low-order LCN bytes.

The decompression algorithm is as follows:

1. Initialize NextVcn to `Attribute->LowestVcn` and CurrentLcn to 0.
2. Initialize the byte stream pointer to `(PCHAR)Attribute + Attribute->AttributeForm->Nonresident->MappingPairsOffset`.
3. Set CurrentVcn to NextVcn.
4. Read the next byte from the stream. If it is 0, then break; else extract *v* and *l* as previously described.
5. Interpret the next *v* bytes as a signed quantity, with the low-order byte first. Unpack it sign-extended into 64 bits and add it to NextVcn.
6. Interpret the next *l* bytes as a signed quantity, with the low-order byte first. Unpack it sign-extended into 64 bits and add it to CurrentLcn. If this produces a CurrentLcn of 0, then the VCNs from CurrentVcn to NextVcn–1 are unallocated.
7. Update the cached mapping information from CurrentVcn, NextVcn, and CurrentLcn.
8. Go to step 3.

## See also

[Master File Table](https://learn.microsoft.com/windows/win32/devnotes/master-file-table)

