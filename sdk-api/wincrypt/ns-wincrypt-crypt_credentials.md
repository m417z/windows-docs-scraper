# CRYPT_CREDENTIALS structure

## Description

The **CRYPT_CREDENTIALS** structure contains information about credentials that can be passed as optional input to a remote object retrieval function such as [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) or [CryptGetTimeValidObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgettimevalidobject).

## Members

### `cbSize`

The size in bytes of this structure.

### `pszCredentialsOid`

A pointer to a null-terminated string that contains the type of credential object represented by the **pvCredentials** member.

This member can contain the following possible value.

| Value | Meaning |
| --- | --- |
| **CREDENTIAL_OID_PASSWORD_CREDENTIALS** | The **pvCredentials** member contains a [CRYPT_PASSWORD_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_password_credentialsa) structure that represents a user name and password combination. |

### `pvCredentials`

A pointer to a structure as defined by the **pszCredentialsOid** member.