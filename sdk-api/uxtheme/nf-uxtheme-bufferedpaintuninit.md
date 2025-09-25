# BufferedPaintUnInit function

## Description

Closes down buffered painting for the current thread. Called once for each call to [BufferedPaintInit](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-bufferedpaintinit) after calls to [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint) are no longer needed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.