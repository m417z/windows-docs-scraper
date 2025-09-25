# CoGetSystemSecurityPermissions function

## Description

Returns the default values of the Security Descriptors of the machine-wide launch and access permissions, as well as launch and access limits.

## Parameters

### `comSDType` [in]

A value from the [COMSD](https://learn.microsoft.com/windows/desktop/api/objbase/ne-objbase-comsd) enumeration. Specifies the type of the requested system security permissions, such as launch permissions, access permissions, launch restrictions, and access restrictions.

### `ppSD` [out]

Pointer to a caller-supplied variable that this routine sets to the address of a buffer containing the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) for the system security permissions. Memory will be allocated by **CoGetSystemSecurityPermissions** and should be freed by caller with [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid parameter *comSDType* or *ppSD*. |
| **E_FAIL** | No connection to the resolver process. |
| **E_OUTOFMEMORY** | Not enough memory for the security descriptor's allocation. |

## See also

[COMSD](https://learn.microsoft.com/windows/desktop/api/objbase/ne-objbase-comsd)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)