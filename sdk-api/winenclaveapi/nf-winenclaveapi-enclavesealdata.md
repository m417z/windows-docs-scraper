# EnclaveSealData function

## Description

Generates an encrypted binary large object (blob) from unencrypted data.

## Parameters

### `DataToEncrypt` [in]

A pointer to the data that you want to seal. This data can be stored either within the address range of the enclave or within the address range of the host process.

### `DataToEncryptSize` [in]

The size of the data that you want to seal, in bytes.

### `IdentityPolicy` [in]

A value that specifies how another enclave must be related to the enclave that calls **EnclaveSealData** for the enclave to unseal the data.

### `RuntimePolicy` [in]

A value that indicates whether an enclave that runs with debugging turned on is permitted to unseal the data the this call to **EnclaveSealData** seals.

| Value | Meaning |
|-------|---------|
| **ENCLAVE_RUNTIME_POLICY_ALLOW_FULL_DEBUG**<br>`1` | If specified, indicates that an enclave that runs with debugging turned on is permitted to unseal the data. If not specified, indicates that an enclave that runs with debugging turned on is not permitted to unseal the data. This flag is automatically included if the calling enclave is running with debugging turned on. |
| **ENCLAVE_RUNTIME_POLICY_ALLOW_DYNAMIC_DEBUG**<br>`2` | If specified, indicates that an enclave that runs with dynamic debugging turned on is permitted to unseal the data. If not specified, indicates that an enclave that runs with dynamic debugging turned on is not permitted to unseal the data. This flag is automatically included if the calling enclave is running with dynamic debugging turned on. |

### `ProtectedBlob` [out]

A pointer to a buffer where the sealed data should be placed. This data may be stored either within the address range of the enclave or within the address space of the host process. If this parameter is NULL, only the size of the protected blob is calculated.

### `BufferSize` [in]

A pointer to a variable that holds the size of the buffer to which the *ProtectedBlob* parameter points. If *ProtectedBlob* is `NULL`, this value must be zero. If *ProtectedBlob* is not `NULL`, and if the size of the encrypted data is larger than this value, an error occurs.

### `ProtectedBlobSize` [out]

A pointer to a variable that receives the actual size of the encrypted blob.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**EnclaveSealData** must be called from within an enclave, and is only supported within enclaves that have the **ENCLAVE_TYPE_VBS** enclave type.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[ENCLAVE_SEALING_IDENTITY_POLICY](https://learn.microsoft.com/windows/win32/api/ntenclv/ne-ntenclv-enclave_sealing_identity_policy)

[EnclaveUnsealData](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaveunsealdata)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)