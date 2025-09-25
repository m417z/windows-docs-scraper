# EMRCOLORMATCHTOTARGET structure

## Description

The **EMRCOLORMATCHTOTARGET** structure contains members for the [ColorMatchToTarget](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-colormatchtotarget) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `dwAction`

The action to be taken. This member can be one of the following values.

| Action | Meaning |
| --- | --- |
| CS_ENABLE | Maps colors to the target device's color gamut. This enables color proofing. All subsequent draw commands to the DC will render colors as they would appear on the target device. |
| CS_DISABLE | Disables color proofing. |
| CS_DELETE_TRANSFORM | If color management is enabled for the target profile, disables it and deletes the concatenated transform. |

### `dwFlags`

This parameter can be the following value.

| Flag | Meaning |
| --- | --- |
| COLORMATCHTOTARGET_EMBEDED | Indicates that a color profile has been embedded in the metafile. |

### `cbName`

The size of the desired target profile name, in bytes.

### `cbData`

The size of the raw target profile data in bytes, if it is attached.

### `Data`

An array containing the target profile name and the raw target profile data.
The size of the array is **cbName** + **cbData**.
If **cbData** is nonzero the raw target profile data is attached and follows the target profile name at location **Data**[**cbName**].

## See also

[ColorMatchToTarget](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-colormatchtotarget)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)