## Description

Specifies the color and usage of an entry in a logical palette. In GDI, a logical palette is defined by a [LOGPALETTE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logpalette) structure. In Direct3D, logical palettes are used in a [D3DHAL_DP2UPDATEPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2updatepalette) structure.

## Members

### `peRed`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The red intensity value for the palette entry.

### `peGreen`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The green intensity value for the palette entry.

### `peBlue`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The blue intensity value for the palette entry.

### `peFlags`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

For the GDI use case of logical palettes, *peFlags* indicates how the palette entry is to be used. This member may be set to zero or one of the following values.

|Value|Meaning|
|-|-|
|**PC_EXPLICIT**|Specifies that the low-order word of the logical palette entry designates a hardware palette index. This flag allows the application to show the contents of the display device palette.|
|**PC_NOCOLLAPSE**|Specifies that the color be placed in an unused entry in the system palette instead of being matched to an existing color in the system palette. If there are no unused entries in the system palette, the color is matched normally. Once this color is in the system palette, colors in other logical palettes can be matched to this color.|
|**PC_RESERVED**|Specifies that the logical palette entry be used for palette animation. This flag prevents other windows from matching colors to the palette entry since the color frequently changes. If an unused system-palette entry is available, the color is placed in that entry. Otherwise, the color is not available for animation.|

For the Direct3D use case of logical palettes, *peFlags* represents the alpha intensity value for the palette entry..

## See also

* [Direct3D structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)