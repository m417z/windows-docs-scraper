# IMFMediaEngine::CanPlayType

## Description

Queries how likely it is that the Media Engine can play a specified type of media resource.

## Parameters

### `type` [in]

A string that contains a MIME type with an optional codecs parameter, as defined in RFC 4281.

### `pAnswer` [out]

Receives an [MF_MEDIA_ENGINE_CANPLAY](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_canplay) enumeration value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **canPlayType** attribute of the **HTMLMediaElement** interface in HTML5.

The **canPlayType** attribute defines the following values.

| Value | Description |
| --- | --- |
| "" (empty string) | The user-agent cannot play the resource, or the resource type is "application/octet-stream". |
| "probably" | The user-agent probably can play the resource. |
| "maybe" | Neither of the previous values applies. |

The value "probably" is used because a MIME type for a media resource is generally not a complete description of the resource. For example, "video/mp4" specifies an MP4 file with video, but does not describe the codec. Even with the optional codecs parameter, the MIME type omits some information, such as the actual coded bit rate. Therefore, it is usually impossible to be certain that playback is possible until the actual media resource is opened.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)