# CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE enumeration

## Description

Describes the response when a credential provider attempts to serialize credentials. Used by [ICredentialProviderCredential::GetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getserialization).

## Constants

### `CPGSR_NO_CREDENTIAL_NOT_FINISHED:0`

No credential was serialized because more information is needed. One example of this would be if a credential requires both a PIN and an answer to a secret question, but the user has only provided the PIN. This signals the caller should be given a chance to alter its response.

### `CPGSR_NO_CREDENTIAL_FINISHED`

The credential provider has not serialized a credential but has completed its work. This response has multiple meanings. It can mean that no credential was serialized and that the user should not try again. This response can also mean that no credential was submitted but the credential's work is complete. For example, in the Change Password scenario, this response implies success.

### `CPGSR_RETURN_CREDENTIAL_FINISHED`

A credential was serialized. This response implies that a serialization structure was passed back.

### `CPGSR_RETURN_NO_CREDENTIAL_FINISHED`

The credential provider has not serialized a credential, but has completed its work. The difference between this value and **CPGSR_NO_CREDENTIAL_FINISHED** is that this flag will force the logon UI to return, which will call [UnAdvise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-unadvise) for all the credential providers.

## See also

[Credential Providers in Windows 10](https://learn.microsoft.com/windows/desktop/SecAuthN/credential-providers-in-windows)