## Description

Indicates disabled cryptographic settings.

## Members

### `eAlgorithmUsage`

The algorithm being used as specified in the [eTlsAlgorithmUsage](https://learn.microsoft.com/windows/win32/api/schannel/ne-schannel-etlsalgorithmusage) enumeration.

|Value|Algorithm|
|--|--|
|TlsParametersCngAlgUsageKeyExchange |Key exchange algorithm. <br>(*e.g. RSA, ECDHE, DHE*) |
|TlsParametersCngAlgUsageSignature |Signature algorithm. <br>(*e.g. RSA, DSA, ECDSA*)|
|TlsParametersCngAlgUsageCipher |Encryption algorithm. <br>(*e.g. AES, DES, RC4*)|
|TlsParametersCngAlgUsageDigest |Digest of cipher suite. <br> (*e.g. SHA1, SHA256, SHA384*)|
|TlsParametersCngAlgUsageCertSig |Signature and/or hash used to sign certificate. <br>(*e.g. RSA, DSA, ECDSA, SHA1, SHA256*)|

### `strCngAlgId`

The [CNG algorithm identifier](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers).

Cryptographic settings are ignored if the specified algorithm is not used by a supported, enabled cipher suite or an available credential.

### `cChainingModes`

The count of entries in the rgstrChainingModes array.

Set to 0 if strCngAlgId does not have a chaining mode (*e.g. BCRYPT_SHA384_ALGORITHM*). It is an error to specify more than SCH_CRED_MAX_SUPPORTED_CHAINING_MODES.

### `rgstrChainingModes`

An array of [CNG chaining mode identifiers](https://learn.microsoft.com/windows/win32/seccng/cng-property-identifiers).

Set to NULL if strCngAlgId does not have a chaining mode (*e.g. BCRYPT_SHA384_ALGORITHM*).

### `dwMinBitLength`

Minimum bit length for the specified CNG algorithm.

If 0, schannel uses system defaults. Set to 0 if the CNG algorithm implies bit length (*e.g. BCRYPT_ECDH_P521_ALGORITHM*).

### `dwMaxBitLength`

Maximum bit length for the specified CNG algorithm.

If 0, schannel uses system defaults. Set to 0 if the CNG algorithm implies bit length (e.g. BCRYPT_ECDH_P521_ALGORITHM).

## Remarks

The following constant distinguishes between the different RSA padding modes and can be specified in the `strCngAlgId` field. Either of these modes can be provided instead of the [CNG algorithm identifier](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers).

```cpp
#define SCHANNEL_RSA_PSS_PADDING_ALGORITHM L"SCH_RSA_PSS_PAD"
#define SCHANNEL_RSA_PKCS_PADDING_ALGORITHM L"SCH_RSA_PKCS_PAD"
```

## See also

[SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials)

[TLS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-tls_parameters)

[eTlsAlgorithmUsage](https://learn.microsoft.com/windows/win32/api/schannel/ne-schannel-etlsalgorithmusage)