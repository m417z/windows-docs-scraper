# DTBGOPTS structure

## Description

Defines the options for the [DrawThemeBackgroundEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemebackgroundex) function.

## Members

### `dwSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the structure. Set this to sizeof(DTBGOPTS).

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that specify the selected options. This member can be one of the following:

| Value | Meaning |
| --- | --- |
| **DTBG_CLIPRECT** | **rcClip** specifies the rectangle to which drawing is clipped. |
| **DTBG_DRAWSOLID** | Deprecated. Draw transparent and alpha images as solid. |
| **DTBG_OMITBORDER** | Do not draw the border of the part (currently this value is only supported for bgtype=borderfill). |
| **DTBG_OMITCONTENT** | Do not draw the content area of the part (currently this value is only supported for bgtype=borderfill). |
| **DTBG_COMPUTINGREGION** | Deprecated. |
| **DTBG_MIRRORDC** | Assume the **hdc** is mirrored and flip images as appropriate (currently this value is only supported for bgtype=imagefile). |
| **DTBG_NOMIRROR** | Do not mirror the output; even in right-to-left (RTL) layout. |
| **DTBG_VALIDBITS** | DTBG_CLIPRECT \| DTBG_DRAWSOLID \| DTBG_OMITBORDER \| DTBG_OMITCONTENT \| DTBG_COMPUTINGREGION \| DTBG_MIRRORDC \| DTBG_NOMIRROR. |

### `rcClip`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) that specifies the bounding rectangle of the clip region.

## See also

[DrawThemeBackgroundEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemebackgroundex)