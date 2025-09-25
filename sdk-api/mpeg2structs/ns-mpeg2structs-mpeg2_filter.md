# MPEG2_FILTER structure

## Description

The **MPEG2_FILTER** structure specifies criteria for matching MPEG-2 section headers.

## Members

### `bVersionNumber`

Specifies the version number of the structure. This value must be 1 or higher.

### `wFilterSize`

Specifies the size of the structure data, excluding any padding bytes. Set this field equal to the constant **MPEG2_FILTER_VERSION_1_SIZE**.

### `fUseRawFilteringBits`

If **TRUE**, the **Filter** and **Mask** members specify the filtering criteria as a pair of bit masks, and the remaining members of this structure are ignored. If this field is **FALSE**, the **Filter** and **Mask** members are ignored, and the other structure members contain the filtering criteria.

### `Filter`

Specifies a 16-byte bit mask, which contains the bit values to match in the section header.

### `Mask`

Specifies a 16-byte bit mask. Set any "don't care" bits equal to 1, and all other bits to 0. In other words, for each bit, if the value in **Mask** is 0, the corresponding bit in **Filter** will be matched against that bit in the section header. If the value in **Mask** is 1, that bit in the section header is ignored.

### `fSpecifyTableIdExtension`

If **TRUE**, the **table_ID_extension** field in the header must match the value of the **TableIdExtension** structure member. Otherwise, the **table_ID_extension** field is ignored.

### `TableIdExtension`

Specifies a value for the **table_ID_extension** field.

### `fSpecifyVersion`

If **TRUE**, the **version_number** field in the header must match the value of the **Version** structure member. Otherwise, the **version_number** field is ignored.

### `Version`

Specifies a value for the **version_number** field.

### `fSpecifySectionNumber`

If **TRUE**, the **section_number** field in the header must match the value of the **SectionNumber** member. Otherwise, the **section_number** field is ignored.

### `SectionNumber`

Specifies a value for the **section_number** field.

### `fSpecifyCurrentNext`

If **TRUE**, the **current_next_indicator** bit in the header must match the value of the **fNext** structure member. Otherwise, the **current_next_indicator** field is ignored.

### `fNext`

Specifies a value for the **current_next_indicator** bit. You can use the [MPEG_CURRENT_NEXT_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ne-mpeg2structs-mpeg_current_next_bit) enumeration type to specify this value.

### `fSpecifyDsmccOptions`

If **TRUE**, the **Dsmcc** member contains additional filtering criteria for the DSM-CC portions of the section header. Otherwise, the **Dsmcc** member is ignored.

### `Dsmcc`

Specifies a [DSMCC_FILTER_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-dsmcc_filter_options) structure that contains additional filtering criteria for the DSM-CC portions of the section header.

### `fSpecifyAtscOptions`

If **TRUE**, the **Atsc** member contains additional filtering criteria. Otherwise, the **Atsc** member is ignored.

### `Atsc`

Specifies an [ATSC_FILTER_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-atsc_filter_options) structure that contains additional filtering criteria.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)