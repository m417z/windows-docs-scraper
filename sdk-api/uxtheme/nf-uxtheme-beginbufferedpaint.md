# BeginBufferedPaint function

## Description

Begins a buffered paint operation.

## Parameters

### `hdcTarget`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the target DC on which the buffer will be painted.

### `prcTarget`

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the area of the target DC in which to paint.

### `dwFormat`

Type: **[BP_BUFFERFORMAT](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-bp_bufferformat)**

A member of the [BP_BUFFERFORMAT](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-bp_bufferformat) enumeration that specifies the format of the buffer.

### `pPaintParams` [in]

Type: **[BP_PAINTPARAMS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-bp_paintparams)***

A pointer to a [BP_PAINTPARAMS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-bp_paintparams) structure that defines the paint operation parameters. This value can be **NULL**.

### `phdc` [out]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

When this function returns, points to the handle of the new device context.

## Return value

Type: **HPAINTBUFFER**

A handle to the buffered paint context. If this function fails, the return value is **NULL**, and *phdc* is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The returned handle is freed when [EndBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-endbufferedpaint) is called.

An application should call [BufferedPaintInit](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-bufferedpaintinit) on the calling thread before calling **BeginBufferedPaint**, and [BufferedPaintUnInit](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-bufferedpaintuninit) before the thread is terminated. Failure to call **BufferedPaintInit** may result in degraded performance due to internal data being initialized and destroyed for each buffered paint operation.