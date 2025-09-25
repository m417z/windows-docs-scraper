# CRYPT_OID_INFO structure

## Description

The **CRYPT_OID_INFO** structure contains information about an [object identifier](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OID). These structures give the relationship among an OID identifier, its name, its group, and other information about the OID. These structures can be listed by using
the [CryptEnumOIDInfo](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-cryptenumoidinfo) function. New CRYPT_OID_STRUCTURES can be added by using
the [CryptRegisterOIDInfo](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-cryptregisteroidinfo) function.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pszOID`

The OID associated with this OID information.

### `pwszName`

The display name associated with an OID.

### `dwGroupId`

The group identifier value associated with this OID information.

This member can be one of the following **dwGroupId** group identifiers.

| Value | Meaning |
| --- | --- |
| **CRYPT_ENCRYPT_ALG_OID_GROUP_ID** | Encryption algorithms |
| **CRYPT_ENHKEY_USAGE_OID_GROUP_ID** | Enhanced key usages |
| **CRYPT_EXT_OR_ATTR_OID_GROUP_ID** | Extensions or attributes |
| **CRYPT_HASH_ALG_OID_GROUP_ID** | Hash algorithms |
| **CRYPT_POLICY_OID_GROUP_ID** | Policies |
| **CRYPT_PUBKEY_ALG_OID_GROUP_ID** | Public key algorithms |
| **CRYPT_RDN_ATTR_OID_GROUP_ID** | RDN attributes |
| **CRYPT_SIGN_ALG_OID_GROUP_ID** | Signature algorithms |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.dwValue`

A numeric value associated with this OID information. This member is used with **dwGroupId** CRYPT_SIGN_ALG_OID_GROUP_ID.

### `DUMMYUNIONNAME.Algid`

The algorithm identifier associated with this OID information.

This member applies for the following values of **dwGroupId**:

* CRYPT_HASH_ALG_OID_GROUP_ID
* CRYPT_ENCRYPT_ALG_OID_GROUP_ID
* CRYPT_PUBKEY_ALG_OID_GROUP_ID
* CRYPT_SIGN_ALG_OID_GROUP_ID

### `DUMMYUNIONNAME.dwLength`

This member is not implemented. It is always set to zero.

### `ExtraInfo`

Extra information used to find or register OID information. This member applies for the following values of **dwGroupId**:

* CRYPT_PUBKEY_ALG_OID_GROUP_ID
* CRYPT_SIGN_ALG_OID_GROUP_ID
* CRYPT_RDN_ATTR_OID_GROUP_ID

The OIDs in the CRYPT_ENCRYPT_ALG_OID_GROUP_ID OID group have a bit length set for the AES algorithms in the DWORD[0] member of the ExtraInfo member.

The OIDs in the CRYPT_PUBKEY_ALG_OID_GROUP_ID group have a flag set in the DWORD[0] member of the ExtraInfo member.

The OIDs in the ECC curve name public keys, for example, szOID_ECC_CURVE_P256 ("1.2.840.10045.3.1.7"), have a flag set in the DWORD[0] member, a BCRYPT_ECCKEY_BLOB dwMagic field value set in the DWORD[1] member, and a bit length where the BCRYPT_ECCKEY_BLOB cbKey value equals dwBitLength / 8 + ((dwBitLength % 8) ? 1 : 0) set in the DWORD[2] member of the ExtraInfo member.

The OIDs in the CRYPT_SIGN_ALG_OID_GROUP_ID group have a public key algorithm identifier set in the DWORD[0] member, a flag set in the DWORD[1] member, and an optional provider type set in the DWORD[2] member of the ExtraInfo member.

The OIDs in the CRYPT_RDN_ATTR_OID_GROUP_ID group have a null-terminated list of acceptable RDN attribute value types set in an array of **DWORD** values in the ExtraInfo member. An omitted list implies an array of values where the first value in the array is CERT_RDN_PRINTABLE_STRING, the second value in the array is CERT_RDN_UNICODE_STRING, and the third value in the array is zero.

The following values are used for the flags in the **ExtraInfo** member.

| Value | Meaning |
| --- | --- |
| **CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG** | This flag is no longer used.<br><br>Stop the reformatting of the signature before the [CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea) function is called or after the [CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) function is called. |
| **CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG** | Omit **NULL** parameters when encoding. |
| **CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG** | The public key is only used for encryption. |
| **CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG** | The public key is only used for signatures. |
| **CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG** | This flag is no longer used.<br><br>Include the parameters of the public key algorithm in the *digestEncryptionAlgorithm* parameters for the PKCS #7 message. |

#### Post-quantum use

**CRYPT_PUBKEY_ALG_OID_GROUP_ID** has the following *ExtraInfo* fields when used with PQ OIDs (above):

| Field | Description |
|--|--|
| DWORD[0] | Flags |
| DWORD[1] | Public Magic (e.g. **BCRYPT_MLDSA_PUBLIC_MAGIC**) |
| DWORD[2] | Private Magic (e.g. **BCRYPT_MLDSA_PRIVATE_SEED_MAGIC**) |
| DWORD[4] | Public Key Byte Length |
| DWORD[5] | Private Key Byte Length |
| DWORD[6] | Signature Byte Length |

**CRYPT_SIGN_ALG_OID_GROUP_ID** has the following *ExtraInfo* fields when used with PQ OIDs:

| Field | Description |
|--|--|
| DWORD[0] | Flags |
| DWORD[1] | Signature Byte Length |

**CRYPT_HASH_ALG_OID_GROUP_ID** can be set to L”NoHash” to indicate no hash before signing, and the PQ key will directly sign the *ToBeSigned* bytes.

### `pwszCNGAlgid`

The algorithm identifier string passed to the CNG functions (the BCrypt* and NCrypt* functions that are defined in Bcrypt.h and Ncrypt.h). CNG functions use algorithm identifier strings, such as L"SHA1", instead of the [ALG_ID](https://learn.microsoft.com/windows/win32/SecCrypto/alg-id) data type constants, such as **CALG_SHA1**. **Windows Server 2003 and Windows XP:** This member is not available.

> [!NOTE]
> The **pwszCNGAlgid** member is only available if you include the following statement in your code.

```cpp
#define CRYPT_OID_INFO_HAS_EXTRA_FIELDS
```

This member applies for the following values of **dwGroupId**:

- CRYPT_HASH_ALG_OID_GROUP_ID
- CRYPT_ENCRYPT_ALG_OID_GROUP_ID
- CRYPT_PUBKEY_ALG_OID_GROUP_ID
- CRYPT_SIGN_ALG_OID_GROUP_ID

Set the *pwszCNGAlgid* member to the empty string, L"", for the other values of **dwGroupId**.

The *pwszCNGAlgid* member can also be set to a string value that is not passed directly to the CNG functions. The following table lists these values and their meanings:

| Value | Meaning |
|--|--|
| **CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM** | The ECC curve algorithm is obtained from the encoded parameters of the OID algorithm. |
| **CRYPT_OID_INFO_ECC_WRAP_PARAMETERS_ALGORITHM** | The key wrap algorithm is obtained from the encoded parameters of the OID algorithm. |
| **CRYPT_OID_INFO_HASH_PARAMETERS_ALGORITHM** | The hash algorithm is obtained from the encoded parameters of the OID algorithm. |
| **CRYPT_OID_INFO_MGF1_PARAMETERS_ALGORITHM** | The PKCS #1 v2.1 mask generation hash algorithm is obtained from the encoded parameters of the OID algorithm. |
| **CRYPT_OID_INFO_NO_SIGN_ALGORITHM** | A public key algorithm that indicates the signature value is an unsigned hash. |
| **CRYPT_OID_INFO_OAEP_PARAMETERS_ALGORITHM** | The RSAES-OAEP padding hash algorithm is obtained from the encoded parameters of the OID algorithm. |
| **CRYPT32_MLDSA_44_ALGORITHM**<br>`L"ML-DSA:44"` | The ML-DSA algorithm combines the CNG algorithm name for ML-DSA and the CNG parameter set 44 (NIST security category 2). |
| **CRYPT32_MLDSA_65_ALGORITHM**<br>`L"ML-DSA:65"` | The ML-DSA algorithm combines the CNG algorithm name for ML-DSA and the CNG parameter set 65(NIST security category 3). |
| **CRYPT32_MLDSA_87_ALGORITHM**<br>`L"ML-DSA:87"` | The ML-DSA algorithm combines the CNG algorithm name for ML-DSA and the CNG parameter set 87 (NIST security category 5). |
| **CRYPT_OID_INFO_NO_HASH_ALGORITHM**<br>`L"NoHash"` | For PQ digital signatures, indicates there is no hash before signing, and the PQ key will directly sign the ToBeSigned bytes. |

### `pwszCNGExtraAlgid`

An extra algorithm string, other than the string in the **pwszCNGAlgid** member, that can be passed to the CNG functions (the BCrypt* and NCrypt* functions that are defined in Bcrypt.h and Ncrypt.h).

**Windows Server 2003 and Windows XP:** This member is not available.

**Note** This member is only available if you include the following statement in your code.

```cpp
#define CRYPT_OID_INFO_HAS_EXTRA_FIELDS
```

For the signature algorithms (CRYPT_SIGN_ALG_OID_GROUP_ID), this member is the public key algorithm string to pass to the CNG functions.

For ECC signatures, this member is the special CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM string value.

For unsigned signatures, this member is the special CRYPT_OID_INFO_NO_SIGN_ALGORITHM string value.

For ECC curve name public keys, for example, szOID_ECC_CURVE_P256 ("1.2.840.10045.3.1.7"), this is the special CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM string value.

For the other values of **dwGroupId**, set the **pwszCNGExtraAlgid** member to the empty string, L"".

## See also

[CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo)

[CryptRegisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidinfo)

[CryptUnregisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidinfo)