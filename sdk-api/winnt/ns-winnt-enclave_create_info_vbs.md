# ENCLAVE_CREATE_INFO_VBS structure

## Description

Contains architecture-specific information to use to create an enclave when the enclave type is **ENCLAVE_TYPE_VBS**, which specifies a virtualization-based security (VBS) enclave.

## Members

### `Flags`

A flag that indicates whether the enclave permits debugging.

| Value | Meaning |
|-------|---------|
| **ENCLAVE_VBS_FLAG_DEBUG**<br>`0x00000001` | The enclave permits debugging. |
| `0x00000000` | The enclave does not permit debugging. |

### `OwnerID`

The identifier of the owner of the enclave.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)