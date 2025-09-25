# IMMDeviceEnumerator::GetDefaultAudioEndpoint

## Description

The **GetDefaultAudioEndpoint** method retrieves the default audio endpoint for the specified data-flow direction and role.

## Parameters

### `dataFlow` [in]

The data-flow direction for the endpoint device. The caller should set this parameter to one of the following two [EDataFlow](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow) enumeration values:

eRender

eCapture

The data-flow direction for a rendering device is eRender. The data-flow direction for a capture device is eCapture.

### `role` [in]

The role of the endpoint device. The caller should set this parameter to one of the following [ERole](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole) enumeration values:

eConsole

eMultimedia

eCommunications

For more information, see Remarks.

### `ppEndpoint` [out]

Pointer to a pointer variable into which the method writes the address of the [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface of the endpoint object for the default audio endpoint device. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetDefaultAudioEndpoint** call fails, **ppDevice* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppDevice* is **NULL**. |
| **E_INVALIDARG** | Parameter *dataFlow* or *role* is out of range. |
| **E_NOTFOUND** | No device is available. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

**Note**

In Windows Vista, the MMDevice API supports [device roles](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles) but the system-supplied user interface programs do not. The user interface in Windows Vista enables the user to select a default audio device for rendering and a default audio device for capture. When the user changes the default rendering or capture device, the system assigns all three device roles (eConsole, eMultimedia, and eCommunications) to that device. Thus, **GetDefaultAudioEndpoint** always selects the default rendering or capture device, regardless of which role is indicated by the *role* parameter. In a future version of Windows, the user interface might enable the user to assign individual roles to different devices. In that case, the selection of a rendering or capture device by **GetDefaultAudioEndpoint** might depend on the *role* parameter. Thus, the behavior of an audio application developed to run in Windows Vista might change when run in a future version of Windows. For more information, see [Device Roles in Windows Vista](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-in-windows-vista).

This method retrieves the default endpoint device for the specified data-flow direction (rendering or capture) and role. For example, a client can get the default console playback device by making the following call:

```cpp

  hr = pDevEnum->GetDefaultAudioEndpoint(
                   eRender, eConsole, &pDeviceOut);

```

In the preceding code fragment, variable *hr* is of type **HRESULT**, *pDevEnum* is a pointer to an **IMMDeviceEnumerator** interface, and *pDeviceOut* is a pointer to an **IMMDevice** interface.

A Windows system might contain some combination of audio endpoint devices such as desktop speakers, high-fidelity headphones, desktop microphones, headsets with speaker and microphones, and high-fidelity multichannel speakers. The user can assign appropriate roles to the devices. For example, an application that manages voice communications streams can call **GetDefaultAudioEndpoint** to identify the designated rendering and capture devices for that role.

If only a single rendering or capture device is available, the system always assigns all three rendering or capture roles to that device. If the method fails to find a rendering or capture device for the specified role, this means that no rendering or capture device is available at all. If no device is available, the method sets **ppEndpoint* = **NULL** and returns ERROR_NOT_FOUND.

For code examples that call the **GetDefaultAudioEndpoint** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Audio Events for Legacy Audio Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-events-for-legacy-audio-applications)

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IMMDeviceEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)