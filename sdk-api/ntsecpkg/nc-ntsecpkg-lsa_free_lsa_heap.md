# LSA_FREE_LSA_HEAP callback function

## Description

The **FreeReturnBuffer** function is used to free buffers allocated by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) and returned to the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The package calls this function when the information in the returned buffer is no longer needed.

## Parameters

### `Base` [in]

Pointer to the buffer to free.

## Remarks

A pointer to the **FreeReturnBuffer** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)