# EMRFORMAT structure

## Description

The **EMRFORMAT** structure contains information that identifies graphics data in an enhanced metafile. A GDICOMMENT_MULTIFORMATS enhanced metafile public comment contains an array of **EMRFORMAT** structures.

## Members

### `dSignature`

Contains a picture format identifier. The following identifier values are defined.

| Identifier | Meaning |
| --- | --- |
| ENHMETA_SIGNATURE | The picture is in enhanced metafile format. |
| EPS_SIGNATURE | The picture is in encapsulated PostScript file format. |

### `nVersion`

Contains a picture version number. The following version number value is defined.

| Version | Meaning |
| --- | --- |
| 1 | This is the version number of a level 1 encapsulated PostScript file. |

### `cbData`

The size, in bytes, of the picture data.

### `offData`

Specifies an offset to the picture data. The offset is figured from the start of the GDICOMMENT_MULTIFORMATS public comment within which this **EMRFORMAT** structure is embedded. The offset must be a **DWORD** offset.

## Remarks

The reference page for [GdiComment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdicomment) discusses enhanced metafile public comments in general, and the GDICOMMENT_MULTIFORMATS public comment in particular.

## See also

[GdiComment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdicomment)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)