## Description

Restricts (or restores) access by an enclave to the address space of its containing process. This policy applies to all threads in the enclave.

## Parameters

### `RestrictAccess`

Set this value to `TRUE` if the process should restrict (i.e. disable) access to the address space of the containing process. Otherwise, set it to `FALSE` if restrictions should be relaxed, and the containing address space should be accessible.

### `PreviouslyRestricted`

A pointer to a variable that will receive the previous state of the restriction.

## Return value

An `HRESULT` value that indicates the success or failure of the operation.

## Remarks

When access is restricted, attempting to access the address space of the containing process from the enclave will result in an access violation. However, even when access is restricted, the [EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave) and [EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave) APIs continue to permit access to the address space of the containing process.

Access to the containing process's address space can also be restricted by setting the [IMAGE_ENCLAVE_POLICY_STRICT_MEMORY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_enclave_config64#-field-enclaveflags) flag in the enclave's image configuration. The **EnclaveRestrictContainingProcessAccess** API can be used to change this policy at runtime.

## See also

[EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave)

[EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave)