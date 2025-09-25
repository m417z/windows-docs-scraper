# BCryptImportKeyPair function

## Description

The **BCryptImportKeyPair** function imports a [public/private key pair](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) from a key [BLOB](https://learn.microsoft.com/windows/win32/SecGloss/b-gly). The [BCryptImportKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptimportkey) function is used to import a [symmetric key](https://learn.microsoft.com/windows/win32/SecGloss/s-gly).

## Parameters

### `hAlgorithm` [in]

The handle of an algorithm provider that uses asymmetric key pairs. Examples of types of algorithms include Signing, Asymmetric encryption, Key agreement, and Key encapsulation mechanism. This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function, or may be a [CNG Algorithm Pseudo-handle](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles).

### `hImportKey` [in, out]

This parameter is not currently used and should be `NULL`.

### `pszBlobType` [in]

A null-terminated Unicode string that contains an identifier that specifies the type of BLOB that is contained in the *pbInput* buffer. This can be one of the following values:

| Value | Meaning |
|-------|---------|
| **BCRYPT_DH_PRIVATE_BLOB** | The BLOB is a Diffie-Hellman public/private key pair BLOB. The *pbInput* buffer must contain a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data. |
| **BCRYPT_DH_PUBLIC_BLOB** | The BLOB is a Diffie-Hellman [public key BLOB](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbInput* buffer must contain a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data. |
| **BCRYPT_DSA_PRIVATE_BLOB** | The BLOB is a DSA public/private key pair BLOB. The *pbInput* buffer must contain a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) or [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) structure immediately followed by the key data. **BCRYPT_DSA_KEY_BLOB** is used for key lengths from 512 to 1024 bits. **BCRYPT_DSA_KEY_BLOB_V2** is used for key lengths that exceed 1024 bits but are less than or equal to 3072 bits.<br><br>**Windows 8:** Support for [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) begins. |
| **BCRYPT_DSA_PUBLIC_BLOB** | The BLOB is a DSA public key BLOB. The *pbInput* buffer must contain a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) or [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) structure immediately followed by the key data. **BCRYPT_DSA_KEY_BLOB** is used for key lengths from 512 to 1024 bits. **BCRYPT_DSA_KEY_BLOB_V2** is used for key lengths that exceed 1024 bits but are less than or equal to 3072 bits.<br><br>**Windows 8:** Support for [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) begins. |
| **BCRYPT_ECCPRIVATE_BLOB** | The BLOB is an [elliptic curve cryptography](https://learn.microsoft.com/windows/win32/SecGloss/e-gly) (ECC) [private key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbInput* buffer must contain a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data. |
| **BCRYPT_ECCPUBLIC_BLOB** | The BLOB is an ECC public key. The *pbInput* buffer must contain a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data. |
| **BCRYPT_MLKEM_PRIVATE_SEED_BLOB** | The BLOB is an ML-KEM private seed. The *pbInput* buffer must contain a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure with **BCRYPT_MLKEM_SEED_MAGIC**, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_MLKEM_PRIVATE_BLOB** | The BLOB is an ML-KEM private (decapsulation) key. The *pbInput* buffer must contain a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure with **BCRYPT_MLKEM_PRIVATE_MAGIC**, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_MLKEM_PUBLIC_BLOB** | The BLOB is an ML-KEM public (encapsulation) key. The *pbInput* buffer must contain a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure with **BCRYPT_MLKEM_PUBLIC_MAGIC**, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_PQDSA_PRIVATE_SEED_BLOB** | The BLOB is a Post-Quantum Digital Signature algorithm (PQDSA) private seed key. The *pbInput* buffer must contain a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure with appropriate magic, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PQDSA_PRIVATE_BLOB** | The BLOB is a PQDSA private key. The *pbInput* buffer must contain a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure with appropriate magic, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PQDSA_PUBLIC_BLOB** | The BLOB is a PQDSA public key. The *pbInput* buffer must contain a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure with appropriate magic, immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PRIVATE_KEY_BLOB** | The BLOB is a generic private key of any type. The private key does not necessarily contain the public key. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure. |
| **BCRYPT_PUBLIC_KEY_BLOB** | The BLOB is a generic [public key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) of any type. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure. |
| **BCRYPT_RSAPRIVATE_BLOB** | The BLOB is an RSA public/private key pair BLOB. The *pbInput* buffer must contain a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. |
| **BCRYPT_RSAPUBLIC_BLOB** | The BLOB is an RSA public key BLOB. The *pbInput* buffer must contain a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. |
| **LEGACY_DH_PUBLIC_BLOB** | The BLOB is a Diffie-Hellman public key BLOB that was exported by using [CryptoAPI](https://learn.microsoft.com/windows/win32/SecGloss/c-gly). The Microsoft primitive provider does not support importing this BLOB type. |
| **LEGACY_DH_PRIVATE_BLOB** | The BLOB is a legacy [Diffie-Hellman Version 3 Private Key BLOB](https://learn.microsoft.com/windows/win32/SecCrypto/diffie-hellman-version-3-private-key-blobs) that contains a Diffie-Hellman public/private key pair that was exported by using CryptoAPI. |
| **LEGACY_DSA_PRIVATE_BLOB** | The BLOB is a DSA public/private key pair BLOB that was exported by using CryptoAPI. |
| **LEGACY_DSA_PUBLIC_BLOB** | The BLOB is a DSA public key BLOB that was exported by using CryptoAPI. The Microsoft primitive provider does not support importing this BLOB type. |
| **LEGACY_DSA_V2_PRIVATE_BLOB** | The BLOB is a DSA version 2 private key in a form that can be imported by using CryptoAPI. |
| **LEGACY_RSAPRIVATE_BLOB** | The BLOB is an RSA public/private key pair BLOB that was exported by using CryptoAPI. |
| **LEGACY_RSAPUBLIC_BLOB** | The BLOB is an RSA public key BLOB that was exported by using CryptoAPI. The Microsoft primitive provider does not support importing this BLOB type. |

### `phKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** that receives the handle of the imported key. This handle is used in subsequent functions that require a key, such as [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash). This handle must be released when it is no longer needed by passing it to the [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

### `pbInput` [in]

The address of a buffer that contains the [key BLOB](https://learn.microsoft.com/windows/win32/SecGloss/k-gly) to import. The *cbInput* parameter contains the size of this buffer. The *pszBlobType* parameter specifies the type of key BLOB this buffer contains.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function.

This can be zero or the following value:

| Value | Meaning |
|-------|---------|
| **BCRYPT_NO_KEY_VALIDATION** | Opt out of any applicable FIPS self-tests. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_BUFFER_SIZE** | If the buffer *pbInput* is not of the correct size for the combination *hAlgorithm* and *pszBlobType*. |
| **STATUS_INVALID_HANDLE** | The algorithm handle in the *hAlgorithm* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The algorithm provider specified by the *hAlgorithm* parameter does not support the BLOB type specified by the *pszBlobType* parameter. |

## Remarks

When using a supported algorithm provider, **BCryptImportKeyPair** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptImportKeyPair** function must refer to nonpaged (or locked) memory.

Caller should free *hKey* with [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey) when the key is no longer being used.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey)

[BCryptExportKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptimportkey)