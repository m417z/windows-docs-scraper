# IPersistQuery::WriteInt

## Description

The **IPersistQuery::WriteInt** method writes an integer value to the query store.

## Parameters

### `pSection` [in]

Pointer to a null-terminated Unicode string that represents the section name that the integer should be written to.

### `pValueName` [in]

Pointer to a null-terminated Unicode string that represents the name of the integer value.

### `value` [in]

Contains the integer value to be written to the query store.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)