# EnclaveUnsealData function

## Description

Decrypts an encrypted binary large object (blob).

## Parameters

### `ProtectedBlob` [in]

A pointer to the sealed data to unseal. This data may be stored either within the address range of the enclave or within the address space of the host process

### `ProtectedBlobSize` [in]

The size of the sealed data to unseal, in bytes.

### `DecryptedData` [out]

A pointer to a buffer where the unencrypted data should be placed. This data may be stored either within the address range of the enclave or within the address space of the host process. If this parameter is `NULL`, only the size of the decrypted data is calculated.

### `BufferSize` [in]

The size of the buffer to which the *DecryptedData* parameter points, in bytes. If *DecryptedData* is `NULL`, *BufferSize* must be zero. If *DecryptedData* is not `NULL`, and if the size of the decrypted data is larger than this value, an error is returned.

### `DecryptedDataSize` [out]

A pointer to a variable that receives the actual size of the decrypted data, in bytes.

### `SealingIdentity` [out, optional]

An optional pointer to a buffer that should be filled with the identity of the enclave that sealed the data. If this pointer is `NULL`, the identity of the sealing enclave is not returned.

### `UnsealingFlags` [out, optional]

An optional pointer to a variable that receives zero or more of the following flags that describe the encrypted binary large object.

| Value | Meaning |
|-------|---------|
| **ENCLAVE_UNSEAL_FLAG_STALE_KEY**<br>`1` | The data was encrypted with a stale key. Sealing keys are rotated when required for security, and the system can only maintain a fixed number of recently known keys. An enclave that determines that data was encrypted with a stale key should re-encrypt the data with a current key to minimize the chances that the key used to encrypt the data is no longer maintained in the key list. |

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The enclave that calls **EnclaveUnsealData** must meet the criteria that correspond to the value of the [ENCLAVE_SEALING_IDENTITY_POLICY](https://learn.microsoft.com/windows/win32/api/ntenclv/ne-ntenclv-enclave_sealing_identity_policy) that was specified by the enclave that sealed the data by calling [EnclaveSealData](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavesealdata).

**EnclaveUnsealData** must be called from within an enclave, and is only supported within enclaves that have the **ENCLAVE_TYPE_VBS** enclave type.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[ENCLAVE_SEALING_IDENTITY_POLICY](https://learn.microsoft.com/windows/win32/api/ntenclv/ne-ntenclv-enclave_sealing_identity_policy)

[EnclaveSealData](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavesealdata)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)