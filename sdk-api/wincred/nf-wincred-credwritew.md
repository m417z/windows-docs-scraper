# CredWriteW function

## Description

The **CredWrite** function creates a new credential or modifies an existing credential in the user's credential set. The new credential is associated with the logon session of the current token. The token must not have the user's [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) disabled.

## Parameters

### `Credential` [in]

A pointer to the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure to be written.

### `Flags` [in]

Flags that control the function's operation. The following flag is defined.

| Value | Meaning |
| --- | --- |
| **CRED_PRESERVE_CREDENTIAL_BLOB** | The credential BLOB from an existing credential is preserved with the same credential name and credential type. The **CredentialBlobSize** of the passed in *Credential* structure must be zero. |

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get a more specific status code. The following status codes can be returned.

Other smart card errors can be returned when writing a CRED_TYPE_CERTIFICATE credential.

| Return code/value | Description |
| --- | --- |
| **ERROR_NO_SUCH_LOGON_SESSION** | The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set. |
| **ERROR_INVALID_PARAMETER** | Certain fields cannot be changed in an existing credential. This error is returned if a field does not match the value in a protected field of the existing credential. |
| **ERROR_INVALID_FLAGS** | A value that is not valid was specified for the *Flags* parameter. |
| **ERROR_BAD_USERNAME** | The **UserName** member of the passed in *Credential* structure is not valid. For a description of valid user name syntax, see the definition of that member. |
| **ERROR_NOT_FOUND** | CRED_PRESERVE_CREDENTIAL_BLOB was specified and there is no existing credential by the same **TargetName** and **Type**. |
| **SCARD_E_NO_READERS_AVAILABLE** | The CRED_TYPE_CERTIFICATE credential being written requires the smart card reader to be available. |
| **SCARD_E_NO_SMARTCARD or SCARD_W_REMOVED_CARD** | A CRED_TYPE_CERTIFICATE credential being written requires the smart card to be inserted. |
| **SCARD_W_WRONG_CHV** | The wrong PIN was supplied for the CRED_TYPE_CERTIFICATE credential being written. |

## Remarks

This function creates a credential if a credential with the specified **TargetName** and **Type** does not exist. If a credential with the specified **TargetName** and **Type** exists, the new specified credential replaces the existing one.

When this function writes a CRED_TYPE_CERTIFICATE credential, the *Credential*->**CredentialBlob** member specifies the PIN protecting the private key of the certificate specified by the *Credential*->**UserName** member. The credential manager does not maintain the PIN. Rather, the PIN is passed to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) indicated on the certificate for later use by the CSP and the authentication packages. The CSP defines the lifetime of the PIN. Most CSPs flush the PIN when the smart card removal from the smart card reader.

If the value of the **Type** member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure specified by the *Credential* parameter is **CRED_TYPE_DOMAIN_EXTENDED**, a namespace must be specified in the target name. This function does not support writing to target names that contain wildcards.

> [!NOTE]
> The wincred.h header defines CredWrite as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala)