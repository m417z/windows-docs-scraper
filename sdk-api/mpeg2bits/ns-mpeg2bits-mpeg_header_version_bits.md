# MPEG_HEADER_VERSION_BITS structure

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **MPEG_HEADER_VERSION_BITS** structure contains the first 8 bits following the TSID in an MPEG-2 PSI section. These bits contain the version number and the current/next indicator.

## Members

### `CurrentNextIndicator`

The current_next_indicator field.

### `VersionNumber`

The version_number field.

### `Reserved`

Two reserved bits.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)