# IVMRFilterConfig9::SetNumberOfStreams

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetNumberOfStreams` method sets the number of streams to be mixed and instructs the VMR to go into mixer mode.

## Parameters

### `dwMaxStreams` [in]

Double word containing the maximum number of input streams that the VMR will be required to mix.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The mixer is already configured. |
| **E_INVALIDARG** | An attempt was made to configure the mixer for more than 16 input streams. |
| **E_OUTOFMEMORY** | Memory to manage the streams could not be allocated. |

## Remarks

*dwMaxStreams* should be equal to the number of input pins required. Pins cannot be added or removed after the VMR has been connected. If you do not know in advance how many input streams will be required, set *dxMaxStreams* to the maximum number that might be required. A value of 1 is valid for dwMaxStreams. This value does not cause any extra pins to be created, but it does force the VMR to go into "mixer mode."

The VMR creates as many input pins as are specified without attempting to determine whether there is enough video memory to support them all. This is because it has no way of knowing the media type or rectangle dimensions at this time. Later, when an upstream filter attempts to connect to a pin, at that point the media type is known and the VMR will examine the video memory and fail the connection if there is not enough memory to process the stream.

**Note** Although the VMR supports multiple streams, they all share a single clock, and therefore you cannot seek one stream independently of the others. If you need to seek the input streams independently, you must use a different technique.

## See also

[IVMRFilterConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)