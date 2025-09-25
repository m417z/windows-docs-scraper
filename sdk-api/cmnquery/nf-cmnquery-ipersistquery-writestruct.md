# IPersistQuery::WriteStruct

## Description

The **IPersistQuery::WriteStruct** method writes a structure to the query store.

## Parameters

### `pSection` [in]

Pointer to a null-terminated Unicode string that represents the section name that the structure should be written to.

### `pValueName` [in]

Pointer to a null-terminated Unicode string that represents the name of the structure.

### `pStruct` [in]

Pointer to the structure to be written. The *cbStruct* parameter contains the number of bytes to be written.

### `cbStruct` [in]

Contains the size, in bytes, of the structure to be written.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)