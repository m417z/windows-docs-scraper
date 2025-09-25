# IMDSPStorage4::GetParent

## Description

The **GetParent** method retrieves the parent of the current storage.

## Parameters

### `ppStorage` [out]

Pointer to the returned parent storage object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method can be used to traverse the complete hierarchy of the current storage if used recursively.

When this method is called for root storage, this method should return S_FALSE and set *ppStorage* to **NULL**.

## See also

[IMDSPStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage4)