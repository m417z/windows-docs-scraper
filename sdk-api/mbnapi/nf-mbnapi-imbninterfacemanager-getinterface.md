# IMbnInterfaceManager::GetInterface

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a specific interface.

## Parameters

### `interfaceID` [in]

A string that contains the ID of the interface to retrieve.

### `mbnInterface` [out, retval]

Pointer to the address of the [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) specified by *interfaceID* or **NULL** if there is no matching interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | There is no available interface matching the specified interface ID. |
| **E_POINTER** | The *mbnInterface* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Could not allocate the required memory. |

## See also

[IMbnInterfaceManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfacemanager)