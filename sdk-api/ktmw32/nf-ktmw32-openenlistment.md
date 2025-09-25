# OpenEnlistment function

## Description

Opens an existing enlistment object, and returns a handle to the enlistment.

## Parameters

### `dwDesiredAccess` [in]

The access requested for this enlistment. See [Enlistment Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/enlistment-access-masks) for a list of valid values.

### `ResourceManagerHandle` [in]

A handle to the resource manager.

### `EnlistmentId` [in]

The enlistment identifier.

## Return value

If the function succeeds, the return value is a handle to the enlistment.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[CreateEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createenlistment)

[Enlistment Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/enlistment-access-masks)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)