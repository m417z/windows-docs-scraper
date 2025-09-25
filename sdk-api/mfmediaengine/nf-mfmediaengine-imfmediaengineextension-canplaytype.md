# IMFMediaEngineExtension::CanPlayType

## Description

Queries whether the object can load a specified type of media resource.

## Parameters

### `AudioOnly` [in]

If **TRUE**, the Media Engine is set to audio-only mode. Otherwise, the Media Engine is set to audio-video mode.

### `MimeType` [in]

A string that contains a MIME type with an optional codecs parameter, as defined in RFC 4281.

### `pAnswer` [out]

Receives a member of the [MF_MEDIA_ENGINE_CANPLAY](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_canplay) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implement this method if your Media Engine extension supports one or more MIME types.

## See also

[IMFMediaEngineExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineextension)