# SpMarshallSupplementalCredsFn callback function

## Description

The **SpMarshallSupplementalCreds** function converts [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from a public format into a format suitable for local procedure calls.

## Parameters

### `CredentialSize` [in]

Specifies the size of the supplemental credentials.

### `Credentials` [in]

Pointer to the supplemental credentials.

### `MarshalledCredSize` [out]

Pointer to the size of the *MarshalledCreds* buffer.

### `MarshalledCreds` [out]

Pointer that receives the address of the buffer containing the [serialized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials. Allocate the memory for this buffer by calling the
[AllocateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpMarshallSupplementalCreds** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpMarshallSupplementalCreds** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[AllocateHeap](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374721(v=vs.85))

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)