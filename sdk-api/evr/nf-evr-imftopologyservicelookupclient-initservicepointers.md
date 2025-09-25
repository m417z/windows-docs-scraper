# IMFTopologyServiceLookupClient::InitServicePointers

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Signals the mixer or presenter to query the enhanced video renderer (EVR) for interface pointers.

## Parameters

### `pLookup` [in]

Pointer to the [IMFTopologyServiceLookup](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imftopologyservicelookup) interface. To query the EVR for an interface, call [IMFTopologyServiceLookup::LookupService](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imftopologyservicelookup-lookupservice).

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The [IMFTopologyServiceLookup](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imftopologyservicelookup) pointer is guaranteed to be valid only during the call to **InitServicePointers**. The mixer or presenter should not store a pointer to this interface after the method returns.

When the EVR calls [IMFTopologyServiceLookupClient::ReleaseServicePointers](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imftopologyservicelookupclient-releaseservicepointers), the mixer or presenter should release any pointers it obtained from the EVR.

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFTopologyServiceLookupClient](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imftopologyservicelookupclient)