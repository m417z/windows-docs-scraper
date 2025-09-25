# IMFMediaEngineProtectedContent::TransferVideoFrame

## Description

Copies a protected video frame to a DXGI surface.

## Parameters

### `pDstSurf` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the destination surface.

### `pSrc` [in]

A pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle.

### `pDst` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination rectangle.

### `pBorderClr` [in]

A pointer to an [MFARGB](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfargb) structure that specifies the border color.

### `pFrameProtectionFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_frame_protection_flags) enumeration. These flags indicate which content protections the application must apply before presenting the surface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For protected content, call this method instead of the [IMFMediaEngine::TransferVideoFrame](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-transfervideoframe) method.

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)