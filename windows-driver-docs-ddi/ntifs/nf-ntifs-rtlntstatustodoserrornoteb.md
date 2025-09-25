# RtlNtStatusToDosErrorNoTeb function

## Description

The **RtlNtStatusToDosErrorNoTeb** routine converts the specified NTSTATUS code to its equivalent system error code. Reserved for system use.

## Parameters

### `Status` [in]

The NTSTATUS code to be converted.

## Return value

**RtlNtStatusToDosErrorNoTeb** returns the corresponding system error code. Error codes are defined in *Winerror.h*. For more information about system error codes, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

There is no function that provides the inverse functionality of **RtlNtStatusToDosErrorNoTeb**, converting a system error code to its corresponding NTSTATUS code.