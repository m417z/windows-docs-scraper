# SpGetInfoFn callback function

## Description

The **SpGetInfo** function provides general information about the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), such as its name and capabilities.

The **SpGetInfo** function is called when the client calls the
[QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `PackageInfo` [out]

Pointer to a
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure that is allocated by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) and must be populated by the package.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

It is safe to place pointers to constant or dynamic data into the
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure—the LSA will make a copy of the data prior to forwarding it.

SSP/APs must implement the **SpGetInfo** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpGetInfo** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)