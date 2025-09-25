# ActivateAudioInterfaceAsync function

## Description

Enables Windows Store apps to access preexisting Component Object Model (COM) interfaces in the [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) family.

## Parameters

### `deviceInterfacePath` [in]

A device interface ID for an audio device. This is normally retrieved from a [DeviceInformation](https://learn.microsoft.com/uwp/api/windows.devices.enumeration.deviceinformation) object or one of the methods of the [MediaDevice](https://learn.microsoft.com/uwp/api/windows.media.devices.mediadevice) class.

The GUIDs [DEVINTERFACE_AUDIO_CAPTURE](https://learn.microsoft.com/windows/desktop/CoreAudio/devinterface-xxx-guids) and **DEVINTERFACE_AUDIO_RENDER** represent the default audio capture and render device respectively. Call [StringFromIID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromiid) to convert either of these GUIDs to an **LPCWSTR** to use for this argument.

Specify **VIRTUAL_AUDIO_DEVICE_PROCESS_LOOPBACK** to activate the audio interface for process loopback capture. For sample code that demonstrates the process loopback capture scenario, see the [Application Loopback API Capture Sample](https://docs.microsoft.com/en-us/samples/microsoft/windows-classic-samples/applicationloopbackaudio-sample/).

### `riid` [in]

The IID of a COM interface in the [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) family, such as [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient).

### `activationParams` [in]

Interface-specific activation parameters. For more information, see the *pActivationParams* parameter in [IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate).

Starting with Windows 10 Build 20438, you can specify [AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/desktop/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params) to activate the interface to include or exclude audio streams associated with a specified process ID.

### `completionHandler` [in]

An interface implemented by the caller that is called by Windows when the result of the activation procedure is available.

### `activationOperation`

Returns an [IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation) interface that represents the asynchronous operation of activating the requested **WASAPI** interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The underlying object and asynchronous operation were created successfully. |
| **E_ILLEGAL_METHOD_CALL** | On versions of Windows previous to Windows 10, this error may result if the function is called from an incorrect COM apartment, or if the passed [IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler) is not implemented on an agile object (aggregating a free-threaded marshaler). |

## Remarks

This function enables Windows Store apps to activate certain [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) COM interfaces after using Windows Runtime APIs in the **Windows.Devices** and [Windows.Media.Devices](https://learn.microsoft.com/uwp/api/windows.media.devices) namespaces to select an audio device.

For many implementations, an application must call this function from the main UI thread to activate a COM interface in the [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) family so that the system can show a dialog to the user. The application passes an [IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler) callback COM interface through *completionHandler*. Windows calls a method in the application’s **IActivateAudioInterfaceCompletionHandler** interface from a worker thread in the COM Multi-threaded Apartment (MTA) when the activation results are available. The application can then call a method in the [IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation) interface to retrieve the result code and the requested **WASAPI** interface. There are some activations that are explicitly safe and therefore don't require that this function be called from the main UI thread. These explicitly safe activations include:

* Calling **ActivateAudioInterfaceAsync** with a *deviceInterfacePath* that specifies an audio render device and an *riid* that specifies the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface.
* Calling **ActivateAudioInterfaceAsync** with a *deviceInterfacePath* that specifies an audio render device and an *riid* that specifies the [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) interface.
* Calling **ActivateAudioInterfaceAsync** from a session 0 service. For more information, see [Services](https://learn.microsoft.com/windows/desktop/services/services).

Windows holds a reference to the application's [IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler) interface until the operation is complete and the application releases the [IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation) interface.

**Important**

Applications must not free the object implementing the **IActivateAudioInterfaceCompletionHandler** until the completion handler callback has executed.

Depending on which [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) interface is activated, this function may display a consent prompt the first time it is called. For example, when the application calls this function to activate [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) to access a microphone, the purpose of the consent prompt is to get the user's permission for the app to access the microphone. For more information about the consent prompt, see [Guidelines for devices that access personal data](https://learn.microsoft.com/windows/uwp/security/).

**ActivateAudioInterfaceAsync** must be called on the main UI thread so that the consent prompt can be shown. If the consent prompt can’t be shown, the user can’t grant device access to the app.

On versions of Windows previous to Windows 10, **ActivateAudioInterfaceAsync** must be called on a thread in a COM Single-Threaded Apartment (STA), when opening a device for audio capture. The *completionHandler* that is passed into **ActivateAudioInterfaceAsync** needs to implement [IAgileObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagileobject) to ensure that there is no deadlock when the *completionHandler* is called from the MTA. Otherwise, an **E_ILLEGAL_METHOD_CALL** will occur.

## See also

[Core Audio Functions](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-functions)

[IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation)

[IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler)