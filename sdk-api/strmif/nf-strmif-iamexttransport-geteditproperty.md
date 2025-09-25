# IAMExtTransport::GetEditProperty

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetEditProperty` method retrieves parameters and values associated with an edit event.

This method is not implemented.

## Parameters

### `EditID` [in]

Specifies the edit property set. Use the identifier returned by the [IAMExtTransport::SetEditPropertySet](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditpropertyset) method.

### `Param` [in]

Specifies the edit event parameter to retrieve.

### `pValue` [out]

pointer to a variable that receives the parameter value.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

For a list of edit event parameters and their possible values, see [IAMExtTransport::SetEditProperty](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditproperty). In addition, this method supports ED_EDIT_TEST, which determines whether the device can perform the edit. If the device filter estimates that the device can perform the edit, it returns the value OATRUE in the *pValue* parameter. If not, it returns the value OAFALSE.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::SetEditProperty](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditproperty)