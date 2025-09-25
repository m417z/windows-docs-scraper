# ENCLAVE_CREATE_INFO_SGX structure

## Description

Contains architecture-specific information to use to create an enclave when the enclave type is **ENCLAVE_TYPE_SGX** or **ENCLAVE_TYPE_SGX2**, which specifies an enclave for one of the Intel Software Guard Extensions (SGX) architecture extensions.

## Members

### `Secs`

The SGX enclave control structure (**SECS**) to use to create the enclave.

## Remarks

For more information about the **SECS** structure, see the Intel SGX Programming Reference that is available from [Intel Software Guard Extensions](https://software.intel.com/sgx).

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)

[ENCLAVE_INIT_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_init_info_sgx)