# ENCLAVE_INIT_INFO_SGX structure

## Description

Contains architecture-specific information to use to initialize an enclave when the enclave type is **ENCLAVE_TYPE_SGX** or **ENCLAVE_TYPE_SGX2**, which specifies an enclave for the Intel Software Guard Extensions (SGX) architecture extension.

## Members

### `SigStruct`

The enclave signature structure (**SIGSTRUCT**) to use to initialize the enclave. This structure specifies information about the enclave from the enclave signer.

### `Reserved1`

Not used.

### `EInitToken`

The EINIT token structure (**EINITTOKEN**) to use to initialize the enclave. The initialization operation uses this structure to verify that the enclave has permission to start.

### `Reserved2`

Not used.

## Remarks

For more information about the **SIGSTRUCT** and **EINITTOKEN** structures, see the Intel SGX Programming Reference that is available from [Intel Software Guard Extensions](https://software.intel.com/sgx).

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[ENCLAVE_CREATE_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_create_info_sgx)

[InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave)