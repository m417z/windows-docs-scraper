# CRED_MARSHAL_TYPE enumeration

## Description

The **CRED_MARSHAL_TYPE** enumeration specifies the types of credential to be marshaled by [CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala) or unmarshaled by [CredUnmarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credunmarshalcredentiala).

## Constants

### `CertCredential:1`

Specifies that the credential is a certificate reference described by a [CERT_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-cert_credential_info) structure.

### `UsernameTargetCredential`

Specifies that the credential is a reference to a CRED_FLAGS_USERNAME_TARGET credential described by a [USERNAME_TARGET_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-username_target_credential_info) structure.

### `BinaryBlobCredential`

### `UsernameForPackedCredentials`

### `BinaryBlobForSystem`