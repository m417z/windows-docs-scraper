# CreateResourceManager function

## Description

Creates a new resource manager (RM) object, and associates the RM with a transaction manager (TM).

## Parameters

### `lpResourceManagerAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that contains the security attributes for the resource manager. Specify **NULL** to obtain the default attributes.

### `ResourceManagerId` [in]

A pointer the resource manager GUID. This parameter is required and must not be **NULL**.

### `CreateOptions` [in, optional]

Any optional attributes for the new RM.

| Value | Meaning |
| --- | --- |
| **RESOURCE_MANAGER_VOLATILE** | Indicates that the RM is volatile, and does not perform recovery. |

### `TmHandle` [in]

A handle to the TM that will manage the transactions for this RM.

### `Description` [in, optional]

A description for this RM.

## Return value

If the function succeeds, the return value is a handle to the RM.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

Immediately after calling this function, you must call [RecoverResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recoverresourcemanager).

An RM is an endpoint for TM notifications regarding transactions that the RM has enlisted in.

RMs are typically persistent, meaning that after a system failure, they must be reopened to perform certain operations. Volatile, or transient, RMs can be created by calling the **CreateResourceManager** function and by specifying RESOURCE_MANAGER_VOLATILE. Volatile RMs do not perform recovery operations, but do require notifications about a transaction.

You can create a volatile RM on a durable TM, but you cannot create a durable RM on a volatile TM.

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-openresourcemanager)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetResourceManagerCompletionPort](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-setresourcemanagercompletionport)