# LSA_CLIENT_CALLBACK callback function

## Description

The **ClientCallback** function allows a [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA)-mode [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to call back to its user-mode package and invoke a function in its DLL there.

## Parameters

### `Callback` [in]

A pointer to the name of the function to invoke. For more information, see [ClientCallback_Function](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374759(v=vs.85)).

### `Argument1` [in]

A pointer to the first argument to pass to the callback function.

### `Argument2` [in]

A pointer to the second argument to pass to the callback function.

### `Input` [in]

A pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that contains information to pass to the callback function.

### `Output` [out]

A pointer to a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives information passed from the callback function.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code that indicates the reason it failed.

## Remarks

A pointer to the **ClientCallback** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

The user-mode security package must use the
[RegisterCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa379372(v=vs.85)) function to register the function to be called.

## See also

[ClientCallback_Function](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374759(v=vs.85))

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[RegisterCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa379372(v=vs.85))

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)