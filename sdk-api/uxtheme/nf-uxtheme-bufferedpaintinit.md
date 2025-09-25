# BufferedPaintInit function

## Description

Initialize buffered painting for the current thread.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**BufferedPaintInit** is called before [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint) or [BeginBufferedAnimation](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedanimation) for each thread that uses these functions.

Each call to **BufferedPaintInit** should be matched with a call to [BufferedPaintUnInit](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-bufferedpaintuninit) when calls to buffered paint APIs are no longer needed.
An application may call this API multiple times, as long as each call to **BufferedPaintInit** is balanced with a call to **BufferedPaintUnInit**.

This function only needs to be called once in the lifetime of a thread. Typically, this function is called before creating the main application window, or during [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create). Call [BufferedPaintUnInit](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-bufferedpaintuninit) after destroying the window, or during [WM_NCDESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncdestroy).