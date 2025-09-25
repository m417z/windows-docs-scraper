# IMFMediaEngineEx::SetStereo3DFramePackingMode

## Description

For stereoscopic 3D video, sets the layout of the two views within a video frame.

## Parameters

### `packMode` [in]

A member of the [MF_MEDIA_ENGINE_S3D_PACKING_MODE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_s3d_packing_mode) enumeration that specifies the layout. The two views can be arranged side-by-side, or top-to-bottom.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)