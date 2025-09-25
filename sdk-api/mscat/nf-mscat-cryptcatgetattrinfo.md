# CryptCATGetAttrInfo function

## Description

[The **CryptCATGetAttrInfo** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATGetAttrInfo** function retrieves information about an attribute of a member of a catalog.

## Parameters

### `hCatalog` [in]

The handle of the catalog that contains the member to retrieve the attribute information for. This handle is obtained by calling the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) function. This parameter is required and cannot be **NULL**.

### `pCatMember` [in]

A pointer to a [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that represents the member to retrieve the attribute information for. This can be obtained by calling the [CryptCATGetMemberInfo](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatgetmemberinfo) function. This parameter is required and cannot be **NULL**.

### `pwszReferenceTag` [in]

A pointer to a null-terminated Unicode string that contains the name of the attribute to retrieve the information for. This parameter is required and cannot be **NULL**.

## Return value

This function returns a pointer to a [CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute) structure that contains the attribute information. If the function fails, it returns **NULL**.

**Important** Do not free the returned pointer nor any of the members pointed to by the returned pointer.

If this function returns **NULL**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | The member or the attribute could not be found. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |

## See also

[CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute)

[CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember)

[CryptCATGetMemberInfo](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatgetmemberinfo)

[CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen)