# LSA_CLOSE_SAM_USER callback function

## Description

The **CloseSamUser** function closes a handle to a Security Accounts Manager (SAM) user account.

## Parameters

### `UserHandle` [in]

A handle to the SAM user account previously opened using the
[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user) function.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason. The following table lists a common reason for failure and the error code that the function returns.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | The value specified for *UserHandle* is not valid or **NULL**. |

## Remarks

A pointer to the **CloseSamUser** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)