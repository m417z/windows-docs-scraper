# LSA_MAP_BUFFER callback function

## Description

The **MapBuffer** function maps a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure into the address space of the [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)/[authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (SSP/AP).

## Parameters

### `InputBuffer` [in]

Pointer to the
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure to map.

### `OutputBuffer` [out]

Pointer that receives the address of the mapped
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed.

## Remarks

If the
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) has already been mapped, the **MapBuffer** function copies the contents of the input buffer over the output buffer.

A pointer to the **MapBuffer** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)