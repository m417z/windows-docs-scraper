## Description

The structure containing the COSE credential parameter that is sent to the authenticator.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `pwszCredentialType`

Well-known credential type specifying a credential to create.

### `lAlg`

Well-known COSE algorithm specifying the algorithm to use for the credential.

## Remarks

## See also

[WEBAUTHN_COSE_CREDENTIAL_PARAMETERS](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_cose_credential_parameters)