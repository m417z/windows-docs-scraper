# NCryptExportKey function

## Description

The **NCryptExportKey** function exports a CNG key to a memory [BLOB](https://learn.microsoft.com/windows/win32/SecGloss/b-gly).

## Parameters

### `hKey` [in]

A handle of the key to export.

### `hExportKey` [in, optional]

A handle to a cryptographic key of the destination user. The key data within the exported key BLOB is encrypted by using this key. This ensures that only the destination user is able to make use of the key BLOB.

### `pszBlobType` [in]

A null-terminated Unicode string that contains an identifier that specifies the type of BLOB to export. This can be one of the following values.

#### BCRYPT_DH_PRIVATE_BLOB

Export a Diffie-Hellman [public/private key pair](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data.

#### BCRYPT_DH_PUBLIC_BLOB

Export a Diffie-Hellman [public key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data.

#### BCRYPT_DSA_PRIVATE_BLOB

Export a DSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) structure immediately followed by the key data.

#### BCRYPT_DSA_PUBLIC_BLOB

Export a DSA public key. The *pbOutput* buffer receives a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) structure immediately followed by the key data.

#### BCRYPT_ECCPRIVATE_BLOB

Export an [elliptic curve cryptography](https://learn.microsoft.com/windows/win32/SecGloss/e-gly) (ECC) [private key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data.

#### BCRYPT_ECCPUBLIC_BLOB

Export an ECC public key. The *pbOutput* buffer receives a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data.

#### BCRYPT_MLKEM_PRIVATE_SEED_BLOB

Export an ML-KEM private seed key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.

**Note:** ML-KEM key handles which contain a private key which was imported using **BCRYPT_MLKEM_PRIVATE_BLOB** have insufficient information to export a private seed key.

**Windows Insiders (build 27843):** Support for ML-KEM begins.

#### BCRYPT_MLKEM_PRIVATE_BLOB

Export an ML-KEM private (decapsulation) key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.

**Windows Insiders (build 27843):** Support for ML-KEM begins.

#### BCRYPT_MLKEM_PUBLIC_BLOB

Export an ML-KEM public (encapsulation) key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.

**Windows Insiders (build 27843):** Support for ML-KEM begins.

#### BCRYPT_PQDSA_PRIVATE_SEED_BLOB

Export a PQDSA private seed key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.

**Note:** PQDSA key handles which contain a private key which was imported using **BCRYPT_PQDSA_PRIVATE_BLOB** have insufficient information to export a private seed key.

**Windows Insiders (build 27843):** Support for ML-DSA begins.

#### BCRYPT_PQDSA_PRIVATE_BLOB

Export a PQDSA private key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.

**Windows Insiders (build 27843):** Support for ML-DSA begins.

#### BCRYPT_PQDSA_PUBLIC_BLOB

Export a PQDSA public key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.

**Windows Insiders (build 27843):** Support for ML-DSA begins.

#### BCRYPT_PUBLIC_KEY_BLOB

Export a generic public key of any type. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure.

#### BCRYPT_PRIVATE_KEY_BLOB

Export a generic private key of any type. The private key does not necessarily contain the public key. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure.

#### BCRYPT_RSAFULLPRIVATE_BLOB

Export a full RSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. This BLOB will include additional key material compared to the **BCRYPT_RSAPRIVATE_BLOB** type.

#### BCRYPT_RSAPRIVATE_BLOB

Export an RSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data.

#### BCRYPT_RSAPUBLIC_BLOB

Export an RSA public key. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data.

#### LEGACY_DH_PRIVATE_BLOB

Export a legacy [Diffie-Hellman Version 3 Private Key BLOB](https://learn.microsoft.com/windows/win32/SecCrypto/diffie-hellman-version-3-private-key-blobs) that contains a Diffie-Hellman public/private key pair that can be imported by using [CryptoAPI](https://learn.microsoft.com/windows/win32/SecGloss/c-gly).

#### LEGACY_DH_PUBLIC_BLOB

Export a legacy [Diffie-Hellman Version 3 Private Key BLOB](https://learn.microsoft.com/windows/win32/SecCrypto/diffie-hellman-version-3-private-key-blobs) that contains a Diffie-Hellman public key that can be imported by using CryptoAPI.

#### LEGACY_DSA_PRIVATE_BLOB

Export a DSA public/private key pair in a form that can be imported by using CryptoAPI.

#### LEGACY_DSA_PUBLIC_BLOB

Export a DSA public key in a form that can be imported by using CryptoAPI.

#### LEGACY_RSAPRIVATE_BLOB

Export an RSA public/private key pair in a form that can be imported by using CryptoAPI.

#### LEGACY_RSAPUBLIC_BLOB

Export an RSA public key in a form that can be imported by using CryptoAPI.

#### NCRYPT_CIPHER_KEY_BLOB

Export a cipher key in a [NCRYPT_KEY_BLOB_HEADER](https://learn.microsoft.com/windows/win32/api/ncrypt/ns-ncrypt-ncrypt_key_blob_header) structure.

**Windows 8 and Windows Server 2012:** Support for this value begins.

#### NCRYPT_OPAQUETRANSPORT_BLOB

Export a key in a format that is specific to a single CSP and is suitable for transport. Opaque BLOBs are not transferable and must be imported by using the same CSP that generated the BLOB.

#### NCRYPT_PKCS7_ENVELOPE_BLOB

Export a PKCS #7 envelope BLOB. The parameters identified by the _pParameterList_ parameter either can or must contain the following parameters, as indicated by the Required or optional column.

| Parameter | Required or optional |
|--------|--------|
| NCRYPTBUFFER_CERT_BLOB | Required |
| NCRYPTBUFFER_PKCS_ALG_OID | Required |
| NCRYPTBUFFER_PKCS_ALG_PARAM | Optional |

#### NCRYPT_PKCS8_PRIVATE_KEY_BLOB

Export a PKCS #8 private key BLOB. The parameters identified by the _pParameterList_ parameter either can or must contain the following parameters, as indicated by the Required or optional column.

| Parameter | Required or optional |
|--------|--------|
| NCRYPTBUFFER_PKCS_ALG_OID | Optional |
| NCRYPTBUFFER_PKCS_ALG_PARAM | Optional |
| NCRYPTBUFFER_PKCS_SECRET | Optional |

#### NCRYPT_PROTECTED_KEY_BLOB

Export a protected key in a [NCRYPT_KEY_BLOB_HEADER](https://learn.microsoft.com/windows/win32/api/ncrypt/ns-ncrypt-ncrypt_key_blob_header) structure.

**Windows 8 and Windows Server 2012:** Support for this value begins.

#### NCRYPT_PQ_PRIVATE_KEY_BLOB

Export a generic private key of any type of Post-Quantum algorithm. The type of key in this BLOB is determined by the **Magic** member of the **NCRYPT_PQ_BLOB** structure.

### `pParameterList` [in, optional]

The address of an [NCryptBufferDesc](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbufferdesc) structure that receives parameter information for the key. This parameter can be **NULL** if this information is not needed.

### `pbOutput` [out, optional]

The address of a buffer that receives the key BLOB. The _cbOutput_ parameter contains the size of this buffer. If this parameter is **NULL**, this function will place the required size, in bytes, in the **DWORD** pointed to by the _pcbResult_ parameter.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer.

### `pcbResult` [out]

The address of a **DWORD** variable that receives the number of bytes copied to the *pbOutput* buffer. If the *pbOutput* parameter is **NULL**, this function will place the required size, in bytes, in the **DWORD** pointed to by this parameter.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values. The set of valid flags is specific to each key storage provider. The following flag applies to all providers.

| Value | Meaning |
|--------|--------|
| NCRYPT_SILENT_FLAG | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|--------|--------|
| ERROR_SUCCESS | The function was successful. |
| NTE_BAD_FLAGS | The _dwFlags_ parameter contains a value that is not valid. |
| NTE_BAD_KEY_STATE | The key specified by the _hKey_ parameter is not valid. The most common cause of this error is that the key was not completed by using the [NCryptFinalizeKey](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptfinalizekey) function. |
| NTE_BAD_TYPE | The key specified by the _hKey_ parameter cannot be exported into the BLOB type specified by the _pszBlobType_ parameter. |
| NTE_INVALID_HANDLE | The _hKey_ or the _hExportKey_ parameter is not valid. |
| NTE_INVALID_PARAMETER | One or more parameters are not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its **StartService** function, a deadlock can occur, and the service may stop responding.

## See also

- [NCryptBuffer](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbuffer)
- [NCryptFinalizeKey](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptfinalizekey)