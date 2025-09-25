# IAMExtTransport::GetBump

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetBump` method retrieves the status of bump mode.

This method is not implemented.

## Parameters

### `pSpeed` [out]

Pointer to a **long** integer that receives the temporary bump speed, as a multiple of normal speed.

### `pDuration` [out]

Pointer to a **long** integer that receives the duration of a bump. The duration is given in the current time format; see [IAMExtTransport::SetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportbasicparameters) for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

This method returns the temporary speed and remaining duration for an active "bump."

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::SetBump](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-setbump)