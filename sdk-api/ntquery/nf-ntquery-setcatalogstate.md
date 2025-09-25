# SetCatalogState function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Sets the catalog state for backup or other purposes.

## Parameters

### `pwcsCat`

A pointer to the name of the catalog, for example, L"system" or L"Web".

### `pwcsMachine`

A pointer to the name of the computer where the catalog exists; for example, L"." for the local computer.

### `dwNewState`

The state of the catalog. See [CICAT_* Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/cicat-constants).

### `pdwOldState`

A pointer to a value that receives one of the CICAT_* constants that reflects the current state of the catalog.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **CI_E_NOT_FOUND** | The function failed because either the catalog or the computer was not found. |
| **CI_E_NOT_RUNNING** | The function failed because Indexing Service is not running. |
| **CI_E_TIMEOUT** | The function failed because Indexing Service is too busy. |

## Remarks

A catalog can be read-only if any of the following conditions exist:

* The value of the **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ContentIndex\Catalogs\<catalog name>\IsReadOnly** registry entry is set to 1.
* The catalog is on a write-protected volume.
* The catalog, specifically the file cicat.hsh, is read-only.

If any of the preceding conditions exist and the CICAT_WRITABLE bit is set, it does not have the desired effect and the catalog is opened read-only.

If the *dwNewState* parameter contains CICAT_NO_QUERY, the system checks to see whether the catalog can be set to a writable state. If any of the preceding conditions exist that prevent the catalog from being writable, the catalog remains read-only and the *pdwOldState* parameter returns CICAT_READONLY. However, because the intention of the flag is to halt querying, the catalog stops accepting queries even though it is in this read-only state.

Specifically, if you make the call:

`SetCatalogState("System", ".", CICAT_NO_QUERY, &OldState);`

the value of the *pdwOldState* parameter on return will contain CICAT_NO_QUERY in addition to CI_CAT_WRITABLE or CI_CAT_READONLY values, depending on the READONLY/WRITABLE attributes of the volume or file.

If you make the call to **SetCatalogState**, where the *dwNewState* parameter is any value other than CICAT_NO_QUERY, then the value of the **pdwOldState* parameter on return will contain one of the mutually exclusive CICAT_* constants (excluding CICAT_NO_QUERY and CICAT_GET_STATE) which reflects the current state of the catalog.

**Note** If you issue a **net pause** command or a **net continue** command for Indexing Service, the state changes that were set by the **SetCatalogState** function are not preserved.

For examples of changes in a catalog's state, see the ChgState sample in the Platform SDK directory mssdk\samples\winbase\indexing\chgstate.

## See also

[LocateCatalogs](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/locating-the-catalog-for-the-selected-scope)