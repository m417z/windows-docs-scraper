# VBS_ENCLAVE_REPORT_VARDATA_HEADER structure

## Description

Describes the format of a variable data block contained in a report that the [EnclaveGetAttestationReport](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavegetattestationreport) function generates.

## Members

### `DataType`

The type of the variable data block.

| Value | Meaning |
|-------|---------|
| **VBS_ENCLAVE_VARDATA_INVALID**<br>`0x00000000` | The variable data block is not valid. |
| **VBS_ENCLAVE_VARDATA_MODULE**<br>`0x00000001` | The variable data block is a module. |

### `Size`

The size of this variable data block, including the header, in bytes.

## Remarks

An enclave attestation report includes zero or variable data blocks. These variable data blocks consist of the following items:

- A **VBS_ENCLAVE_REPORT_VARDATA_HEADER** structure that describes the format of the variable data block.
- The data described by the **VBS_ENCLAVE_REPORT_VARDATA_HEADER** structure. If the value of the **DataType** member of the **VBS_ENCLAVE_REPORT_VARDATA_HEADER** structure is **VBS_ENCLAVE_VARDATA_MODULE**, this data is a [VBS_ENCLAVE_REPORT_MODULE](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_module) structure.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[EnclaveGetAttestationReport](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavegetattestationreport)

[VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report)

[VBS_ENCLAVE_REPORT_MODULE](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_module)