# IMbnDeviceServicesManager::GetDeviceServicesContext

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the [IMbnDeviceServicesContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicescontext) interface for a specific Mobile Broadband device

## Parameters

### `networkInterfaceID` [in]

A string that contains the ID of the Mobile Broadband device. The ID can be obtained using the [InterfaceID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-get_interfaceid) property

### `mbnDevicesContext` [out, retval]

Pointer to the address of the [IMbnDeviceServicesContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicescontext) for the device specified by *networkInterfaceID* or **NULL** if there is no matching interface.

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | There is no available device matching the specified interface ID. |
| **E_POINTER** | The *mbnDeviceServicesContext* parameter is NULL. |
| **E_OUTOFMEMORY** | Could not allocate the required memory. |

## See also

[IMbnDeviceServicesManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesmanager)