# IMediaObject::Discontinuity

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Discontinuity` method signals a discontinuity on the specified input stream.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **DMO_E_NOTACCEPTING** | The DMO is not accepting input. |
| **DMO_E_TYPE_NOT_SET** | The input and output types have not been set. |
| **S_OK** | Success |

## Remarks

A discontinuity represents a break in the input. A discontinuity might occur because no more data is expected, the format is changing, or there is a gap in the data. After a discontinuity, the DMO does not accept further input on that stream until all pending data has been processed. The application should call the [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput) method until none of the streams returns the DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE flag.

This method might fail if it is called before the client sets the input and output types on the DMO.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)