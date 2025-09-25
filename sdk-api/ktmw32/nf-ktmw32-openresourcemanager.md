# OpenResourceManager function

## Description

Opens an existing resource manager (RM).

## Parameters

### `dwDesiredAccess` [in]

The access requested for the RM. See [Resource Manager Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/resource-manager-access-masks) for a list of valid values.

### `TmHandle` [in]

A handle to the transaction manager.

### `ResourceManagerId` [in]

The identifier for this resource manager.

## Return value

If the function succeeds, the return value is a handle to the resource manager.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

Immediately after calling this function, you must call [RecoverResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recoverresourcemanager).

## See also

[CreateResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createresourcemanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[Resource Manager Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/resource-manager-access-masks)