# NCryptCloseProtectionDescriptor function

## Description

The **NCryptCloseProtectionDescriptor** function zeros and frees a protection descriptor object and releases its handle.

## Parameters

### `hDescriptor` [in]

Handle of a protection descriptor created by calling [NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor).

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_HANDLE** | The handle specified by the *hDescriptor* parameter cannot be **NULL** and it must represent a valid descriptor. |

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor)