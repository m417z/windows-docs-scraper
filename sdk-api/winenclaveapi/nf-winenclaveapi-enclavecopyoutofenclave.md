## Description

Copies data from the enclave to an untrusted address (outside of the enclave).

## Parameters

### `UnsecureAddress`

An address outside of the enclave to which to copy data.

### `EnclaveAddress`

An address within the enclave from which to copy data.

### `NumberOfBytes`

The number of bytes to copy.

## Return value

An HRESULT value that indicates success or failure. The function returns `S_OK` if the copy operation was successful. Otherwise, it returns an HRESULT error code.

## Remarks

Note that the **EnclaveCopyOutOfEnclave** and [EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave) APIs will still continue to work (and access the address space of the containing process) even when access is restricted using [EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess).

## See also

[EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave)

[EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess)