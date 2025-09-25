# IEffectivePermission::GetEffectivePermission

## Description

The **GetEffectivePermission** method returns the effective permission for an object type.

## Parameters

### `pguidObjectType` [in]

A **GUID** for the object type whose permission is being queried.

### `pUserSid` [in]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the security principal whose effective permission is being determined.

### `pszServerName` [in]

A pointer to null-terminated wide character string that represents the server name.

### `pSD` [in]

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that represents the object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The security descriptor is used to perform the access check.

### `ppObjectTypeList` [out]

A pointer to a pointer to an [OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structure that represents the array of object types in the object tree for the object. If an object does not support property access, use the following technique to specify the value for the **OBJECT_TYPE_LIST**.

```cpp
#include <windows.h>

OBJECT_TYPE_LIST g_DefaultOTL[] = {
 {0, 0, (LPGUID)&GUID_NULL},
};

```

### `pcObjectTypeListLength` [out]

A pointer to a **ULONG** that receives the count of object types pointed to by *ppObjectTypeList*.

### `ppGrantedAccessList` [out]

A pointer to a pointer to an [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that receives the array of granted access masks. The operating system will use [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to free the memory allocated for this parameter.

### `pcGrantedAccessListLength` [out]

A pointer to a **ULONG** variable that receives the count of granted access masks pointed to by the *ppGrantedAccessList* parameter.

## Return value

If the function is successful, the return value is S_OK.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).