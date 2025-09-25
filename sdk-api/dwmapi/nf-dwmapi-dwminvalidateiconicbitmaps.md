# DwmInvalidateIconicBitmaps function

## Description

Called by an application to indicate that all previously provided iconic bitmaps from a window, both thumbnails and peek representations, should be refreshed.

## Parameters

### `hwnd` [in]

A handle to the window or tab whose bitmaps are being invalidated through this call. This window must belong to the calling process.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this function causes the Desktop Window Manager (DWM) to invalidate its current bitmaps for the window and request new bitmaps from the window when they are next needed. **DwmInvalidateIconicBitmaps** should not be called frequently. Doing so can lead to poor performance as new bitmaps are created and retrieved.