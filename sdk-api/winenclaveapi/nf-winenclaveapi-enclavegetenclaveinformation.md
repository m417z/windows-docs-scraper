# EnclaveGetEnclaveInformation function

## Description

Gets information about the currently executing enclave.

## Parameters

### `InformationSize` [in]

The size of the [ENCLAVE_INFORMATION](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-enclave_information) structure that the *EnclaveInformation* parameter points to, in bytes.

### `EnclaveInformation` [out]

Information about the currently executing enclave.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**EnclaveGetEnclaveInformation** must be called from within an enclave, and is only supported within enclaves that have the **ENCLAVE_TYPE_VBS** enclave type.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[ENCLAVE_INFORMATION](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-enclave_information)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)