# RKeyPFXInstall function

The **RKeyPFXInstall** function is not supported.

**Windows Server 2003:** The **RKeyPFXInstall** function installs a certificate on a remote computer. Note that this behavior has changed with Windows Server 2003 with Service Pack 1 (SP1).

## Parameters

*hKeySvcCli* \[in\]

A [**KEYSVCC\_HANDLE**](https://learn.microsoft.com/windows/win32/seccrypto/keysvcc-handle) handle previously opened by [**RKeyOpenKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyopenkeyservice). The handle represents the remote computer that will receive the certificate. This value cannot be **NULL**.

*pPFX* \[in\]

A pointer to a [**KEYSVC\_BLOB**](https://learn.microsoft.com/windows/win32/seccrypto/keysvc-blob) structure that represents the certificate to install. The BLOB is in [*PKCS \#12*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) format.

*pPassword* \[in\]

A pointer to a [**KEYSVC\_UNICODE\_STRING**](https://learn.microsoft.com/windows/win32/seccrypto/keysvc-unicode-string) structure that represents the password for the BLOB. When you have finished using the password, clear the password from memory by calling the [**SecureZeroMemory**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/win32/secbp/handling-passwords).

*ulFlags* \[in\]

Flags that specify the certificate installation options. This parameter can be a zero or a combination of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| **CRYPT\_EXPORTABLE**<br> | Imported keys are marked as exportable.<br> |
| **CRYPT\_MACHINE\_KEYSET**<br> | Private keys are stored under the remote computer and not under the current user.<br> |

## Return value

If the function is successful, the return value is S\_OK.

If the function fails, the return value is a **ULONG** that indicates the error.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Rkeysvcc.h |

## See also

[**RKeyCloseKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyclosekeyservice)

[**RKeyOpenKeyService**](https://learn.microsoft.com/windows/win32/seccrypto/rkeyopenkeyservice)

