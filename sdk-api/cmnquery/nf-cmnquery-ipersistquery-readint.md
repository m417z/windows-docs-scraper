# IPersistQuery::ReadInt

## Description

The **IPersistQuery::ReadInt** method reads an integer value from the query store.

## Parameters

### `pSection` [in]

A pointer to a null-terminated Unicode string that represents the section name that the integer should be read from.

### `pValueName` [in]

A pointer to a null-terminated Unicode string that represents the name of the integer value to be read.

### `pValue` [out]

Pointer to an integer variable that receives the integer value.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)