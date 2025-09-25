# CredWriteDomainCredentialsA function

## Description

The **CredWriteDomainCredentials** function writes domain credentials to the user's credential set. The credential set used is the one associated with the logon session of the current token. The token must not have the user's SID disabled.

## Parameters

### `TargetInfo` [in]

Identifies the target server. At least one of the naming members must be non-**NULL** and can be **NetbiosServerName**, **DnsServerName**, **NetbiosDomainName**, **DnsDomainName**, or **DnsTreeName**.

### `Credential` [in]

Credential to be written.

The credential must be one that matches *TargetInfo* For instance, if the **TargetName** is a wildcard DNS name, then the **TargetName** member of the credential must be a postfix of the **DnsServerName** member from the *TargetInfo*.

### `Flags` [in]

Flags to control the operation of the API. The following flag is defined.

| Value | Meaning |
| --- | --- |
| **CRED_PRESERVE_CREDENTIAL_BLOB** | The credential BLOB should be preserved from the already existing credential with the same credential name and credential type. The **CredentialBlobSize** of the passed in *Credential* structure must be zero. |

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get a more specific status code. The following status codes can be returned.

Other smart card errors can be returned when writing a CRED_TYPE_CERTIFICATE credential.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. Either none of the naming parameters were specified, or the credential specified did not have the **Type** member set to CRED_TYPE_DOMAIN_PASSWORD or CRED_TYPE_DOMAIN_CERTIFICATE, or the *Credential* does not match the *TargetInfo*. |
| **ERROR_NO_SUCH_LOGON_SESSION** | The logon session does not exist or there is no credential set associated with this logon session. Network logon sessions do not have an associated credential set. |
| **ERROR_INVALID_FLAGS** | A value that is not valid was specified for the *Flags* parameter. |
| **ERROR_BAD_USERNAME** | The **UserName** member of the passed in *Credential* structure is not valid. For a description of valid syntaxes, see the definition of that member. |
| **ERROR_NOT_FOUND** | CRED_PRESERVE_CREDENTIAL_BLOB was specified and there is no existing credential by the same **TargetName** and **Type**. |
| **SCARD_E_NO_READERS_AVAILABLE** | The CRED_TYPE_CERTIFICATE credential being written requires the smart card reader to be available. |
| **SCARD_E_NO_SMARTCARD or SCARD_W_REMOVED_CARD: The CRED_TYPE_CERTIFICATE** | The credential being written requires the smart card to be inserted. |
| **SCARD_W_WRONG_CHV** | The wrong PIN was supplied for the CRED_TYPE_CERTIFICATE credential being written. |

## Remarks

When this function writes a CRED_TYPE_CERTIFICATE credential, the *Credential*->**CredentialBlob** member specifies the PIN that protects the private key of the certificate specified by the *Credential*->**UserName**. The credential manager does not maintain the PIN. Rather, the PIN is passed to the CSP of the certificate for later use by the CSP and authentication packages. The CSP defines the lifetime of the PIN. For instance, most CSPs flush the PIN upon smart card removal.

**CredWriteDomainCredentials** differs from [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) in that it handles the idiosyncrasies of domain (CRED_TYPE_DOMAIN_PASSWORD or CRED_TYPE_DOMAIN_CERTIFICATE) credentials. Domain credentials contain more than one target member.

If the value of the **Type** member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure specified by the *Credential* parameter is **CRED_TYPE_DOMAIN_EXTENDED**, a namespace must be specified in the target name.

> [!NOTE]
> The wincred.h header defines CredWriteDomainCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).