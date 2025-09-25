# BCryptImportKey function

## Description

The **BCryptImportKey** function imports a symmetric key from a key [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). The [BCryptImportKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkeypair) function is used to import a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hAlgorithm` [in]

The handle of the algorithm provider to import the key. This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function.

### `hImportKey` [in, optional]

The handle of the key encryption key needed to unwrap the key BLOB in the *pbInput* parameter.

**Note** The handle must be supplied by the same provider that supplied the key that is being imported.

**Windows Server 2008 and Windows Vista:** This parameter is not used and should be set to **NULL**.

### `pszBlobType` [in]

A null-terminated Unicode string that contains an identifier that specifies the type of BLOB that is contained in the *pbInput* buffer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_AES_WRAP_KEY_BLOB** | Import a symmetric key from an AES key–wrapped key BLOB. The *hImportKey* parameter must reference a valid **BCRYPT_KEY_HANDLE** pointer to the key encryption key.<br><br>**Windows Server 2008 and Windows Vista:** This BLOB type is not supported. |
| **BCRYPT_KEY_DATA_BLOB** | Import a symmetric key from a data BLOB. The *pbInput* parameter is a pointer to a [BCRYPT_KEY_DATA_BLOB_HEADER](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_key_data_blob_header) structure immediately followed by the key BLOB. |
| **BCRYPT_OPAQUE_KEY_BLOB** | Import a symmetric key BLOB in a format that is specific to a single CSP. Opaque BLOBs are not transferable and must be imported by using the same CSP that generated the BLOB. Opaque BLOBs are only intended to be used for interprocess transfer of keys and are not suitable to be persisted and read in across versions of a provider. |

### `phKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** that receives the handle of the imported key. This handle is used in subsequent functions that require a key, such as [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt). This handle must be released when it is no longer needed by passing it to the [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

### `pbKeyObject` [out, optional]

A pointer to a buffer that receives the imported key object. The *cbKeyObject* parameter contains the size of this buffer. The required size of this buffer can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_OBJECT_LENGTH** property. This will provide the size of the key object for the specified algorithm.

This memory can only be freed after the *phKey* key handle is destroyed.

### `cbKeyObject` [in]

The size, in bytes, of the *pbKeyObject* buffer.

### `pbInput` [in]

The address of a buffer that contains the key BLOB to import. The *cbInput* parameter contains the size of this buffer. The *pszBlobType* parameter specifies the type of key BLOB this buffer contains.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are currently defined, so this parameter should be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the key object specified by the *cbKeyObject* parameter is not large enough to hold the key object. |
| **STATUS_INVALID_HANDLE** | The algorithm handle in the *hAlgorithm* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The algorithm provider specified by the *hAlgorithm* parameter does not support the BLOB type specified by the *pszBlobType* parameter. |

## Remarks

When using a supported algorithm provider, **BCryptImportKey** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptImportKey** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey)

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkeypair)