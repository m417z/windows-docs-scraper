# IMDSPStorage::GetName

## Description

The **GetName** method retrieves the display name of the storage object.

## Parameters

### `pwszName` [out]

Pointer to a (Unicode) wide-character null-terminated string containing the object name.

### `nMaxChars` [in]

Integer containing the maximum number of characters that can be copied to the name string.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The display name of the object is the file name without path information. In hierarchical media the display name would be concatenated with the ancestor instances of **IMDSPStorage** interfaces to create a full path-qualified name.

The **LPWSTR** string type is a 16-bit Unicode character string and does not accept byte-sized characters.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage::GetDate](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getdate)

[IMDSPStorage::GetSize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getsize)