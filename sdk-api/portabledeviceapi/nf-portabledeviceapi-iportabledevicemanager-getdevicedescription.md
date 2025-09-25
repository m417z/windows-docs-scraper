# IPortableDeviceManager::GetDeviceDescription

## Description

Retrieves the description of a device.

## Parameters

### `pszPnPDeviceID` [in]

Pointer to a null-terminated string that contains the device's Plug and Play ID. You can retrieve a list of Plug and Play names of devices that are currently connected by calling [GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices).

### `pDeviceDescription` [in, out]

A caller-allocated buffer to hold the user-description name of the device. The caller must allocate the memory for this parameter. To learn the required size for this parameter, first call this method with this parameter set to **NULL** and *pcchDeviceDescription* set to **0**; the method will succeed and set *pcchDeviceDescription* to the required buffer size to hold the device-friendly name, including the termination character.

### `pcchDeviceDescription` [in, out]

The number of characters (not including the termination character) in *pDeviceDescription*. On input, the maximum length of *pDeviceDescription*; on output, the length of the returned string in *pDeviceDescription*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The supplied buffer is not large enough to hold the device description. (Refer to the value returned in *pcchDeviceDescription* for the required size.) |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | The device description could not be found. |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## See also

[GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices)

[IPortableDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicemanager)