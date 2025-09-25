# IMDSPDevice::GetDeviceIcon

## Description

The **GetDeviceIcon** method returns a **HICON** that represents the icon that the device service provider indicates must be used to represent this device.

## Parameters

### `hIcon` [out]

Handle to an **Icon** object that receives the icon for the device. Before using it, the caller must cast the value to a **HICON***. When an application is finished with the icon, it should call **DestroyIcon** to free the resource. **DestroyIcon** is a standard Win32 function.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

In addition to the values above, the **HRESULT** error code could be a Win32 error.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)