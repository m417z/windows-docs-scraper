# CredFindBestCredentialA function

## Description

The **CredFindBestCredential** function searches the [Credentials Management](https://learn.microsoft.com/windows/desktop/SecAuthN/credentials-management) (CredMan) database for the set of generic credentials that are associated with the current logon session and that best match the specified target resource.

## Parameters

### `TargetName` [in]

A pointer to a null-terminated string that contains the name of the target resource for which to find credentials.

### `Type` [in]

The type of credentials to search for. Currently, this function supports only **CRED_TYPE_GENERIC**.

### `Flags` [in]

Reserved.

### `Credential` [out]

The address of a pointer to a [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure that specifies the set of credentials this function finds.

When you have finished using this structure, free it by calling the [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!NOTE]
> The wincred.h header defines CredFindBestCredential as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).