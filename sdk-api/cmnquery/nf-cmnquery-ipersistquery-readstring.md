# IPersistQuery::ReadString

## Description

The **IPersistQuery::ReadString** method reads a string from the query store.

## Parameters

### `pSection` [in]

Pointer to a null-terminated Unicode string that represents the section name that the string should be read from.

### `pValueName` [in]

Pointer to a null-terminated Unicode string that represents the name of the string value to be read.

### `pBuffer` [out]

Pointer to a character buffer that receives the string value. The *cchBuffer* parameter specifies the size of this buffer including the null terminator.

### `cchBuffer` [in]

Contains the size, in characters, of the *pBuffer* buffer including the null terminator.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)