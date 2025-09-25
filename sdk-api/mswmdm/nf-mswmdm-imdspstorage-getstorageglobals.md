# IMDSPStorage::GetStorageGlobals

## Description

The **GetStorageGlobals** method retrieves the **IMDSPStorageGlobals** interface to provide access to global information about a storage medium.

## Parameters

### `ppStorageGlobals` [out]

Pointer to an **IMDSPStorageGlobals** interface that can provide access to global information about a storage medium.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IMDSPStorageGlobals** interface provides methods for accessing global information about the medium regardless of the nesting level of the **IMDSPStorage** interface from which the global view is accessed. Any instance of **IMDSPStorage** can acquire an **IMDSPStorageGlobals** interface.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)