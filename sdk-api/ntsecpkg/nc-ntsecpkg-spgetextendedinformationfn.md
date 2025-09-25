# SpGetExtendedInformationFn callback function

## Description

The **SpGetExtendedInformation** function provides extended information about a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `Class` [in]

A value from the
[SECPKG_EXTENDED_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ne-ntsecpkg-secpkg_extended_information_class) enumeration indicating the type of extended information.

### `ppInformation` [out]

Pointer to a pointer to a
[SECPKG_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_extended_information) structure allocated by the security package. If the function call succeeds, the returned structure contains the requested information.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

Extended information is set using the
[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn) function.

An SSP/AP must implement the **SpGetExtendedInformation** function; however, the actual name given to the implementation is up to the package developer.

A pointer to the **SpGetExtendedInformation** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_extended_information)

[SECPKG_EXTENDED_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ne-ntsecpkg-secpkg_extended_information_class)

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)

[SpSetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spsetextendedinformationfn)