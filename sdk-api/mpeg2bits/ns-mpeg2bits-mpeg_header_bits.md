# MPEG_HEADER_BITS structure

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **MPEG_HEADER_BITS** structure contains the first 16 bits that follow the table_id in a generic MPEG-2 section header.

## Members

### `SectionLength`

The length of the section, in bytes.

### `Reserved`

Two reserved bits.

### `PrivateIndicator`

The private_indicator bit.

### `SectionSyntaxIndicator`

The section_syntax_indicator bit.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)

[SECTION Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section)