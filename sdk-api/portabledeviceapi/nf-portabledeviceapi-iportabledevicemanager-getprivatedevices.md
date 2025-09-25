# IPortableDeviceManager::GetPrivateDevices

## Description

The **GetPrivateDevices** method retrieves a list of private portable devices connected to the computer. These private devices are only accessible through an application that is designed for these particular devices.

## Parameters

### `pPnPDeviceIDs` [in, out]

A caller-allocated array of string pointers that holds the Plug and Play names of all of the connected devices. To learn the required size for this parameter, first call this method with this parameter set to **NULL** and *pcPnPDeviceIDs* set to zero, and then allocate a buffer according to the value retrieved by *pcPnPDeviceIDs*. These names can be used by [IPortableDevice::Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-open) to create a connection to a device.

### `pcPnPDeviceIDs` [in, out]

On input, the number of values that *pPnPDeviceIDs* can hold. On output, a pointer to the number of devices actually written to *pPnPDeviceIDs*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |
| **S_FALSE** | The *pPnPDeviceIDs* buffer is too small to hold all the values requested, but *pcPnPDeviceIDs* values have been written to *pPnPDeviceIDs*. |

## Remarks

In order to write an application that communicates with a private device, you must have knowledge of the custom functionality exposed by a particular device driver. The description of this functionality must be obtained from the device manufacturer.

The list of devices is generated when the device manager is instantiated; it does not refresh as devices connect and disconnect. To refresh the list of connected devices, call [RefreshDeviceList](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-refreshdevicelist).

The API allocates the memory for each string pointed to by the *pPnPDeviceIDs* array. Once your application no longer needs these strings, it must iterate through this array and free the associated memory by calling the **CoTaskMemFree** function.

A private device may not respond correctly to the standard Windows Portable Devices function calls that perform object enumeration, resource transfer, retrieval of device capabilities, and so on.

## See also

[IPortableDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicemanager)