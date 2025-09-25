# RtlNtStatusToDosError function

## Description

The **RtlNtStatusToDosError** routine converts the specified NTSTATUS code to its equivalent system error code.

## Parameters

### `Status` [in]

The NTSTATUS code to be converted.

## Return value

**RtlNtStatusToDosError** returns the corresponding system error code. Error codes are defined in *Winerror.h*.

**RtlNtStatusToDosError** returns ERROR_MR_MID_NOT_FOUND when the specified NTSTATUS code does not have a corresponding system error code. For more information about system error codes, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

There is no function that provides the inverse functionality of **RtlNtStatusToDosError**, converting a system error code to its corresponding NTSTATUS code.