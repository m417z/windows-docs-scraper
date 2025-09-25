# CredGetSessionTypes function

## Description

The **CredGetSessionTypes** function returns the maximum persistence supported by the current logon session. A separate maximum persistence is returned for each credential type.

## Parameters

### `MaximumPersistCount` [in]

Number of elements in the *MaximumPersist* array. Use CRED_TYPE_MAXIMUM to return all of the currently defined credential types.

### `MaximumPersist` [out]

Pointer to an array to return the persistence values in. The passed in array should be *MaximumPersistCount* elements long. On return, each element specifies the maximum persistence supported by the corresponding credential type.

The caller should use one of the following defines to index into the array:

* CRED_TYPE_GENERIC
* CRED_TYPE_DOMAIN_PASSWORD
* CRED_TYPE_DOMAIN_CERTIFICATE

That is, *MaximumPersist*[CRED_TYPE_GENERIC] specifies the maximum persistence supported for generic credentials.

The following values can be returned in each element of the array.

| Value | Meaning |
| --- | --- |
| **CRED_PERSIST_NONE** | No credential can be stored. This value will be returned if the credential type is not supported or has been disabled by policy. |
| **CRED_PERSIST_SESSION** | Only a session-specific credential can be stored. |
| **CRED_PERSIST_LOCAL_MACHINE** | Session-specific and computer-specific credentials can be stored.<br><br>**Windows XP:** This credential cannot be stored for sessions in which the profile is not loaded. |
| **CRED_PERSIST_ENTERPRISE** | Any credential can be stored.<br><br>**Windows XP:** This credential cannot be stored for sessions in which the profile is not loaded. |

## Return value

This function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status code can be returned:

ERROR_NO_SUCH_LOGON_SESSION

The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set.