# IMFCaptureEngine::Initialize

## Description

Initializes the capture engine.

## Parameters

### `pEventCallback` [in]

A pointer to the [IMFCaptureEngineOnEventCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineoneventcallback) interface. The caller must implement this interface. The capture engine uses this interface to send asynchronous events to the caller.

### `pAttributes` [in, optional]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. This parameter can be **NULL**.

You can use this parameter to configure the capture engine. Call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes) to create an attribute store, and then set any of the following attributes.

* [MF_CAPTURE_ENGINE_D3D_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-d3d-manager)
* [MF_CAPTURE_ENGINE_DISABLE_DXVA](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-disable-dxva)
* [MF_CAPTURE_ENGINE_DISABLE_HARDWARE_TRANSFORMS](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-disable-hardware-transforms)
* [MF_CAPTURE_ENGINE_ENCODER_MFT_FIELDOFUSE_UNLOCK_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-encoder-mft-fieldofuse-unlock-attribute)
* [MF_CAPTURE_ENGINE_EVENT_GENERATOR_GUID](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-event-generator-guid)
* [MF_CAPTURE_ENGINE_EVENT_STREAM_INDEX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh162817(v=vs.85))
* [MF_CAPTURE_ENGINE_MEDIASOURCE_CONFIG](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-mediasource-config)
* [MF_CAPTURE_ENGINE_RECORD_SINK_AUDIO_MAX_PROCESSED_SAMPLES](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-record-sink-audio-max-processed-samples)
* [MF_CAPTURE_ENGINE_RECORD_SINK_AUDIO_MAX_UNPROCESSED_SAMPLES](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-record-sink-audio-max-unprocessed-samples)
* [MF_CAPTURE_ENGINE_RECORD_SINK_VIDEO_MAX_PROCESSED_SAMPLES](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-record-sink-video-max-processed-samples)
* [MF_CAPTURE_ENGINE_RECORD_SINK_VIDEO_MAX_UNPROCESSED_SAMPLES](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-record-sink-video-max-unprocessed-samples)
* [MF_CAPTURE_ENGINE_USE_AUDIO_DEVICE_ONLY](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-use-audio-device-only)
* [MF_CAPTURE_ENGINE_USE_VIDEO_DEVICE_ONLY](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-use-video-device-only)

### `pAudioSource` [in, optional]

An [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer that specifies an audio-capture device. This parameter can be **NULL**.

If you set the [MF_CAPTURE_ENGINE_USE_VIDEO_DEVICE_ONLY](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-use-video-device-only) attribute to **TRUE** in *pAttributes*, the capture engine does not use an audio device, and the *pAudioSource* parameter is ignored.

Otherwise, if *pAudioSource* is **NULL**, the capture engine selects the microphone that is built into the video camera specified by *pVideoSource*. If the video camera does not have a microphone, the capture engine enumerates the audio-capture devices on the system and selects the first one.

To override the default audio device, set *pAudioSource* to an [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) or [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer for the device. For more information, see [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/audio-video-capture-in-media-foundation).

### `pVideoSource` [in, optional]

An [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer that specifies a video-capture device. This parameter can be **NULL**.

If you set the [MF_CAPTURE_ENGINE_USE_AUDIO_DEVICE_ONLY](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-use-audio-device-only) attribute to **TRUE** in *pAttributes*, the capture engine does not use a video device, and the *pVideoSource* parameter is ignored.

Otherwise, if *pVideoSource* is **NULL**, the capture engine enumerates the video-capture devices on the system and selects the first one.

To override the default video device, set *pVideoSource* to an [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) or [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer for the device. For more information, see [Enumerating Video Capture Devices](https://learn.microsoft.com/windows/desktop/medfound/enumerating-video-capture-devices).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | The [Initialize](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-initialize) method was already called. |
| **MF_E_NO_CAPTURE_DEVICES_AVAILABLE** | No capture devices are available. |
| **MF_E_UNSUPPORTED_CAPTURE_DEVICE_PRESENT** | An unsupported capture device is present on the system. This error will only be returned if NULL is specified for the *pVideoSource* parameter, indicating that the system should pick the capture device, and if no supported capture device has already been attached. It is recommended that apps show users a specific unsupported capture device message if this error is returned, rather than a general failure message. |

## Remarks

You must call this method once before using the capture engine. Calling the method a second time returns **MF_E_INVALIDREQUEST**.

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_INITIALIZED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)