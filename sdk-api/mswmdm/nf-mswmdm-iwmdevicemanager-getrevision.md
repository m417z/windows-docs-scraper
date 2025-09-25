# IWMDeviceManager::GetRevision

## Description

The **GetRevision** method retrieves the version number of Windows Media Device Manager currently in use.

## Parameters

### `pdwRevision` [out]

Pointer to a **DWORD** specifying the Windows Media Device Manager version number. Windows Media Device Manager 10 returns 0x00080000.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager)