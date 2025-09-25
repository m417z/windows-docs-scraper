# SpInitializeFn callback function

## Description

The **SpInitialize** function is called once by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) to provide a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with general security information and a dispatch table of support functions. The security package should save the information and do internal initialization processing, if any is needed.

## Parameters

### `PackageId` [in]

A unique identifier the LSA assigns to each security package. The value is valid until the system is restarted.

### `Parameters` [in]

A pointer to a
[SECPKG_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_parameters) structure containing primary domain and machine state information.

### `FunctionTable` [in]

Pointer to a table of LSA support functions that a security package can call.

## Return value

If the function succeeds, return STATUS_SUCCESS, or an informational status code.

If the function fails, return an NTSTATUS error code indicating the reason it failed. For more information, see Remarks.

## Remarks

If **SpInitialize** returns an NTSTATUS error code to the LSA, the package will be unloaded, and the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) will not include it in the list of available security packages.

SSP/APs must implement the **SpInitialize** function; however, the actual name given to the implementation is up to the developer.

A pointer to the SSP/AP's implementation of the **SpInitialize** function must be in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure passed to the LSA from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SECPKG_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_parameters)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)