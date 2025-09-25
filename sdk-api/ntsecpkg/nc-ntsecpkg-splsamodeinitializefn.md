# SpLsaModeInitializeFn callback function

## Description

The **SpLsaModeInitialize** function is called once by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) for each registered [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)/[authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (SSP/AP) DLL it loads. This function provides the LSA with pointers to the functions implemented by each [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in the SSP/AP DLL.

## Parameters

### `LsaVersion` [in]

The version of the LSA.

### `PackageVersion` [out]

Pointer to a **ULONG** that returns the SSP/AP DLL version number.

### `ppTables` [out]

Pointer to an array of
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structures. Each structure is a table of pointers to the functions implemented by a security package deployed in the SSP/AP DLL.

### `pcTables` [out]

Pointer that returns the number of elements in the array pointed to by the *ppTables* parameter.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

The **SpLsaModeInitialize** function must be implemented by SSP/AP DLLs.

The *ppTables* parameter should contain one
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) for each security package deployed in the DLL.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)