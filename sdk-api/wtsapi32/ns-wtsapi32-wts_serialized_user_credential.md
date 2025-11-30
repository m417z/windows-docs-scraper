## Description

Contains the serialization of a user credential.

## Syntax

```cpp
typedef struct _WTS_SERIALIZED_USER_CREDENTIAL {
    ULONG SerializationLength;
    BYTE* Serialization;
} WTS_SERIALIZED_USER_CREDENTIAL, *PWTS_SERIALIZED_USER_CREDENTIAL;
```

## Members

### SerializationLength

The size of the array pointed to by `Serialization` in bytes.

### Serialization

A pointer to an array of bytes containing serialized credential information. The format of this data is compatible with the [Microsoft Negotiate authentication package](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage). See *[CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization)* for more information.

## Requirements