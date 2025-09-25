# CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION structure

## Description

Contains details about a credential.

## Members

### `ulAuthenticationPackage`

Type: **ULONG**

The unique identifier of the authentication package. This parameter is required when calling [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser). In a Credential UI scenario, this value is set before a serialization is sent through [SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization). This is the same as the authentication package value returned by [LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage). Content providers can use this parameter to determine if they are able to return credentials for this authentication package. Developers who write their own authentication package may supply their own value.

### `clsidCredentialProvider`

Type: **GUID**

The CLSID of the credential provider. Credential providers assign their own CLSID to this member during serialization. Credential UI ignores this member.

### `cbSerialization`

Type: **ULONG**

The size, in bytes, of the credential pointed to by **rgbSerialization**.

### `rgbSerialization`

Type: **byte***

An array of bytes containing serialized credential information. The exact format of this data depends on the authentication package targeted by a credential provider.

## Remarks

Once the user has entered credential information into a credential tile, it needs to be put into a buffer. Packaging up this information is called serialization and is necessary regardless of whether the scenario uses a Logon UI or a Credential UI. The **CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION** defines the structure for serialization. After serialization, where the buffer is sent depends on whether it is a Logon UI or Credential UI scenario. With a Logon UI, the buffer is passed to [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon). In the Credential UI scenario, this buffer is returned to the calling application which then uses it to authenticate the user.

**Important**

Even if you are implementing a [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) of **CPUS_LOGON**, you do not directly call [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser). That call is handled by the system. You merely need to pass your credentials to [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon).

Credential providers may also enumerate a credential tile if an input credential is received from [SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization). One example where this is useful is if a user provides an invalid user-password combination. The Credential UI will pass the credentials back to the credential provider since they are invalid. The credential provider can opt to display a tile to the user that already has the user name filled in.

Input credentials can take many different forms. It is important that credential providers are robust when receiving serialized credentials. This could include incomplete or partial credentials. In many cases, an incomplete input credential is a hint about what type of credential the caller wants. One case where this process is used is with callers who only wish to gather smart card credentials from the user. During the **CPUS_LOGON** usage scenario, the system uses [SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) to fill in some of the information from a remote machine. Logon UI will call **SetSerialization** zero or one times each enumeration cycle.