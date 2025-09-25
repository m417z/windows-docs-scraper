# NtCreateTransaction function

## Description

The **ZwCreateTransaction** routine creates a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects).

## Parameters

### `TransactionHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the new transaction object, if the call to **ZwCreateTransaction** succeeds.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the transaction object. In addition to the access rights that are defined for all kinds of objects (see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)), the caller can specify any of the following flags for transaction objects.

| Access mask | Allows the caller to |
| --- | --- |
| TRANSACTION_COMMIT | Commit the transaction (see [ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)). |
| TRANSACTION_ENLIST | Create an enlistment for the transaction (see [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)). |
| TRANSACTION_PROPAGATE | Do not use. |
| TRANSACTION_QUERY_INFORMATION | Obtain information about the transaction (see [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)). |
| TRANSACTION_ROLLBACK | Roll back the transaction (see [ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction)). |
| TRANSACTION_SET_INFORMATION | Set information for the transaction (see [ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction)). |

Alternatively, you can specify one or more of the following ACCESS_MASK bitmaps. These bitmaps combine the flags from the previous table with the STANDARD_RIGHTS_*XXX* flags that are described on the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) reference page. You can also combine these bitmaps with additional flags from the preceding table. The following table shows how the bitmaps correspond to specific access rights.

| Rights bitmap | Set of specific access rights |
| --- | --- |
| TRANSACTION_GENERIC_READ | STANDARD_RIGHTS_READ, TRANSACTION_QUERY_INFORMATION, and SYNCHRONIZE |
| TRANSACTION_GENERIC_WRITE | STANDARD_RIGHTS_WRITE, TRANSACTION_SET_INFORMATION, TRANSACTION_COMMIT, TRANSACTION_ENLIST, TRANSACTION_ROLLBACK, TRANSACTION_PROPAGATE, TRANSACTION_SAVEPOINT, and SYNCHRONIZE |
| TRANSACTION_GENERIC_EXECUTE | STANDARD_RIGHTS_EXECUTE, TRANSACTION_COMMIT, TRANSACTION_ROLLBACK, and SYNCHRONIZE |
| TRANSACTION_ALL_ACCESS | STANDARD_RIGHTS_REQUIRED, TRANSACTION_GENERIC_READ, TRANSACTION_GENERIC_WRITE, and TRANSACTION_GENERIC_EXECUTE |
| TRANSACTION_RESOURCE_MANAGER_RIGHTS | STANDARD_RIGHTS_WRITE, TRANSACTION_GENERIC_READ, TRANSACTION_SET_INFORMATION, TRANSACTION_ENLIST, TRANSACTION_ROLLBACK, TRANSACTION_PROPAGATE, and SYNCHRONIZE |

Typically, a resource manager specifies TRANSACTION_RESOURCE_MANAGER_RIGHTS.

The *DesiredAccess* value cannot be zero.

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `Uow` [in, optional]

A pointer to a GUID that KTM uses as the new transaction object's [unit of work (UOW) identifier](https://learn.microsoft.com/windows-hardware/drivers/kernel/ktm-objects). This parameter is optional and can be **NULL**. If this parameter is **NULL**, KTM generates a GUID and assigns it to the transaction object. For more information, see the following Remarks section.

### `TmHandle` [in, optional]

A handle to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) that was obtained by a previous call to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager). KTM assigns the new transaction object to the specified transaction manager object. If this parameter is **NULL**, KTM assigns the new transaction object to a transaction manager later, when a resource manager creates an enlistment for the transaction.

### `CreateOptions` [in, optional]

Optional object creation flags. The following table contains the available flags, which are defined in Ktmtypes.h.

| Option flag | Meaning |
| --- | --- |
| TRANSACTION_DO_NOT_PROMOTE | Reserved for future use. |

### `IsolationLevel` [in, optional]

Reserved for future use. Callers must set this parameter to zero.

### `IsolationFlags` [in, optional]

Reserved for future use. Callers should set this parameter to zero.

### `Timeout` [in, optional]

A pointer to a time-out value. If the transaction has not been committed by the time specified by this parameter, KTM rolls back the transaction. The time-out value is expressed in system time units (100-nanosecond intervals), and can specify either an absolute time or a relative time. If the value pointed to by *Timeout* is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. This pointer is optional and can be **NULL** if you do not want the transaction to have a time-out value. If *Timeout* = **NULL** or **Timeout* = 0, the transaction never times out. (You can also use [ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction) to set a time-out value.)

### `Description` [in, optional]

A pointer to a caller-supplied [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a NULL-terminated string. The string provides a description of the transaction. KTM stores a copy of the string and includes the string in messages that it writes to the log stream. The maximum string length is MAX_TRANSACTION_DESCRIPTION_LENGTH. This parameter is optional and can be **NULL**.

## Return value

**ZwCreateTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *CreateOptions* parameter contains an invalid flag, the *DesiredAccess* parameter is zero, or the *Description* parameter's string is too long. |
| **STATUS_INSUFFICIENT_RESOURCES** | KTM could not allocate system resources (typically memory). |
| **STATUS_INVALID_ACL** | A security descriptor contains an invalid access control list (ACL). |
| **STATUS_INVALID_SID** | A security descriptor contains an invalid security identifier (SID). |
| **STATUS_OBJECT_NAME_EXISTS** | The object name that the *ObjectAttributes* parameter specifies already exists. |
| **STATUS_OBJECT_NAME_INVALID** | The object name that the *ObjectAttributes* parameter specifies is invalid. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The caller can use the *Uow* parameter to specify a UOW identifier for the transaction object. If the caller does not specify a UOW identifier, KTM generates a GUID and assigns it to the transaction object. The caller can later obtain this GUID by calling [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction).

Typically, you should let KTM generate a GUID for the transaction object, unless your component communicates with another TPS component that has already generated a UOW identifier for the transaction.

To close the transaction handle, the component that called **ZwCreateTransaction** must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose). If the last transaction handle closes before any component calls [ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction) for the transaction, KTM rolls back the transaction.

For more information about how transaction clients should use **ZwCreateTransaction**, see [Creating a Transactional Client](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-transactional-client).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)

[ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction)

[ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction)