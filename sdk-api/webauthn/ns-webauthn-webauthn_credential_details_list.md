## Description

The list of credential details.

## Syntax

```cpp
typedef struct _WEBAUTHN_CREDENTIAL_DETAILS_LIST {
  DWORD                        cCredentialDetails;
  PWEBAUTHN_CREDENTIAL_DETAILS *ppCredentialDetails;
} WEBAUTHN_CREDENTIAL_DETAILS_LIST, *PWEBAUTHN_CREDENTIAL_DETAILS_LIST;
```

## Members

### `cCredentialDetails`

The size of the credential details array.

### `ppCredentialDetails`

The credential details array.

## Remarks

## See also

[WEBAUTHN_CREDENTIAL_DETAILS](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential_details)