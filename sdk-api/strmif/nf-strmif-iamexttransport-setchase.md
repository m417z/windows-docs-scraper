# IAMExtTransport::SetChase

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetChase` method enables or disables chase mode.

This method is not implemented.

## Parameters

### `Enable` [in]

Specifies whether chase is enabled as a **long** integer.

| Value | Description |
| --- | --- |
| OATRUE | Enable chase. |
| OAFALSE | Disable chase. |

### `Offset` [in]

Specifies the offset that the transport will maintain from a reference time. The offset is given in the current time format; see [IAMExtTransport::SetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportbasicparameters) for more information.

### `hEvent` [in]

Specifies a handle to an event. The device signals the event after it has established the signal offset.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Use this method when you want an external transport to follow a timecode signal by a fixed offset. For example, if a VCR supports chasing, it can switch to play mode and keep the tape at a fixed offset from a reference timecode.

Chase mode remains in effect until it completes or is canceled. The filter must verify that the transport is maintaining the fixed offset, by periodically reading the transport's timecode.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetChase](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-getchase)