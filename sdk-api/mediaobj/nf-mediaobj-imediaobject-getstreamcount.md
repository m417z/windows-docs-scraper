# IMediaObject::GetStreamCount

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetStreamCount` method retrieves the number of input and output streams.

## Parameters

### `pcInputStreams` [out]

Pointer to a variable that receives the number of input streams. Cannot be **NULL**.

### `pcOutputStreams` [out]

Pointer to a variable that receives the number of output streams. Cannot be **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

The DMO might have zero input streams or zero output streams. The number of streams does not change; a DMO cannot dynamically add or remove streams.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)