# IMMDevice::Activate

## Description

The **Activate** method creates a COM object with the specified interface.

## Parameters

### `iid` [in]

The interface identifier. This parameter is a reference to a GUID that identifies the interface that the caller requests be activated. The caller will use this interface to communicate with the COM object. Set this parameter to one of the following interface identifiers:

IID_IAudioClient

IID_IAudioEndpointVolume

IID_IAudioMeterInformation

IID_IAudioSessionManager

IID_IAudioSessionManager2

IID_IBaseFilter

IID_IDeviceTopology

IID_IDirectSound

IID_IDirectSound8

IID_IDirectSoundCapture

IID_IDirectSoundCapture8

IID_IMFTrustedOutput

IID_ISpatialAudioClient

IID_ISpatialAudioMetadataClient

For more information, see Remarks.

### `dwClsCtx` [in]

The execution context in which the code that manages the newly created object will run. The caller can restrict the context by setting this parameter to the bitwise **OR** of one or more **CLSCTX** enumeration values. Alternatively, the client can avoid imposing any context restrictions by specifying CLSCTX_ALL. For more information about **CLSCTX**, see the Windows SDK documentation.

### `pActivationParams` [in]

Set to **NULL** to activate an [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume), [IAudioMeterInformation](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation), [IAudioSessionManager](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager), or [IDeviceTopology](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology) interface on an audio endpoint device.

When activating an **IBaseFilter**, **IDirectSound**, **IDirectSound8**, **IDirectSoundCapture**, or **IDirectSoundCapture8** interface on the device, the caller can specify a pointer to a **PROPVARIANT** structure that contains stream-initialization information. For more information, see Remarks.

### `ppInterface` [out]

Pointer to a pointer variable into which the method writes the address of the interface specified by parameter *iid*. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **Activate** call fails, **ppInterface* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The object does not support the requested interface type. |
| **E_POINTER** | Parameter *ppInterface* is **NULL**. |
| **E_INVALIDARG** | The *pActivationParams* parameter must be **NULL** for the specified interface; or *pActivationParams* points to invalid data. |
| **E_OUTOFMEMORY** | Out of memory. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The user has removed either the audio endpoint device or the adapter device that the endpoint device connects to. |

## Remarks

This method creates a COM object with an interface that is specified by the *iid* parameter. The method is similar to the Windows **CoCreateInstance** function, except that the caller does not supply a CLSID as a parameter. For more information about **CoCreateInstance**, see the Windows SDK documentation.

A client can call the **Activate** method of the **IMMDevice** interface for a particular audio endpoint device to obtain a counted reference to an interface on that device. The method can activate the following interfaces:

* [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)
* [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)
* [IAudioMeterInformation](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation)
* [IAudioSessionManager](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager)
* [IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)
* IBaseFilter
* [IDeviceTopology](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)
* IDirectSound
* IDirectSound8
* IDirectSoundCapture
* IDirectSoundCapture8
* IMFTrustedOutput

To obtain the interface ID for an interface, use the **__uuidof** operator. For example, the interface ID of **IAudioCaptureClient** is defined as follows:

``` syntax

const IID IID_IAudioClient  __uuidof(IAudioCaptureClient)

```

For information about the **__uuidof** operator, see the Windows SDK documentation. For information about **IBaseFilter**, **IDirectSound**, **IDirectSound8**, **IDirectSoundCapture**, **IDirectSoundCapture8**, and **IMFTrustedOutput** see the Windows SDK documentation.

The *pActivationParams* parameter should be **NULL** for an **Activate** call to create an **IAudioEndpointVolume**, **IAudioMeterInformation**, **IAudioSessionManager**, or **IDeviceTopology** interface for an audio endpoint device. Starting in Windows 10 Build 20348, callers activating an **IAudioClient** can set *pActivationParams* to a pointer to a [AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params) to configure an audio client in loopback mode with a process filter.

For an **Activate** call to create an **IBaseFilter**, **IDirectSound**, **IDirectSound8**, **IDirectSoundCapture**, or **IDirectSoundCapture8** interface, the caller can, as an option, specify a non-**NULL** value for *pActivationParams*. In this case, *pActivationParams* points to a **PROPVARIANT** structure that contains stream-initialization information. Set the **vt** member of the structure to VT_BLOB. Set the **blob.pBlobData** member to point to a [DIRECTX_AUDIO_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ns-mmdeviceapi-directx_audio_activation_params) structure that contains an audio session GUID and stream-initialization flags. Set the **blob.cbSize** member to **sizeof**(**DIRECTX_AUDIO_ACTIVATION_PARAMS**). For a code example, see [Device Roles for DirectShow Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-for-directshow-applications). For more information about **PROPVARIANT**, see the Windows SDK documentation.

An **IBaseFilter**, **IDirectSound**, **IDirectSound8**, **IDirectSoundCapture**, or **IDirectSoundCapture8** interface instance that is created by the **Activate** method encapsulates a stream on the audio endpoint device. During the **Activate** call, the DirectSound system module creates the stream by calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ns-mmdeviceapi-directx_audio_activation_params) method. If *pActivationParams* is non-**NULL**, DirectSound supplies the audio session GUID and stream-initialization flags from the **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure as input parameters to the **Initialize** call. If *pActivationParams* is **NULL**, DirectSound sets the **Initialize** method's *AudioSessionGuid* and *StreamFlags* parameters to their respective default values, **NULL** and 0. These values instruct the method to assign the stream to the process-specific session that is identified by the session GUID value GUID_NULL.

**Activate** can activate an **IDirectSound** or **IDirectSound8** interface only on a rendering endpoint device. It can activate an **IDirectSoundCapture** or **IDirectSoundCapture8** interface only on a capture endpoint device. An **Activate** call to activate an **IDirectSound** or **IDirectSoundCapture8** interface on a capture device or an **IDirectSoundCapture** or **IDirectSoundCapture8** interface on a rendering device fails and returns error code E_NOINTERFACE.

In Windows 7, a client can call **IMMDevice::Activate** and specify, **IID_IMFTrustedOutput**, to create an output trust authorities (OTA) object and retrieve a pointer to the object's [IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput) interface. OTAs can operate inside or outside the Media Foundation's protected media path (PMP) and send content outside the Media Foundation pipeline. If the caller is outside PMP, then the OTA may not operate in the PMP, and the protection settings are less robust. For information about using protected objects for audio and example code, see [Protected User Mode Audio (PUMA)](https://learn.microsoft.com/windows/desktop/CoreAudio/protected-user-mode-audio--puma-).

For general information about protected objects and [IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput), see "Protected Media Path" in Media Foundation documentation.

**Note** When using the [ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) interfaces on an Xbox One Development Kit (XDK) title, you must first call **EnableSpatialAudio** before calling [IMMDeviceEnumerator::EnumAudioEndpoints](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-enumaudioendpoints) or [IMMDeviceEnumerator::GetDefaultAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdefaultaudioendpoint). Failure to do so will result in an E_NOINTERFACE error being returned from the call to Activate. **EnableSpatialAudio** is only available for XDK titles, and does not need to be called for Universal Windows Platform apps running on Xbox One, nor for any non-Xbox One devices.

For code examples that call the **Activate** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies)
* [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties)
* [Audio Events for Legacy Audio Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-events-for-legacy-audio-applications)
* [Render Spatial Sound Using Spatial Audio Objects](https://learn.microsoft.com/windows/desktop/CoreAudio/render-spatial-sound-using-spatial-audio-objects)

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioMeterInformation Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation)

[IAudioSessionManager Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager)

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)