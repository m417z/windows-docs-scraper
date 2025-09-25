# MPEG2_FILTER2 structure

## Description

The **MPEG2_FILTER2** structure specifies criteria for matching MPEG-2 section headers.

## Members

### `bVersionNumber`

The version number of the structure. This value must be 2 or higher.

### `wFilterSize`

The size of the structure data, excluding any padding bytes. Set this field equal to the constant **MPEG2_FILTER_VERSION_2_SIZE**.

### `fUseRawFilteringBits`

If **TRUE**, the **Filter** and **Mask** members specify the filtering criteria as a pair of bit masks, and the remaining members of this structure are ignored. If **FALSE**, the **Filter** and **Mask** members are ignored, and the other structure members give the filtering criteria.

### `Filter`

A 16-byte bit mask, which contains the bit values to match in the section header.

### `Mask`

A 16-byte bit mask. For each bit, if the value in **Mask** is 0, the corresponding bit in **Filter** is matched against that bit in the section header. If the value in **Mask** is 1, that bit in the section header is ignored.

### `fSpecifyTableIdExtension`

If **TRUE**, the **table_ID_extension** field in the header must match the value of the **TableIdExtension** structure member. Otherwise, the **table_ID_extension field** is ignored.

### `TableIdExtension`

A value for the **table_ID_extension** field.

### `fSpecifyVersion`

If **TRUE**, the version_number field in the header must match the value of the **Version** member. Otherwise, the **version_number** field is ignored.

### `Version`

A value for the **version_number** field.

### `fSpecifySectionNumber`

If **TRUE**, the **section_number** field in the header must match the value of the **SectionNumber** member. Otherwise, the **section_number** field is ignored.

### `SectionNumber`

A value for the **section_number** field.

### `fSpecifyCurrentNext`

If **TRUE**, the **current_next_indicator** bit in the header must match the value of the **fNext** member. Otherwise, the **current_next_indicator** field is ignored.

### `fNext`

A value for the **current_next_indicator** bit. You can use the [MPEG_CURRENT_NEXT_BIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ne-mpeg2structs-mpeg_current_next_bit) enumeration type to specify this value.

### `fSpecifyDsmccOptions`

If **TRUE**, the **Dsmcc** member contains additional filtering criteria for the DSM-CC portions of the section header. Otherwise, the **Dsmcc** member is ignored.

### `Dsmcc`

A [DSMCC_FILTER_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-dsmcc_filter_options) structure that contains additional filtering criteria for the DSM-CC portions of the section header.

### `fSpecifyAtscOptions`

If **TRUE**, the **Atsc** member contains additional filtering criteria. Otherwise, the **Atsc** member is ignored.

### `Atsc`

An [ATSC_FILTER_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-atsc_filter_options) structure that contains additional filtering criteria.

### `bVersion1Bytes`

### `fSpecifyDvbEitOptions`

If **TRUE**, the **Dvb_Eit** member contains additional filtering criteria. Otherwise, the **Dvb_Eit** member is ignored.

**Note** Requires Windows 7 or later.

### `DvbEit`

An [DVB_EIT_FILTER_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-dvb_eit_filter_options) structure that contains additional filtering criteria.

**Note** Requires Windows 7 or later.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)