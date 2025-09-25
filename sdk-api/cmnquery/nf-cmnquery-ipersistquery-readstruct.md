# IPersistQuery::ReadStruct

## Description

The **IPersistQuery::ReadStruct** method reads a structure from the query store.

## Parameters

### `pSection` [in]

Pointer to a null-terminated Unicode string that represents the section name that the structure should be read from.

### `pValueName` [in]

Pointer to a null-terminated Unicode string that represents the name of the structure value to be read.

### `pStruct` [out]

Pointer to a buffer that will receive the structure. The *cbStruct* parameter specifies the size of this buffer, in bytes.

### `cbStruct` [in]

Specifies the size, in bytes, of the buffer represented by the *pStruct* parameter.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** value otherwise. Possible error codes include the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)