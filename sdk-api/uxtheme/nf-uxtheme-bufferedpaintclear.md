# BufferedPaintClear function

## Description

Clears a specified rectangle in the buffer to ARGB = {0,0,0,0}.

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

The handle of the buffered paint context, obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the rectangle to clear. Set this parameter to **NULL** to specify the entire buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function accesses the buffer bits directly and is therefore faster than calling a GDI function to erase the buffer.