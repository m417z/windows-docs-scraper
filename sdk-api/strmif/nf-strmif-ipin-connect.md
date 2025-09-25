# IPin::Connect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Connect` method connects the pin to another pin.

Applications should not call this method. Use [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) methods instead. This method is called by the Filter Graph Manager to connect pins.

## Parameters

### `pReceivePin` [in]

Pointer to the receiving pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface.

### `pmt` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type for the connection. Can be **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_ALREADY_CONNECTED** | The pin is already connected. |
| **VFW_E_NO_ACCEPTABLE_TYPES** | Cannot find an acceptable media type. |
| **VFW_E_NO_TRANSPORT** | Pins cannot agree on a transport, or there is no allocator for the connection. |
| **VFW_E_NOT_STOPPED** | The filter is active and the pin does not support dynamic reconnection. |
| **VFW_E_TYPE_NOT_ACCEPTED** | The specified media type is not acceptable. |

## Remarks

The *pmt* parameter can be **NULL**. It can also specify a partial media type, with a value of GUID_NULL for the major type, subtype, or format.

This method verifies that the connection is possible. If the pin rejects the connection, the method fails. The connecting pin proposes media types by calling [IPin::ReceiveConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-receiveconnection) on the receiving pin.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)