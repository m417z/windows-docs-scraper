# IWMDMDevice::GetManufacturer

## Description

The **GetManufacturer** method retrieves the name of the manufacturer of the device.

## Parameters

### `pwszName` [out]

Pointer to a wide-character, null-terminated string specifying the manufacturer's name. The buffer must be allocated and released by the caller.

### `nMaxChars` [in]

Integer specifying the maximum number of characters that can be copied to *pwszName*, including the termination character.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)