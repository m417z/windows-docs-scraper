# IPinConnection::DynamicQueryAccept

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DynamicQueryAccept` method queries whether the pin can accept the specified media type while the graph is running with the current connection to this pin.

## Parameters

### `pmt` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Media type is acceptable. |
| **VFW_E_TYPE_NOT_ACCEPTED** | Media type is not acceptable. |

## Remarks

If this method succeeds, the pin can accept the media type on the next sample or in a call to [IPin::ReceiveConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-receiveconnection).

An application or filter can call this method to determine whether the filter graph must be reconfigured. If the pin can accept the specified media type, there is no need to reconfigure the graph.

Although the [IPin::QueryAccept](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryaccept) method also determines whether a pin can accept a format type, it does not guarantee that the pin can switch to that format while the filter is running. If you need to switch formats while the filter is running, call `DynamicQueryAccept` instead.

## See also

[Dynamic Format Changes](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-format-changes)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPinConnection Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection)