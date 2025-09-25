# IMFMediaEngine::TransferVideoFrame

## Description

Copies the current video frame to a DXGI surface or WIC bitmap.

## Parameters

### `pDstSurf` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the destination surface.

### `pSrc` [in]

A pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle.

### `pDst` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination rectangle.

### `pBorderClr` [in]

A pointer to an [MFARGB](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfargb) structure that specifies the border color.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In frame-server mode, call this method to blit the video frame to a DXGI or WIC surface. The application can call this method at any time after the Media Engine loads a video resource. Typically, however, the application calls [IMFMediaEngine::OnVideoStreamTick](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-onvideostreamtick) first, to determine whether a new frame is available. If **OnVideoStreamTick** returns **S_OK**, the application then calls **TransferVideoFrame**.

The Media Engine scales and letterboxes the video to fit the destination rectangle. It fills the letterbox area with the border color.

For protected content, call the [IMFMediaEngineProtectedContent::TransferVideoFrame](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineprotectedcontent-transfervideoframe) method instead of this method.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)