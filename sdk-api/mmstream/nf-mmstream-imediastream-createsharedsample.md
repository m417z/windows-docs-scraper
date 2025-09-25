# IMediaStream::CreateSharedSample

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Creates a new stream sample that shares the same backing object as the existing sample.

## Parameters

### `pExistingSample` [in]

Pointer to the existing sample.

### `dwFlags` [in]

Reserved for flag data. Must be zero.

### `ppNewSample` [out]

Address of a pointer to an [IStreamSample](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample) interface that will point to the newly created shared sample.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There isn't enough memory available to create the sample. |
| **E_POINTER** | One of the parameters is invalid. |
| **MS_E_INCOMPATIBLE** | The existing sample isn't compatible with the specified media stream. |
| **S_OK** | Success; *ppNewSample* points to the newly created sample. |

## Remarks

This method calls **IUnknown::QueryInterface** on the existing sample to retrieve the media type-specific information, which it uses to create the shared sample.

## See also

[IMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream)