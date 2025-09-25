# IAMExtTransport::get_LocalControl

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_LocalControl` method determines whether the transport is under local control or remote control.

This method is not implemented.

## Parameters

### `pState` [out]

Pointer to a **long** integer that receives one of the following values:

| Value | Description |
| --- | --- |
| OATRUE | Local control. |
| OAFALSE | Remote control. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

To control an external device from an application, the device must be in remote mode.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::put_LocalControl](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-put_localcontrol)