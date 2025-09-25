# IMDSPEnumDevice::Skip

## Description

The **Skip** method skips over the next specified number of media device interface(s) in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements to skip.

### `pceltFetched` [out]

Pointer to the number of elements that actually were skipped.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the number specified in the *celt* parameter is greater than the actual number of interfaces remaining in the enumeration sequence, then the return value from **Skip** is S_FALSE. When this happens, the *pceltFetched* parameter must be queried to determine how many interfaces were skipped. If you skip to the end of the array of enumerated media device interfaces, a subsequent call to **Next** returns S_FALSE.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumdevice)