# MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAGS enumeration

## Description

Specifies the content protection requirements for a video frame.

## Constants

### `MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAG_PROTECTED:0x1`

The video frame should be protected.

### `MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAG_REQUIRES_SURFACE_PROTECTION:0x2`

Direct3D surface protection must be applied to any surface that contains the frame.

### `MF_MEDIA_ENGINE_FRAME_PROTECTION_FLAG_REQUIRES_ANTI_SCREEN_SCRAPE_PROTECTION:0x4`

Direct3D anti-screen-scrape protection must be applied to any surface that contains the frame.

## See also

[IMFMediaEngineProtectedContent::GetRequiredProtections](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineprotectedcontent-getrequiredprotections)

[IMFMediaEngineProtectedContent::TransferVideoFrame](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineprotectedcontent-transfervideoframe)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)