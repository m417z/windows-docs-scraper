# EnclaveVerifyAttestationReport function

## Description

Verifies an attestation report that was generated on the current system.

## Parameters

### `EnclaveType` [in]

The type of the enclave for which the report was generated. Must be **ENCLAVE_TYPE_VBS**.

### `Report` [in]

A pointer to a buffer that stores the report. This report may be stored either within the address range of the enclave or within the address space of the host process.

### `ReportSize` [in]

The size of the report, in bytes.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is used if two enclaves run on the same system and need to establish a secure channel between one another. When you call **EnclaveVerifyAttestationReport** from a virtualization-based security (VBS) enclave, you can only use **EnclaveVerifyAttestationReport** to validate an attestation report that another VBS enclave generated.

**EnclaveVerifyAttestationReport** must be called from within an enclave, and is only supported within enclaves that have the **ENCLAVE_TYPE_VBS** enclave type.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[EnclaveGetAttestationReport](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavegetattestationreport)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)