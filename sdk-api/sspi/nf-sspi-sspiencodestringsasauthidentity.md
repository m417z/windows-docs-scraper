# SspiEncodeStringsAsAuthIdentity function

## Description

Encodes a set of three credential strings as an authentication identity structure.

## Parameters

### `pszUserName` [in]

The user name associated with the identity to encode.

### `pszDomainName` [in]

The domain name associated with the identity to encode.

### `pszPackedCredentialsString` [in]

An encoded string version of a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure that specifies the user's credentials.

### `ppAuthIdentity` [out]

A pointer to the encoded identity structure.

When you have finished using this structure, free it by calling the [SspiFreeAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspifreeauthidentity) function.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.