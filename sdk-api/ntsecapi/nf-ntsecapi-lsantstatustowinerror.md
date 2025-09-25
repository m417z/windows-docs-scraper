# LsaNtStatusToWinError function

## Description

The **LsaNtStatusToWinError** function converts an NTSTATUS code returned by an LSA function to a Windows error code.

## Parameters

### `Status` [in]

An NTSTATUS code returned by an LSA function call. This value will be converted to a
[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Return value

The return value is the Windows error code that corresponds to the *Status* parameter. If there is no corresponding Windows error code, the return value is ERROR_MR_MID_NOT_FOUND.

## See also

[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values)