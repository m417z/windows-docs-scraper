# IMMDevice::GetId

## Description

The **GetId** method retrieves an [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings) that identifies the audio endpoint device.

## Parameters

### `ppstrId` [out]

Pointer to a pointer variable into which the method writes the address of a null-terminated, wide-character string containing the endpoint device ID. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetId** call fails, **ppstrId is NULL.* For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_POINTER** | Parameter *pwstrId* is **NULL**. |

## Remarks

The endpoint ID string obtained from this method identifies the audio endpoint device that is represented by the **IMMDevice** interface instance. A client can use the endpoint ID string to create an instance of the audio endpoint device at a later time or in a different process by calling the [IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice) method. Clients should treat the contents of the endpoint ID string as opaque. That is, clients should *not* attempt to parse the contents of the string to obtain information about the device. The reason is that the string format is undefined and might change from one implementation of the MMDevice API system module to the next.

For code examples that call the **GetId** method, see the following topics:

* [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties)
* [Device Roles for Legacy Windows Multimedia Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-for-legacy-windows-multimedia-applications)

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice)