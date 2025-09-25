# IMFTopologyServiceLookup::LookupService

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Retrieves an interface from the enhanced video renderer (EVR), or from the video mixer or video presenter.

## Parameters

### `Type` [in]

Specifies the scope of the search. Currently this parameter is ignored. Use the value MF_SERVICE_LOOKUP_GLOBAL.

### `dwIndex` [in]

Reserved, must be zero.

### `guidService` [in]

Service GUID of the requested interface.

### `riid` [in]

Interface identifier of the requested interface.

### `ppvObjects` [out]

Array of interface pointers. If the method succeeds, each member of the array contains either a valid interface pointer or **NULL**. The caller must release the interface pointers when the EVR calls [IMFTopologyServiceLookupClient::ReleaseServicePointers](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imftopologyservicelookupclient-releaseservicepointers) (or earlier). If the method fails, every member of the array is **NULL**.

### `pnObjects` [in, out]

Pointer to a value that specifies the size of the *ppvObjects* array. The value must be at least 1. In the current implementation, there is no reason to specify an array size larger than one element. The value is not changed on output.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOINTERFACE** | The requested interface is not available. |
| **MF_E_NOTACCEPTING** | The method was not called from inside the [IMFTopologyServiceLookupClient::InitServicePointers](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imftopologyservicelookupclient-initservicepointers) method. See Remarks. |
| **MF_E_UNSUPPORTED_SERVICE** | The object does not support the specified service GUID. |

## Remarks

This method can be called only from inside the [IMFTopologyServiceLookupClient::InitServicePointers](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imftopologyservicelookupclient-initservicepointers) method. At any other time, the method returns MF_E_NOTACCEPTING.

The presenter can use this method to query the EVR and the mixer. The mixer can use it to query the EVR and the presenter. Which objects are queried depends on the caller and the service GUID, as shown in the following table.

| Caller | Service GUID | Objects queried |
| --- | --- | --- |
| Presenter | MR_VIDEO_RENDER_SERVICE | EVR |
| Presenter | MR_VIDEO_MIXER_SERVICE | Mixer |
| Mixer | MR_VIDEO_RENDER_SERVICE | Presenter and EVR |

The following interfaces are available from the EVR:

* **IMediaEventSink**. This interface is documented in the DirectShow SDK documentation.
* [IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock) interface. This interface is available if the EVR has access to a clock (reference clock in DirectShow or presentation clock in Media Foundation). This interface might not be available. Presenter and mixers must be able to process data without a clock. If the **IMFClock** interface is available, you can also get these related interfaces:

  + [IMFTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimer)
  + [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) (Media Foundation EVR only)

The following interfaces are available from the mixer:

* [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)
* [IMFVideoDeviceID](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodeviceid)

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFTopologyServiceLookup](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imftopologyservicelookup)