# IWMDMDevice::GetDeviceIcon

## Description

The **GetDeviceIcon** method retrieves a handle to the icon that the device manufacturer wants to display when the device is connected.

## Parameters

### `hIcon` [out]

Handle to an icon object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

When the application is finished with the icon, it must call the Win32 **DestroyIcon** function to free the memory.

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)