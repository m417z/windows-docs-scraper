# CredReadA function

## Description

The **CredRead** function reads a credential from the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `TargetName` [in]

Pointer to a null-terminated string that contains the name of the credential to read.

### `Type` [in]

Type of the credential to read. *Type* must be one of the CRED_TYPE_* defined types.

### `Flags` [in]

Currently reserved and must be zero.

### `Credential` [out]

Pointer to a single allocated block buffer to return the credential.
Any pointers contained within the buffer are pointers to locations within this single allocated block. The single returned buffer must be freed by calling [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status codes can be returned:

* ERROR_NOT_FOUND

  No credential exists with the specified *TargetName*.
* ERROR_NO_SUCH_LOGON_SESSION

  The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set.
* ERROR_INVALID_FLAGS

  A flag that is not valid was specified for the *Flags* parameter.

## Remarks

If the value of the **Type** member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure specified by the *Credential* parameter is **CRED_TYPE_DOMAIN_EXTENDED**, a namespace must be specified in the target name. This function can return only one credential of the specified type.

> [!NOTE]
> The wincred.h header defines CredRead as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).