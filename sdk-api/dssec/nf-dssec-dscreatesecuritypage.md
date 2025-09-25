# DSCreateSecurityPage function

## Description

The **DSCreateSecurityPage** function creates a security property page for an Active Directory object. The resulting property page can be added to a property sheet.

## Parameters

### `pwszObjectPath` [in]

A pointer to a **null**-terminated wide character string that represents the full Active Directory path for the object.

### `pwszObjectClass` [in, optional]

A pointer to a **null**-terminated wide character string that represents the object class. This value can be **NULL**.

### `dwFlags` [in]

Flags used for the security property page. This parameter can be none or any combination of the following flags.

| Value | Meaning |
| --- | --- |
| **DSSI_READ_ONLY**<br><br>0x00000001 | The security properties are read-only. |
| **DSSI_NO_ACCESS_CHECK**<br><br>0x00000002 | No access check is performed. |
| **DSSI_NO_EDIT_SACL**<br><br>0x00000004 | The [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) property is read-only. |
| **DSSI_NO_EDIT_OWNER**<br><br>0x00000008 | The object owner property is read-only. |
| **DSSI_IS_ROOT**<br><br>0x00000010 | The object is a root object. |
| **DSSI_NO_FILTER**<br><br>0x00000020 | Do not apply any filters. |
| **DSSI_NO_READONLY_MESSAGE**<br><br>0x00000040 | Suppress read-only popup messages. |

### `phPage` [out]

A pointer to a **HPROPSHEETPAGE** that returns the created security property page.

### `pfnReadSD` [in, optional]

A pointer to a function used to read the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the object. This value can be **NULL**. If *pfnReadSD* is not **NULL**, **DSCreateSecurityPage** calls the function referenced by *pfnReadSD* to retrieve the security descriptor of the object.

### `pfnWriteSD` [in, optional]

A pointer to a function used to write the security descriptor of the object. This value can be **NULL**. If *pfnWriteSD* is not **NULL**, **DSCreateSecurityPage** calls the function referenced by *pfnWriteSD* to write the security descriptor of the object.

### `lpContext` [in]

Context to pass to the functions identified by *pfnReadSD* or *pfnWriteSD*.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The function pointed to by *pfnReadSD* is defined as follows.

```cpp
#include <windows.h>

typedef HRESULT (WINAPI *PFNREADOBJECTSECURITY)(
    LPCWSTR,               // Active Directory path of object
    SECURITY_INFORMATION,  // the security information to read
    PSECURITY_DESCRIPTOR*, // the returned security descriptor
    LPARAM                 // context parameter
);

```

The **DSCreateSecurityPage** function will free the security descriptor returned in the third parameter above by a call to the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

The function pointed to by *pfnWriteSD* is defined as follows.

```cpp
#include <windows.h>

typedef HRESULT (WINAPI *PFNWRITEOBJECTSECURITY)(
    LPCWSTR,              // Active Directory path of object
    SECURITY_INFORMATION, // the security information to write
    PSECURITY_DESCRIPTOR, // the security descriptor to write
    LPARAM                // context parameter
);

```

## See also

[Basic Security Property Page](https://learn.microsoft.com/windows/desktop/SecAuthZ/basic-security-property-page)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)