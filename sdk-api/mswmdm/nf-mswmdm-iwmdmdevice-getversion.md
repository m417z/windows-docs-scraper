# IWMDMDevice::GetVersion

## Description

The **GetVersion** method retrieves the manufacturer-defined version number of the device.

## Parameters

### `pdwVersion` [out]

Pointer to a **DWORD** specifying the version number.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The format of the version number is determined by the manufacturer.

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)