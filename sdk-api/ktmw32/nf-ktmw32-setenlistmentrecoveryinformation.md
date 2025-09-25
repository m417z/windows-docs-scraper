# SetEnlistmentRecoveryInformation function

## Description

 Sets an opaque, user-defined structure of recovery data from KTM. Recovery information is stored in a log on behalf of a resource manager (RM) by calling **SetEnlistmentRecoveryInformation**. After a failure, the RM can use [GetEnlistmentRecoveryInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getenlistmentrecoveryinformation) to retrieve the information.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `BufferSize` [in]

The size of *Buffer*, in bytes.

### `Buffer` [in]

The recovery information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

This call cannot be used with volatile transaction managers.

The information that is provided by the user may not be durably stored in the log at the completion of this operation, but it will be durably stored by the end of the next commit operation for this enlistment.

## See also

[GetEnlistmentRecoveryInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getenlistmentrecoveryinformation)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)