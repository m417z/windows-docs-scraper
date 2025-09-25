# IDeviceTopology::GetDeviceId

## Description

The **GetDeviceId** method gets the device identifier of the device that is represented by the device-topology object.

## Parameters

### `ppwstrDeviceId` [out]

Pointer to a pointer variable into which the method writes the address of a null-terminated, wide-character string that contains the device identifier. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetDeviceId** call fails, **ppwstrDeviceId* is **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **D_POINTER** | Pointer *ppwstrDeviceId* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

The device identifier obtained from this method can be used as an input parameter to the [IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice) method.

For a code example that uses the **GetDeviceId** method, see [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties).

## See also

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice)