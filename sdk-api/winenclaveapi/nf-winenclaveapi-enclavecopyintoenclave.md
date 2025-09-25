## Description

Copies data from an untrusted address (outside of the enclave) into the enclave.

## Parameters

### `EnclaveAddress`

An address within the enclave to which to copy data.

### `UnsecureAddress`

An address outside of the enclave from which to copy data.

### `NumberOfBytes`

The number of bytes to copy.

## Return value

An HRESULT value that indicates success or failure. The function returns `S_OK` if the copy operation was successful. Otherwise, it returns an HRESULT error code.

## Remarks

Note that the [EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave) and **EnclaveCopyIntoEnclave** APIs will still continue to work (and access the address space of the containing process) even when access is restricted using [EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess).

## See also

[EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave)

[EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess)