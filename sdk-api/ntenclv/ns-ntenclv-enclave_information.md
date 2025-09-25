# ENCLAVE_INFORMATION structure

## Description

Contains information about the currently executing enclave.

## Members

### `EnclaveType`

The architecture type of the enclave.

| Value | Meaning |
|-------|---------|
| **ENCLAVE_TYPE_SGX**<br>`0x00000001` | An enclave for the Intel Software Guard Extensions (SGX) architecture extension. |
| **ENCLAVE_TYPE_SGX2**<br>`0x00000002` | Supports SGX2 and SGX1 enclaves. The platform and OS support SGX2 instructions with EDMM on this platform (in addition to other SGX2 constructs). |
| **ENCLAVE_TYPE_VBS**<br>`0x00000010` | A VBS enclave. |

### `Reserved`

Reserved.

### `BaseAddress`

A pointer to the base address of the enclave.

### `Size`

The size of the enclave, in bytes.

### `Identity`

The identity of the primary module of an enclave.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[ENCLAVE_IDENTITY](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-enclave_identity)

[EnclaveGetEnclaveInformation](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavegetenclaveinformation)