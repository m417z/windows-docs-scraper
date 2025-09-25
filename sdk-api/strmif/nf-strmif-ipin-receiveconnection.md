# IPin::ReceiveConnection

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReceiveConnection` method accepts a connection from another pin.

Applications should not call this method. This method is called by other filters during the pin connection process.

## Parameters

### `pConnector` [in]

Pointer to the connecting pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface.

### `pmt` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type for the connection.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_ALREADY_CONNECTED** | The pin is already connected. |
| **VFW_E_NOT_STOPPED** | Cannot connect while filter is active. |
| **VFW_E_TYPE_NOT_ACCEPTED** | The specified media type is not acceptable. |

## Remarks

When an output pin connects, it calls this method on the input pin. The input pin should verify that the specified media type is acceptable. It may also need to check for other connection requirements specific to the owning filter. If the connection is suitable, the input pin should return S_OK, and also do the following:

* Store the media type, and return the same type in the [IPin::ConnectionMediaType](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-connectionmediatype) method.
* Store the output pin's **IPin** interface (*pConnector*), and return this pointer in the [IPin::ConnectedTo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-connectedto) method.

If the connection is unsuitable, the pin should return an error code.

The [CBasePin](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepin) class implements the basic framework for this method, including storing the media type and **IPin** pointers.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Filters Connect](https://learn.microsoft.com/windows/desktop/DirectShow/how-filters-connect)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)