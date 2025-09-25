# DdCreateDIBSection function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Creates a [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection) structure that shares its color table with the device.

**GdiEntry9** is defined as an alias for this function.

## Parameters

### `hdc`

A valid DC compatible with the current display device.

### `pbmi`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that describes the requested [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection).

### `iUsage`

Specifies the type of data contained in the **bmiColors** array member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure pointed to by *pbmi* (either logical palette indexes or literal RGB values). The following values are defined.

#### (DIB_PAL_COLORS)

The **bmiColors** member is an array of 16-bit indexes into the logical palette of the device context specified by *hdc*.

#### (DIB_RGB_COLORS)

The [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contains an array of literal RGB values.

### `ppvBits`

Pointer to a pointer to the created [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection) data.

### `hSectionApp`

Reserved. Must be **NULL**.

### `dwOffset`

## Return value

If successful, this function returns a handle to a bitmap representing the [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection); otherwise it returns **NULL**.

## Remarks

Calling this function ensures an identity palette, and no palette conversion when [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt) or [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) are called.

Applications are advised to use [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7), which can create 8-bit-per-pixel, identity-paletted surfaces in a manner independent of the operating system.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)