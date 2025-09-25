# EnclaveGetAttestationReport function

## Description

Gets an enclave attestation report that describes the current enclave and is signed by the authority that is responsible for the type of the enclave.

## Parameters

### `EnclaveData` [in, optional]

A pointer to a 64-byte buffer of data that the enclave wants to insert into its signed report. For example, this buffer could include a 256-bit nonce that the relying party supplied, followed by a SHA-256 hash of additional data that the enclave wants to convey, such as a public key that corresponds to a private key that the enclave owns. If this parameter is `NULL`, the corresponding field of the report is filled with zeroes.

### `Report` [out]

A pointer to a buffer where the report should be placed. This report may be stored either within the address range of the enclave or within the address space of the host process. Specify `NULL` to indicate that only the size of the buffer required for the output should be calculated, and not the report itself.

### `BufferSize` [in]

The size of the buffer to which the *Report* parameter points. If *Report* is `NULL`, *BufferSize* must be zero. If *Report* is not `NULL`, and if the size of the report is larger than this value, an error is returned.

### `OutputSize` [out]

A pointer to a variable that receives the size of the report.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**EnclaveGetAttestationReport** must be called from within an enclave.

**EnclaveGetAttestationReport** is not currently supported for enclaves with a type of **ENCLAVE_TYPE_SGX**. For VBS enclaves, the report that **EnclaveGetAttestationReport** gets is signed by using a VBS-specific key.

The enclave attestation report contains the identity of all code loaded into the enclave, as well as policies that control how the enclave is running, such as whether the enclave is running with debugger access active. The report also includes a small amount of information that the enclave generated to use in a key-exchange protocol.

The report that **EnclaveGetAttestationReport** generates consists of the following items:

- A [VBS_ENCLAVE_REPORT_PKG_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_pkg_header) structure
- A signed statement that consist of the following items:
  - A [VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report) structure
  - Zero or more variable data blocks that consist of the following items:
    - A [VBS_ENCLAVE_REPORT_VARDATA_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_vardata_header) structure
    - Data described by the [VBS_ENCLAVE_REPORT_VARDATA_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_vardata_header) structure
- A signature

The enclave attestation report provide proof that specific code is running with an enclave. If a validating entity also obtains proof that the host system is running with VBS turned on, that entity can use that proof in conjunction with the enclave attestation report to verify that a specific enclave, populated with specific code, has been loaded.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[EnclaveVerifyAttestationReport](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaveverifyattestationreport)

[VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report)

[VBS_ENCLAVE_REPORT_PKG_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_pkg_header)

[VBS_ENCLAVE_REPORT_VARDATA_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_vardata_header)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)