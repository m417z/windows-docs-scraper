# IMFMediaEngineProtectedContent::GetRequiredProtections

## Description

Gets the content protections that must be applied in frame-server mode.

## Parameters

### `pFrameProtectionFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_frame_protection_flags) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)