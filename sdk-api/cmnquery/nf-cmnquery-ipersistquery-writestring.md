# IPersistQuery::WriteString

## Description

The **IPersistQuery::WriteString** method writes a string to the query store.

## Parameters

### `pSection` [in]

Pointer to a null-terminated Unicode string that represents the section name that the string should be written to.

### `pValueName` [in]

Pointer to a null-terminated Unicode string that represents the name of the string value.

### `pValue` [in]

Pointer to a null-terminated Unicode string that contains the string to be written.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)