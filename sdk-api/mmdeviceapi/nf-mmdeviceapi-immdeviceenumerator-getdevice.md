# IMMDeviceEnumerator::GetDevice

## Description

The **GetDevice** method retrieves an audio endpoint device that is identified by an [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings).

## Parameters

### `pwstrId` [in]

Pointer to a string containing the endpoint ID. The caller typically obtains this string from the [IMMDevice::GetId](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-getid) method or from one of the methods in the [IMMNotificationClient](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient) interface.

### `ppDevice` [out]

Pointer to a pointer variable into which the method writes the address of the [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface for the specified device. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetDevice** call fails, **ppDevice* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pwstrId* or *ppDevice* is **NULL**. |
| **E_NOTFOUND** | The device ID does not identify an audio device that is in this system. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If two programs are running in two different processes and both need to access the same audio endpoint device, one program cannot simply pass the device's **IMMDevice** interface to the other program. However, the programs can access the same device by following these steps:

1. The first program calls the **IMMDevice::GetId** method in the first process to obtain the endpoint ID string that identifies the device.
2. The first program passes the endpoint ID string across the process boundary to the second program.
3. To obtain a reference to the device's **IMMDevice** interface in the second process, the second program calls **GetDevice** with the endpoint ID string.

For more information about the **GetDevice** method, see the following topics:

* [Endpoint ID Strings](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings)
* [Audio Events for Legacy Audio Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-events-for-legacy-audio-applications)

For code examples that use the **GetDevice** method, see the following topics:

* [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties)
* [Device Events](https://learn.microsoft.com/windows/desktop/CoreAudio/device-events)
* [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties)

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IMMDevice::GetId](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-getid)

[IMMDeviceEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)