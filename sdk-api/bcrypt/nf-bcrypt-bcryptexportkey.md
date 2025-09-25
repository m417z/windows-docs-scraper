# BCryptExportKey function

## Description

The **BCryptExportKey** function exports a key to a memory [BLOB](https://learn.microsoft.com/windows/win32/SecGloss/b-gly) that can be persisted for later use.

## Parameters

### `hKey` [in]

The handle of the key to export.

### `hExportKey` [in]

The handle of the key with which to wrap the exported key. Use this parameter when exporting BLOBs of type **BCRYPT_AES_WRAP_KEY_BLOB**; otherwise, set it to `NULL`.

> [!NOTE]
> The *hExportKey* handle must be supplied by the same provider that supplied the *hKey* handle, and *hExportKey* must be a handle to a symmetric key that can be used in the [Advanced Encryption Standard](https://learn.microsoft.com/windows/win32/SecGloss/a-gly) (AES) key wrap algorithm. When the *hKey* handle is from the Microsoft provider, *hExportKey* must be an AES key handle.

**Windows Server 2008 and Windows Vista:** This parameter is not used and should be set to `NULL`.

### `pszBlobType` [in]

A null-terminated Unicode string that contains an identifier that specifies the type of BLOB to export. This can be one of the following values.

| Value | Meaning |
|-------|---------|
| **BCRYPT_AES_WRAP_KEY_BLOB** | Export an AES key wrapped key. The *hExportKey* parameter must reference a valid **BCRYPT_KEY_HANDLE** pointer to the key encryption key, and the key represented by the *hKey* parameter must be a multiple of 8 bytes long.<br><br>**Windows Server 2008 and Windows Vista:** This BLOB type is not supported. |
| **BCRYPT_DH_PRIVATE_BLOB** | Export a Diffie-Hellman [public/private key pair](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data. |
| **BCRYPT_DH_PUBLIC_BLOB** | Export a Diffie-Hellman [public key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_DH_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dh_key_blob) structure immediately followed by the key data. |
| **BCRYPT_DSA_PRIVATE_BLOB** | Export a DSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) or [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) structure immediately followed by the key data. **BCRYPT_DSA_KEY_BLOB** is used for key lengths from 512 to 1024 bits. **BCRYPT_DSA_KEY_BLOB_V2** is used for key lengths that exceed 1024 bits but are less than or equal to 3072 bits.<br><br>**Windows 8:** Support for [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) begins. |
| **BCRYPT_DSA_PUBLIC_BLOB** | Export a DSA public key. The *pbOutput* buffer receives a [BCRYPT_DSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob) or [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) structure immediately followed by the key data. **BCRYPT_DSA_KEY_BLOB** is used for key lengths from 512 to 1024 bits. **BCRYPT_DSA_KEY_BLOB_V2** is used for key lengths that exceed 1024 bits but are less than or equal to 3072 bits.<br><br>**Windows 8:** Support for [BCRYPT_DSA_KEY_BLOB_V2](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_dsa_key_blob_v2) begins. |
| **BCRYPT_ECCPRIVATE_BLOB** | Export an [elliptic curve cryptography](https://learn.microsoft.com/windows/win32/SecGloss/e-gly) (ECC) [private key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The *pbOutput* buffer receives a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data. |
| **BCRYPT_ECCPUBLIC_BLOB** | Export an ECC public key. The *pbOutput* buffer receives a [BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob) structure immediately followed by the key data. |
| **BCRYPT_KEY_DATA_BLOB** | Export a symmetric key to a data BLOB. The *pbOutput* buffer receives a [BCRYPT_KEY_DATA_BLOB_HEADER](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_data_blob_header) structure immediately followed by the key BLOB. |
| **BCRYPT_MLKEM_PRIVATE_SEED_BLOB** | Export an ML-KEM private seed key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Note:** ML-KEM key handles which contain a private key which was imported using **BCRYPT_MLKEM_PRIVATE_BLOB** have insufficient information to export a private seed key.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_MLKEM_PRIVATE_BLOB** | Export an ML-KEM private (decapsulation) key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_MLKEM_PUBLIC_BLOB** | Export an ML-KEM public (encapsulation) key. The *pbOutput* buffer receives a [BCRYPT_MLKEM_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_mlkem_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-KEM begins. |
| **BCRYPT_OPAQUE_KEY_BLOB** | Export a symmetric key in a format that is specific to a single [cryptographic service provider](https://learn.microsoft.com/windows/win32/SecGloss/c-gly) (CSP). Opaque BLOBs are not transferable and must be imported by using the same CSP that generated the BLOB. Opaque BLOBs are only intended to be used for interprocess transfer of keys and are not suitable to be persisted and read across versions of a provider. |
| **BCRYPT_PQDSA_PRIVATE_SEED_BLOB** | Export a Post-Quantum Digital Signature algorithm (PQDSA) private seed key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Note:** PQDSA key handles which contain a private key which was imported using **BCRYPT_PQDSA_PRIVATE_BLOB** have insufficient information to export a private seed key.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PQDSA_PRIVATE_BLOB** | Export a PQDSA private key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PQDSA_PUBLIC_BLOB** | Export a PQDSA public key. The *pbOutput* buffer receives a [BCRYPT_PQDSA_KEY_BLOB](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_key_blob) structure immediately followed by the parameter set and key data.<br><br>**Windows Insiders (build 27843):** Support for ML-DSA begins. |
| **BCRYPT_PRIVATE_KEY_BLOB** | Export a generic private key of any type. The private key does not necessarily contain the public key. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure. |
| **BCRYPT_PUBLIC_KEY_BLOB** | Export a generic public key of any type. The type of key in this BLOB is determined by the **Magic** member of the [BCRYPT_KEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_key_blob) structure. |
| **BCRYPT_RSAFULLPRIVATE_BLOB** | Export a full RSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. This BLOB will include additional key material compared to the **BCRYPT_RSAPRIVATE_BLOB** type. |
| **BCRYPT_RSAPRIVATE_BLOB** | Export an RSA public/private key pair. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. |
| **BCRYPT_RSAPUBLIC_BLOB** | Export an RSA public key. The *pbOutput* buffer receives a [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure immediately followed by the key data. |
| **LEGACY_DH_PRIVATE_BLOB** | Export a legacy [Diffie-Hellman Version 3 Private Key BLOB](https://learn.microsoft.com/windows/win32/SecCrypto/diffie-hellman-version-3-private-key-blobs) that contains a Diffie-Hellman public/private key pair that can be imported by using [CryptoAPI](https://learn.microsoft.com/windows/win32/SecGloss/c-gly). |
| **LEGACY_DH_PUBLIC_BLOB** | Export a legacy [Diffie-Hellman Version 3 Public Key BLOB](https://learn.microsoft.com/windows/win32/SecCrypto/diffie-hellman-version-3-public-key-blobs) that contains a Diffie-Hellman public key that can be imported by using CryptoAPI. |
| **LEGACY_DSA_PRIVATE_BLOB** | Export a DSA public/private key pair in a form that can be imported by using CryptoAPI. |
| **LEGACY_DSA_PUBLIC_BLOB** | Export a DSA public key in a form that can be imported by using CryptoAPI. |
| **LEGACY_DSA_V2_PRIVATE_BLOB** | Export a DSA version 2 private key in a form that can be imported by using CryptoAPI. |
| **LEGACY_RSAPRIVATE_BLOB** | Export an RSA public/private key pair in a form that can be imported by using CryptoAPI. |
| **LEGACY_RSAPUBLIC_BLOB** | Export an RSA public key in a form that can be imported by using CryptoAPI. |

### `pbOutput` [out]

The address of a buffer that receives the key BLOB. The *cbOutput* parameter contains the size of this buffer. If this parameter is `NULL`, this function will place the required size, in bytes, in the **ULONG** pointed to by the *pcbResult* parameter.

### `cbOutput` [in]

Contains the size, in bytes, of the *pbOutput* buffer.

### `pcbResult` [out]

A pointer to a **ULONG** that receives the number of bytes that were copied to the *pbOutput* buffer. If the *pbOutput* parameter is `NULL`, this function will place the required size, in bytes, in the **ULONG** pointed to by this parameter.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size specified by the *cbOutput* parameter is not large enough to hold the ciphertext. If buffer *pbOutput* is too small, *pcbResult* receives the number of bytes required for *pbOutput*. |
| **STATUS_INVALID_HANDLE** | The key handle in the *hKey* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The specified BLOB type is not supported by the provider. If the key handle provided does not support the export of the private seed. See [remarks](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptexportkey#remarks). |

## Remarks

When using a supported algorithm provider, **BCryptExportKey** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hKey* parameter must be derived from an algorithm handle returned by a provider that was opened with the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptExportKey** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptImportKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptimportkey)

[BCryptImportKeyPair](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptimportkeypair)