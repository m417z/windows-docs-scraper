# GetBufferedPaintTargetRect function

## Description

Retrieves the target rectangle specified by BeginBufferedPaint.

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

Handle to the buffered paint context obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

### `prc` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

When this function returns, contains the requested rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this function fails, the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure at *prc* is set to empty.