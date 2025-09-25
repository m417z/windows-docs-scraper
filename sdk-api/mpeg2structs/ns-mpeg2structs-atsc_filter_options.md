# ATSC_FILTER_OPTIONS structure

## Description

The **ATSC_FILTER_OPTIONS** structure specifies additional criteria for matching ATSC section headers.

## Members

### `fSpecifyEtmId`

If this flag is **TRUE**, the ETM_id field in the header must match the value of the **EtmId** structure member. Otherwise, the ETM_id field is ignored.

### `EtmId`

Specifies a value for the ETM_id field.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)

[MPEG2_FILTER Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg2_filter)