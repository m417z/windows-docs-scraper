# GetBufferedPaintTargetDC function

## Description

Retrieves the target device context (DC).

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

A handle to the buffered paint context obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Return value

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the requested DC, or **NULL** otherwise.

## Remarks

If successful, this function returns the target DC that was passed by the application to [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).