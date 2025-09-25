# IUrlAccessor::GetSecurityDescriptor

## Description

Gets the security descriptor for the URL item. Security is applied at query time, so this descriptor identifies security for read access.

## Parameters

### `pSD` [out]

Type: **BYTE***

Receives a pointer to the security descriptor.

### `dwSize` [in]

Type: **DWORD**

Size in **TCHAR****s** of the *pSD* array.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of **TCHAR****s** written to *pSD*, not including the terminating **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method allows custom mappings between users registered to a content source and those users registered on the domain, if they are different. Security descriptors created in this method must be self-relative.

If the URL contains a user security identifier (SID), then the protocol handler is invoked in the security context of that user, and this method must return E_NOTIMPL.

If the URL does not contain a user SID, then the protocol handler is invoked in the security context of the system service. In that case, this method can return either an access control list (ACL) to restrict read access, or [PRTH_S_ACL_IS_READ_EVERYONE](https://learn.microsoft.com/windows/desktop/search/-search-prth-error-constants) to allow anyone read access during querying.

**Note** If this method returns E_NOTIMPL and the URL does NOT contain a user SID, then the item is retrievable by all user queries.

## See also

[IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor)

[Search Protocol Handler Error Messages](https://learn.microsoft.com/windows/desktop/search/-search-prth-error-constants)