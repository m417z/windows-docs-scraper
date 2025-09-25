# IAudioClient::GetService

## Description

The **GetService** method accesses additional services from the audio client object.

## Parameters

### `riid` [in]

The interface ID for the requested service. The client should set this parameter to one of the following REFIID values:

IID_IAudioCaptureClient

IID_IAudioClientDuckingControl

IID_IAudioClock

IID_IAudioRenderClient

IID_IAudioSessionControl

IID_IAudioStreamVolume

IID_IChannelAudioVolume

IID_IMFTrustedOutput

IID_ISimpleAudioVolume

For more information, see Remarks.

### `ppv` [out]

Pointer to a pointer variable into which the method writes the address of an instance of the requested interface. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetService** call fails, **ppv* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppv* is **NULL**. |
| **E_NOINTERFACE** | The requested interface is not available. |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been initialized. |
| **AUDCLNT_E_WRONG_ENDPOINT_TYPE** | The caller tried to access an [IAudioCaptureClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient) interface on a rendering endpoint, or an [IAudioRenderClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiorenderclient) interface on a capture endpoint. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

The **GetService** method supports the following service interfaces:

* [IAudioCaptureClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)
* [IAudioClock](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock)
* [IAudioRenderClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiorenderclient)
* [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)
* [IAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)
* [IChannelAudioVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)
* [IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput)
* [ISimpleAudioVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)

In Windows 7, a new service identifier, **IID_IMFTrustedOutput**, has been added that facilitates the use of output trust authority (OTA) objects. These objects can operate inside or outside the Media Foundation's protected media path (PMP) and send content outside the Media Foundation pipeline. If the caller is outside PMP, then the OTA may not operate in the PMP, and the protection settings are less robust. OTAs must implement the [IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput) interface.
By passing **IID_IMFTrustedOutput** in **GetService**, an application can retrieve a pointer to the object's **IMFTrustedOutput** interface. For more information about protected objects and **IMFTrustedOutput**, see "Protected Media Path" in the Media Foundation SDK documentation.

For information about using trusted audio drivers in OTAs, see [Protected User Mode Audio (PUMA)](https://learn.microsoft.com/windows/desktop/CoreAudio/protected-user-mode-audio--puma-).

Note that activating IMFTrustedOutput through this mechanism works regardless of whether the caller is running in PMP. However, if the caller is not running in a protected process (that is, the caller is not within Media Foundation's PMP) then the audio OTA might not operate in the PMP and the protection settings are less robust.

To obtain the interface ID for a service interface, use the **__uuidof** operator. For example, the interface ID of **IAudioCaptureClient** is defined as follows:

``` syntax

const IID IID_IAudioCaptureClient  __uuidof(IAudioCaptureClient)

```

For information about the **__uuidof** operator, see the Windows SDK documentation.

To release the **IAudioClient** object and free all its associated resources, the client must release all references to any service objects that were created by calling **GetService**, in addition to calling **Release** on the **IAudioClient** interface itself. The client must release a service from the same thread that releases the **IAudioClient** object.

The **IAudioSessionControl**, **IAudioStreamVolume**, **IChannelAudioVolume**, and **ISimpleAudioVolume** interfaces control and monitor aspects of audio sessions and shared-mode streams. These interfaces do not work with exclusive-mode streams.

For code examples that call the **GetService** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)

## See also

[IAudioCaptureClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClock Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock)

[IAudioRenderClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiorenderclient)

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioStreamVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)