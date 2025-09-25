# IMDSPEnumDevice::Next

## Description

The **Next** method retrieves a pointer to the next *celt*[IMDSPDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice) interfaces.

## Parameters

### `celt` [in]

Number of devices requested.

### `ppDevice` [out]

Array of *celt* pointers [IMDSPDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice) allocated by the caller. Return **NULL** to indicate that no more devices exist or an error has occurred. If *celt* is more than 1, the caller must allocate enough memory to store *celt* number of interface pointers.

### `pceltFetched` [out]

Pointer to a **ULONG** variable that receives the number of interfaces retrieved.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

When there are no more service provider interfaces for enumerated devices, or when there are fewer of these interfaces than requested by the *celt* parameter, the return value from **Next** is S_FALSE. When this happens, the *pceltFetched* parameter must be queried to determine how many interfaces, if any, were returned.

The device enumerator may not reflect the effect of device insertion and removal.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)

[IMDSPEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumdevice)