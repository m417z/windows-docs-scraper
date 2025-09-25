# IMFCaptureEngineOnEventCallback::OnEvent

## Description

Called by the capture engine to notify the application of a capture event.

## Parameters

### `pEvent` [in]

A pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface. Use this interface to get information about the event, as described in Remarks.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the type of event, call [IMFMediaEvent::GetExtendedType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getextendedtype). This method returns one of the following GUIDs.

| GUID | Description |
| --- | --- |
| **MF_CAPTURE_ENGINE_ALL_EFFECTS_REMOVED** | The [IMFCaptureSource::RemoveAllEffects](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-removealleffects) method completed. |
| **MF_CAPTURE_ENGINE_CAMERA_STREAM_BLOCKED** | Video capture has been blocked by the driver. |
| **MF_CAPTURE_ENGINE_CAMERA_STREAM_UNBLOCKED** | Video capture has been restored by the driver after having been blocked. |
| **MF_CAPTURE_ENGINE_EFFECT_ADDED** | The [IMFCaptureSource::AddEffect](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-addeffect) method completed. |
| **MF_CAPTURE_ENGINE_EFFECT_REMOVED** | The [IMFCaptureSource::RemoveEffect](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-removeeffect) method completed. |
| **MF_CAPTURE_ENGINE_ERROR** | An error occurred during capture. |
| **MF_CAPTURE_ENGINE_INITIALIZED** | The [IMFCaptureEngine::Initialize](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-initialize) method completed. |
| **MF_CAPTURE_ENGINE_PHOTO_TAKEN** | The [IMFCaptureEngine::TakePhoto](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-takephoto) method completed. |
| **MF_CAPTURE_ENGINE_PREVIEW_STARTED** | The [IMFCaptureEngine::StartPreview](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-startpreview) method completed. |
| **MF_CAPTURE_ENGINE_PREVIEW_STOPPED** | The [IMFCaptureEngine::StopPreview](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-stoppreview) method completed. |
| **MF_CAPTURE_ENGINE_RECORD_STARTED** | The [IMFCaptureEngine::StartRecord](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-startrecord) method completed. |
| **MF_CAPTURE_ENGINE_RECORD_STOPPED** | The [IMFCaptureEngine::StopRecord](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-stoprecord) method completed. |
| **MF_CAPTURE_SINK_PREPARED** | The [IMFCaptureSink::Prepare](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-prepare) method completed. |
| **MF_CAPTURE_SOURCE_CURRENT_DEVICE_MEDIA_TYPE_SET** | The [IMFCaptureSource::SetCurrentDeviceMediaType](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-setcurrentdevicemediatype) method completed. |

This method may be called from a worker thread. The implementation should be thread-safe.

To get the status code for the event, call [IMFMediaEvent::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getstatus). If the status code is an error code, it indicates that the requested operation failed.

In addition, the event object specified by *pEvent* might contain any of the following attributes.

* [MF_CAPTURE_ENGINE_EVENT_GENERATOR_GUID](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-event-generator-guid)
* [MF_CAPTURE_ENGINE_EVENT_STREAM_INDEX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh162817(v=vs.85))

To get event attributes, use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface, which [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) inherits.

## See also

[IMFCaptureEngineOnEventCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineoneventcallback)