# IMDServiceProvider::GetDeviceCount

## Description

The **GetDeviceCount** method returns the number of installed physical or software devices that are currently attached and are known by the service provider.

## Parameters

### `pdwCount` [out]

Pointer to a **DWORD** containing the count of known devices.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The service provider should return only the number of supported devices that are currently attached to the computer.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDServiceProvider Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider)