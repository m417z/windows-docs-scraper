# SpUserModeInitializeFn callback function

## Description

The **SpUserModeInitialize** function is called when a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)/[authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (SSP/AP) DLL is loaded into the process space of a client/server application. This function provides the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) tables for each [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in the SSP/AP DLL.

## Parameters

### `LsaVersion` [in]

The version of the security provider DLL (either Secur32.dll or Security.dll).

### `PackageVersion` [out]

Pointer that returns the version of the SSP/AP DLL.

### `ppTables` [out]

Pointer that returns an array of
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structures. Each structure is a table of pointers to the user-mode functions implemented by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) deployed in the SSP/AP DLL.

### `pcTables` [out]

Pointer that returns the number of elements in the array pointed to by the *ppTables* parameter.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

The **SpUserModeInitialize** function must be implemented by SSP/AP DLLs that contain user-mode security packages.

The *ppTables* parameter should contain one
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) for each user-mode security package deployed in the DLL. For more information on deploying security packages in DLLs, see
[User Mode Initialization](https://learn.microsoft.com/windows/desktop/SecAuthN/user-mode-initialization).

## See also

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)