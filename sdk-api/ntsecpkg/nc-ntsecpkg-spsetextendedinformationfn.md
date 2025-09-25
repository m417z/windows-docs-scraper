# SpSetExtendedInformationFn callback function

## Description

Sets extended information about the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `Class` [in]

A
[SECPKG_EXTENDED_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ne-ntsecpkg-secpkg_extended_information_class) enumeration value indicating the type of extended information.

### `Info` [in]

Pointer to a
[SECPKG_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_extended_information) structure containing the extended information set.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

To retrieve extended information, the
[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn) function is called.

An SSP/AP must implement the **SpSetExtendedInformation** function; however, the actual name given to the implementation is up to the package developer.

A pointer to the **SpSetExtendedInformation** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_extended_information)

[SECPKG_EXTENDED_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ne-ntsecpkg-secpkg_extended_information_class)

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa)

[SpGetExtendedInformation](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetextendedinformationfn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)