# EndBufferedPaint function

## Description

Completes a buffered paint operation and frees the associated buffered paint handle.

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

The handle of the buffered paint context, obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

### `fUpdateTarget`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to copy the buffer to the target DC.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.