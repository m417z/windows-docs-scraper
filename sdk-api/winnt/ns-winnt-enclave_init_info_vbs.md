# ENCLAVE_INIT_INFO_VBS structure

## Description

Contains architecture-specific information to use to initialize an enclave when the enclave type is **ENCLAVE_TYPE_VBS**, which specifies a virtualization-based security (VBS) enclave.

## Members

### `Length`

The total length of the **ENCLAVE_INIT_INFO_VBS** structure, in bytes.

### `ThreadCount`

Upon entry to the [InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave) function, specifies the number of threads to create in the enclave. Upon successful return from **InitializeEnclave**, contains the number of threads the function actually created.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave)