# SpInstanceInitFn callback function

## Description

The **SpInstanceInit** function is called once for each [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) contained in an SSP/AP, when the SSP/AP is loaded into a client/server process. Security packages should use this function to perform any user mode-specific initialization.

## Parameters

### `Version` [in]

The version of the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA).

### `FunctionTable` [in]

Pointer to a
[SECPKG_DLL_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_dll_functions) structure containing the support functions that the security package can use in user-mode.

### `UserFunctions` [out]

This parameter is not used.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

The **SpInstanceInit** function is called once when the SSP/AP is loaded into the user-mode process, after the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function is called.

SSP/APs must implement the **SpInstanceInit** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpInstanceInit** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the [SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)