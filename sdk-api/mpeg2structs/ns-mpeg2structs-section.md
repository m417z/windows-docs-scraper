# SECTION structure

## Description

The **SECTION** structure represents a short header from an MPEG-2 table section.

## Members

### `TableId`

Specifies the table identifier (TID) of the section.

### `Header`

A union that contains the following members.

### `Header.S`

Contains header bits, as an **MPEG_HEADER_BITS_MIDL** structure. Applications should use the **Header.W** field instead.

### `Header.W`

Contains the header bits as a **WORD** type. To get the individual bit fields, coerce this member to an [MPEG_HEADER_BITS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2bits/ns-mpeg2bits-mpeg_header_bits) structure.

### `SectionData`

Contains the section data, as a byte array. The length of the array is given by the **Header.W.SectionLength** field.

## Remarks

This structure represents an MPEG-2 short header. The section might contain a long header or DSM-CC header, each of which extends the short header:

* If the **Header.W.SectionSyntaxIndicator** bit is set, the section uses the long syntax. In that case, you can cast a **SECTION** pointer to a [LONG_SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-long_section) pointer.
* If the TID indicates a DSM-CC user-to-network message (0x3B) or a download data message (0x3C), the section uses the DSM-CC header syntax. In that case, you can cast a **SECTION** pointer to a [DSMCC_SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-dsmcc_section) pointer.

The following code shows how to access the bit fields within the **Header** member:

```cpp

SECTION *pSection; // Points to the section data.

// Coerce the Header field to an MPEG_HEADER_BITS type.
MPEG_HEADER_BITS *pHeader = (MPEG_HEADER_BITS*)&pSection->Header.W;

// Now use the pHeader pointer to access the bit fields.
WORD SectionLength = pHeader->SectionLength;

```

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)