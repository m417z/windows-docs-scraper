# RegOpenCurrentUser function

## Description

Retrieves a handle to the **HKEY_CURRENT_USER** key for the user the current thread is impersonating.

## Parameters

### `samDesired` [in]

A mask that specifies the desired access rights to the key. The function fails if the security descriptor of the key does not permit the requested access for the calling process. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened key. When you no longer need the returned handle, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function to close it.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

The **HKEY_CURRENT_USER** key maps to the root of the current user's branch in the **HKEY_USERS** key. It is cached for all threads in a process. Therefore, this value does not change when another user's profile is loaded.
**RegOpenCurrentUser** uses the thread's token to access the appropriate key, or the default if the profile is not loaded.

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)