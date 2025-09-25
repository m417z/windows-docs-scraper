# EMRCREATECOLORSPACEW structure

## Description

The **EMRCREATECOLORSPACEW** structure contains members for the [CreateColorSpace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcolorspacea) enhanced metafile record.
It differs from [EMRCREATECOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emrcreatecolorspace) in that it has a Unicode logical color space and also has an optional array containing raw source profile data.

## Members

### `emr`

The base structure for all record types.

### `ihCS`

Index of the color space in handle table.

### `lcs`

Logical color space. Note, this is the Unicode version of the structure.

### `dwFlags`

Can be the following.

| Flag | Meaning |
| --- | --- |
| CREATECOLORSPACE_EMBEDED | Indicates that a color space is embedded in the metafile. |

### `cbData`

Size of the raw source profile data in bytes, if it is attached.

### `Data`

An array containing the source profile data. The size of the array is **cbData**.

## See also

[CreateColorSpace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcolorspacea)

[EMRCREATECOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emrcreatecolorspace)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)