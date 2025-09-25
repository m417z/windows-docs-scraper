# IMDSPDevice::GetName

## Description

The **GetName** method retrieves the name of the device.

## Parameters

### `pwszName` [out]

Pointer to an array of 16-bit Unicode characters that receives the device name string.

### `nMaxChars` [in]

Maximum number of characters to copy to the string.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **LPWSTR** string type is a 16-bit Unicode character string and does not accept byte-sized characters. To convert a string of byte-sized characters (**LPCSTR**) to an **LPWSTR** string, use the **MultiByteToWideChar** function as described in Microsoft Windows documentation.

Device names must not contain trailing spaces.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)

[IMDSPDevice::GetType](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-gettype)