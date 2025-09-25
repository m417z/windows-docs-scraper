# IMultiMediaStream::GetInformation

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `GetInformation` method retrieves the capabilities of the multimedia stream object.

## Parameters

### `pdwFlags` [out]

Pointer to a variable that receives a bitwise combination of the following flags.

| Value | Description |
| --- | --- |
| MMSSF_ASYNCHRONOUS | The object supports asynchronous sample updates. This flag is always returned. |
| MMSSF_HASCLOCK | The object has a clock. |
| MMSSF_SUPPORTSEEK | The object supports seeking. |

This parameter can be **NULL**.

### `pStreamType` [out]

Pointer to a variable that receives a member of the [STREAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mmstream/ne-mmstream-stream_type) enumeration. This value indicates whether the multimedia stream is read-only, write-only, or read/write. This parameter can be **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | Unexpected error. |
| **S_OK** | Success. |

## See also

[IMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imultimediastream)