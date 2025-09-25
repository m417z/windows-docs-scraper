# EMRSETICMPROFILE structure

## Description

The **EMRSETICMPROFILE** structure contains members for the [SetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmprofilea) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `dwFlags`

The profile flags. This member can be SETICMPROFILE_EMBEDED (0x00000001).

### `cbName`

The size of the desired profile name.

### `cbData`

The size of profile data, if attached.

### `Data`

An array that contains the profile data. The length of this array is **cbName** plus **cbData**.

## Remarks

This structure is to be used during metafile playback.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmprofilea)