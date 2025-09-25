# IAMExtTransport::SetBump

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetBump` method temporarily changes the playback, for synchronization of multiple external devices.

This method is not implemented.

## Parameters

### `Speed` [in]

Specifies the temporary speed (a multiple of normal speed) as a **long** integer.

### `Duration` [in]

Specifies the duration of a bump as a **long** integer. The duration is given in the current time format; see [IAMExtTransport::SetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportbasicparameters) for more information.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method causes a temporary speed variation of the transport. The transport operates at the new speed until the specified duration elapses. Then it returns to its previous speed.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetBump](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-getbump)