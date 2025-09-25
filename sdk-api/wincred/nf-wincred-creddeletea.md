# CredDeleteA function

## Description

The **CredDelete** function deletes a credential from the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `TargetName` [in]

Pointer to a null-terminated string that contains the name of the credential to delete.

### `Type` [in]

Type of the credential to delete. Must be one of the CRED_TYPE_* defined types. For a list of the defined types, see the **Type** member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure.

If the value of this parameter is **CRED_TYPE_DOMAIN_EXTENDED**, this function can delete a credential that specifies a user name when there are multiple credentials for the same target. The value of the *TargetName* parameter must specify the user name as *Target***|***UserName*.

### `Flags` [in]

Reserved and must be zero.

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status codes can be returned:

* ERROR_NOT_FOUND

  There is no credential with the specified *TargetName*.
* ERROR_NO_SUCH_LOGON_SESSION

  The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set.
* ERROR_INVALID_FLAGS

  A flag that is not valid was specified for the *Flags* parameter.

## Remarks

> [!NOTE]
> The wincred.h header defines CredDelete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).