# IWMDeviceManager::GetDeviceCount

## Description

The **GetDeviceCount** method retrieves the number of portable devices that are currently connected to the computer.

## Parameters

### `pdwCount` [out]

Pointer to a **DWORD** specifying the count of known devices.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager)