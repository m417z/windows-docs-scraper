# IMediaObject::GetInputStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInputStatus` method queries whether an input stream can accept more input data.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `dwFlags` [out]

Pointer to a variable that receives either zero or DMO_INPUT_STATUSF_ACCEPT_DATA.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **S_OK** | Success |

## Remarks

If the input stream will accept more data, the method returns the DMO_INPUT_STATUSF_ACCEPT_DATA flag in the *dwFlags* parameter. Otherwise, it sets this parameter to zero. If the stream will accept more data, the application can call the [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) method.

The status of an input stream can change only as the result of one of the following method calls.

| Method | Description |
| --- | --- |
| [IMediaObject::Discontinuity](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-discontinuity) | Signals a discontinuity on the specified input stream. |
| [IMediaObject::Flush](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-flush) | Flushes all internally buffered data. |
| [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) | Delivers a buffer to the specified input stream. |
| [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput) | Generates output from the current input data. |

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)