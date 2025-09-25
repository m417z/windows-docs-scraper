# IWMDMDevice::GetName

## Description

The **GetName** method retrieves the human-readable name of the media device.

## Parameters

### `pwszName` [out]

Pointer to a (Unicode) wide-character, null-terminated string specifying the device name. The buffer is allocated and released by the caller.

### `nMaxChars` [in]

Integer specifying the maximum number of characters that can be placed in *pwszName*, including the termination character.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)

[IWMDMDevice::GetType](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-gettype)