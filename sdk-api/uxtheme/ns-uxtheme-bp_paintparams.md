# BP_PAINTPARAMS structure

## Description

Defines paint operation parameters for [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the following values.

| Value | Meaning |
| --- | --- |
| **BPPF_ERASE**<br><br>0x0001 | Initialize the buffer to ARGB = {0, 0, 0, 0} during [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint). This erases the previous contents of the buffer. |
| **BPPF_NOCLIP**<br><br>0x0002 | Do not apply the clip region of the target DC to the double buffer. If this flag is not set and if the target DC is a window DC, then clipping due to overlapping windows is applied to the double buffer. |
| **BPPF_NONCLIENT**<br><br>0x0004 | A non-client DC is being used. |

### `prcExclude`

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to exclusion [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure. This rectangle is excluded from the clipping region. May be **NULL** for no exclusion rectangle.

### `pBlendFunction`

Type: **const [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction)***

A pointer to [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction) structure, which controls blending by specifying the blending functions for source and destination bitmaps. If **NULL**, the source buffer is copied to the destination with no blending.