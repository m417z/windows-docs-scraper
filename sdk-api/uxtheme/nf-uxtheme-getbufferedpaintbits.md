# GetBufferedPaintBits function

## Description

Retrieves a pointer to the buffer bitmap if the buffer is a device-independent bitmap (DIB).

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

The handle of the buffered paint context, obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

### `ppbBuffer` [out]

Type: **[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)****

When this function returns, contains a pointer to the address of the buffer bitmap pixels.

### `pcxRow` [out]

Type: **int***

When this function returns, contains a pointer to the width, in pixels, of the buffer bitmap. This value is not necessarily equal to the buffer width. It may be larger.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful, or an error value otherwise. If an error occurs, *ppbBuffer* is set to **NULL** and *pcxRow* is set to zero.

## Remarks

The number of bits per pixel depends on the pixel format passed to [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## See also

[BP_BUFFERFORMAT](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-bp_bufferformat)

[Device-Independent Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/device-independent-bitmaps)

**Other Resources**

**Reference**