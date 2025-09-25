# ChangeAccountPasswordW function

## Description

The **ChangeAccountPassword** function changes the password for a Windows domain account by using the specified [Security Support Provider](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

This function is supported only by the [Microsoft Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-kerberos), [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate), and [Microsoft NTLM](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-ntlm) providers.

## Parameters

### `pszPackageName` [in]

The name of the provider to use. The value of this parameter must be either "Kerberos", "Negotiate", or "NTLM".

### `pszDomainName` [in]

The domain of the account for which to change the password.

### `pszAccountName` [in]

The user name of the account for which to change the password.

### `pszOldPassword` [in]

The old password to be changed.

### `pszNewPassword` [in]

The new password for the specified account.

### `bImpersonating` [in]

**TRUE** if the calling process is running as the client; otherwise, **FALSE**.

### `dwReserved` [in]

Reserved. Must be set to zero.

### `pOutput` [in, out]

On input, a pointer to a [SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure. The **SecBufferDesc** structure must contain a single buffer of type **SECBUFFER_CHANGE_PASS_RESPONSE**. On output, the **pvBuffer** member of that structure points to a [DOMAIN_PASSWORD_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-domain_password_information) structure.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns an error code.

## Remarks

> [!NOTE]
> The sspi.h header defines ChangeAccountPassword as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).