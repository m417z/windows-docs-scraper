# IMFCapturePreviewSink::UpdateVideo

## Description

Updates the video frame. Call this method when the preview window receives a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) or [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size) message.

## Parameters

### `pSrc` [in]

A pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle. The source rectangle defines the area of the video frame that is displayed. If this parameter is **NULL**, the entire video frame is displayed.

### `pDst` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination rectangle. The destination rectangle defines the area of the window or DirectComposition visual where the video is drawn.

### `pBorderClr` [in]

The border color. Use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro to create this value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCapturePreviewSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturepreviewsink)