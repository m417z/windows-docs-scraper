# SspiEncodeAuthIdentityAsStrings function

## Description

Encodes the specified authentication identity as three strings.

## Parameters

### `pAuthIdentity` [in]

The credential structure to be encoded.

### `ppszUserName` [out]

The marshaled user name of the identity specified by the *pAuthIdentity* parameter.

When you have finished using this string, free it by calling the [SspiFreeAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspifreeauthidentity) function.

### `ppszDomainName` [out]

The marshaled domain name of the identity specified by the *pAuthIdentity* parameter.

When you have finished using this string, free it by calling the [SspiFreeAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspifreeauthidentity) function.

### `ppszPackedCredentialsString` [out]

An encoded string version of a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure that specifies the users credentials.

When you have finished using this string, free it by calling the [SspiFreeAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspifreeauthidentity) function.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER**<br><br>0xC000000D | The **SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED** flag is set in the identity structure specified by the *pAuthIdentity* parameter. |