# CredRenameW function

## Description

[**CredRename** is no longer supported. Starting with Windows Vista, calls to **CredRename** always return ERROR_NOT_SUPPORTED.]

The **CredRename** function renames a credential in the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `OldTargetName` [in]

Pointer to a null-terminated string that contains the current name of the credential to be renamed.

### `NewTargetName` [in]

Pointer to a null-terminated string that contains the new name for the credential.

### `Type` [in]

Type of the credential to rename. Must be one of the CRED_TYPE_* defines.

### `Flags` [in]

Flags to control the operation of the function. Currently reserved and must be zero.

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status codes can be returned:

* ERROR_NOT_FOUND

  There is no credential with the specified *OldTargetName*.
* ERROR_ALREADY_EXISTS

  There is already a credential or type *Type* and named *NewTargetName*.
* ERROR_NO_SUCH_LOGON_SESSION

  The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set.
* ERROR_INVALID_FLAGS

  A flag that is not valid was specified for the *Flags* parameter.

## Remarks

> [!NOTE]
> The wincred.h header defines CredRename as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).