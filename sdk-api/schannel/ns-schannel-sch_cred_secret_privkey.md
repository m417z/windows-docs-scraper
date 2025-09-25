# SCH_CRED_SECRET_PRIVKEY structure

## Description

[The **SCH_CRED_SECRET_PRIVKEY** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) structure.]

The **SCH_CRED_SECRET_PRIVKEY** structure contains [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information needed to authenticate a client or server.

## Members

### `dwType`

Must always be set to SCHANNEL_SECRET_PRIVKEY.

### `pPrivateKey`

Pointer to an encrypted private key.

### `cbPrivateKey`

Number of bytes in the encrypted private key.

### `pszPassword`

Pointer to a null-terminated string that Schannel uses to decrypt the private key.