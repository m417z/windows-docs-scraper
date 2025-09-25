# IPortableDeviceManager::GetDeviceManufacturer

## Description

Retrieves the name of the device manufacturer.

## Parameters

### `pszPnPDeviceID` [in]

Pointer to a null-terminated string that contains the device's Plug and Play ID. You can retrieve a list of Plug and Play names of all devices that are connected to the computer by calling [GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices).

### `pDeviceManufacturer` [in, out]

A caller-allocated buffer that holds the name of the device manufacturer. To learn the required size for this parameter, first call this method with this parameter set to **NULL** and *pcchDeviceManufacturer* set to **0**; the method will succeed and set *pcchDeviceManufacturer* to the required buffer size to hold the device-friendly name, including the termination character.

### `pcchDeviceManufacturer` [in, out]

On input, the maximum number of characters that *pDeviceManufacturer* can hold, not including the termination character. On output, the number of characters returned by *pDeviceManufacturer*, not including the termination character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The supplied buffer is not large enough to hold the device description. (Refer to the value returned in *pcchDeviceDescription* for the required size.) |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | The device description could not be found. |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## See also

[IPortableDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicemanager)

[IPortableDeviceManager::GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices)