# IAMExtTransport::GetEditPropertySet

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetEditPropertySet` method retrieves the state of an edit event.

This method is not implemented.

## Parameters

### `EditID` [in]

Specifies the edit property set. Use the identifier returned by the [IAMExtTransport::SetEditPropertySet](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditpropertyset) method.

### `pState` [out]

Pointer to a **long** integer that receives the state of the edit property set:

| Value | Description |
| --- | --- |
| ED_ACTIVE | The edit property set is active. |
| ED_DELETE | The edit property set was deleted. |
| ED_INACTIVE | The edit property set is inactive. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::SetEditPropertySet](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditpropertyset)