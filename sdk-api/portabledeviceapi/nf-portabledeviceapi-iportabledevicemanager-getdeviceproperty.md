# IPortableDeviceManager::GetDeviceProperty

## Description

Retrieves a property value stored by the device on the computer. (These are not standard properties that are defined by Windows Portable Devices.)

## Parameters

### `pszPnPDeviceID` [in]

Pointer to a null-terminated string that contains the device's Plug and Play ID. You can retrieve a list of Plug and Play names of all devices that are connected to the computer by calling [GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices).

### `pszDevicePropertyName` [in]

Pointer to a null-terminated string that contains the name of the property to request. These are custom property names defined by a device manufacturer.

### `pData` [in, out]

A caller-allocated buffer to hold the retrieved data. To get the size required, call this method with this parameter set to **NULL** and *pcbData* set to zero, and the required size will be retrieved in *pcbData*. This call will also return an error that can be ignored. See Return Values.

### `pcbData` [in, out]

The size of the buffer allocated or returned by *pData*, in bytes.

### `pdwType` [in, out]

A constant describing the type of data returned in *pData*. The values for this parameter are the same types used to describe the *lpType* parameter of the Platform SDK function **RegQueryValueEx**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The supplied buffer is not large enough to hold the requested data. (This result is always returned when *pData* is **NULL**. You can ignore this result if you are calling the method to retrieve the required buffer size. See the description of the *pData* parameter.) |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

These property values are stored on device installation, or stored by a device during operation so that they can be persisted across connection sessions. An application must know the exact name of the property, which is specified by the device itself; therefore, this method is intended to be used by device developers who are creating their own applications.

To get Windows Portable Devices properties from the device object, call [IPortableDeviceProperties::GetValues](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getvalues), and specify the device object with **WPD_DEVICE_OBJECT_ID**.

## See also

[IPortableDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicemanager)

[IPortableDeviceManager::GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices)