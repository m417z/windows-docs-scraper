# RtlNtStatusToDosError function

## Description

Converts the specified NTSTATUS code to its equivalent system error code.

## Parameters

### `Status` [in]

The NTSTATUS code to be converted.

## Return value

The function returns the corresponding [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

There is no function that provides the inverse functionality of **RtlNtStatusToDosError**, which would convert a system error code to its corresponding NTSTATUS code.

ERROR_MR_MID_NOT_FOUND is returned when the specified NTSTATUS code does not have a corresponding system error code.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)