# GetBufferedPaintDC function

## Description

Gets the paint device context (DC). This is the same value retrieved by [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

Handle of the buffered paint context, obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Return value

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the requested DC. This is the same DC that is returned by [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint). Returns **NULL** upon failure.