# LONG_SECTION structure

## Description

The **LONG_SECTION** structure represents a long MPEG-2 section header. If a section contains a long header, you can cast a [SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section) pointer to a **LONG_SECTION** pointer. For more information, see the Remarks section in the **SECTION** reference.

## Members

### `TableId`

Specifies the table identifier (TID) of the section.

### `Header`

A union that contains the following members.

### `Header.S`

Contains packed header bits, as an **MPEG_HEADER_BITS_MIDL** structure. Applications should use the **Header.W** field instead.

### `Header.W`

Contains the header bits as a **WORD** type. To get the individual bitfields, coerce this member to an [MPEG_HEADER_BITS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2bits/ns-mpeg2bits-mpeg_header_bits) structure.

### `TableIdExtension`

Specifies the table_id_extension field.

### `Version`

A union that contains the following members.

### `Version.S`

Contains the version number and current/next indicator bit as an **MPEG_HEADER_VERSION_BITS_MIDL** structure. Applications should use the **Version.B** field instead.

### `Version.B`

Contains the version number and current/next indicator bit as a **BYTE** type. To get the individual bit fields, coerce this member to an [MPEG_HEADER_VERSION_BITS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2bits/ns-mpeg2bits-mpeg_header_version_bits) structure.

### `SectionNumber`

Specifies the section_number field, which gives the section number for this section.

### `LastSectionNumber`

Specifies the last_section_number field, which gives the last (highest) section number for the table.

### `RemainingData`

Contains the remaining section data, as a byte array. The length of the array is `Header.W.SectionLength - 5` bytes.

## Remarks

The following code shows how to access the bit fields within the **Version** member:

```cpp

LONG_SECTION *pSection; // Points to the section data.

// Coerce the Version field to an MPEG_HEADER_VERSION_BITS type.
MPEG_HEADER_VERSION_BITS *pVersion;
pVersion = (MPEG_HEADER_VERSION_BITS*)&pSection->Version.B;

// Now use the pHeader pointer to access the bit fields.
BYTE VersionNumber = pSection->VersionNumber;

```

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)