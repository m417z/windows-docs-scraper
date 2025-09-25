# RegOpenUserClassesRoot function

## Description

Retrieves a handle to the **HKEY_CLASSES_ROOT** key for a specified user. The user is identified by an access token. The returned key has a view of the registry that merges the contents of the **HKEY_LOCAL_MACHINE**\Software\Classes key with the contents of the Software\Classes keys in the user's registry hive. For more information, see
[HKEY_CLASSES_ROOT Key](https://learn.microsoft.com/windows/desktop/SysInfo/hkey-classes-root-key).

## Parameters

### `hToken` [in]

A handle to a primary or impersonation access token that identifies the user of interest. This can be a token handle returned by a call to
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera),
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken),
[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken),
[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex),
[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or
[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) functions.

The handle must have TOKEN_QUERY access. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `dwOptions`

This parameter is reserved and must be zero.

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

The
**RegOpenUserClassesRoot** function enables you to retrieve the merged **HKEY_CLASSES_ROOT** information for users other than the interactive user. For example, the server component of a client/server application could use
**RegOpenUserClassesRoot** to retrieve the merged information for a client.

**RegOpenUserClassesRoot** fails if the user profile for the specified user is not loaded. When a user logs on interactively, the system automatically loads the user's profile. For other users, you can call the
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function to load the user's profile. However, **LoadUserProfile** can be very time-consuming, so do not call it for this purpose unless it is absolutely necessary to have the user's merged **HKEY_CLASSES_ROOT** information.

Applications running in the security context of the interactively logged-on user do not need to use
**RegOpenUserClassesRoot**. These applications can call the
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function to retrieve a merged view of the **HKEY_CLASSES_ROOT** key for the interactive user.

## See also

[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea)

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)