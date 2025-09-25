# IMemInputPin::ReceiveCanBlock

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReceiveCanBlock` method determines whether calls to the [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) method might block.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The pin will not block on a call to **Receive** |
| **S_OK** | The pin might block on a call to **Receive**. |

## Remarks

If this method returns S_FALSE, calls to the **Receive** method are guaranteed not to block. Otherwise, they might block. An upstream filter can use this method to determine its threading strategy. If calls to **Receive** can block, the upstream filter might decide to use a worker thread that buffers data.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)