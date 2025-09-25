## Description

The list of credentials that the user has registered with the authenticator.

## Syntax

```cpp
typedef struct _WEBAUTHN_CREDENTIAL_LIST {
  DWORD                   cCredentials;
  PWEBAUTHN_CREDENTIAL_EX *ppCredentials;
} WEBAUTHN_CREDENTIAL_LIST, *PWEBAUTHN_CREDENTIAL_LIST;
```

## Members

### `cCredentials`

The size of *ppCredentials*.

### `ppCredentials`

The array of credentials.

## Remarks

## See also

[WEBAUTHN_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential)