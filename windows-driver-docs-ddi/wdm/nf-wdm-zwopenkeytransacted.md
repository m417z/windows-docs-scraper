# ZwOpenKeyTransacted function

## Description

The **ZwOpenKeyTransacted** routine opens an existing registry key and associates the key with a transaction.

## Parameters

### `KeyHandle` [out]

A pointer to a HANDLE variable into which the routine writes the handle to the key.

### `DesiredAccess` [in]

Specifies the type of access to the key that the caller requests. This parameter is an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value. For more information, see the description of the *DesiredAccess* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine.

### `ObjectAttributes` [in]

A pointer to the object attributes of the key being opened. This parameter points to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that must have been previously initialized by the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine. The caller must specify the name of the registry key as the *ObjectName* parameter in the call to **InitializeObjectAttributes**. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). To obtain this handle, you can call the [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) routine. Or, if you have a pointer to a transaction object, you can supply the pointer to the [ObOpenObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obopenobjectbypointer) routine to obtain the corresponding transaction handle.

## Return value

**ZwOpenKeyTransacted** returns STATUS_SUCCESS if the call successfully opens the key. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *ObjectAttributes* parameter is **NULL** or points to invalid information. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The registry path in the object attributes is invalid. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry path in the object attributes was not found. |
| **STATUS_ACCESS_DENIED** | The caller did not have the required access rights to open a handle for the named registry key. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation operation failed. |

## Remarks

This routine provides a handle with which the caller can access a registry key. Additionally, this routine associates the key with an active transaction.

After the handle that is pointed to by *KeyHandle* is no longer being used, the driver must call the [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) routine to close it.

If the specified key does not exist in the registry, **ZwOpenKeyTransacted** returns an error status value and does not supply a key handle. Unlike the [ZwCreateKeyTransacted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekeytransacted) routine, the **ZwOpenKeyTransacted** routine does not create the specified key if the key does not exist. Both **ZwCreateKeyTransacted** and **ZwOpenKeyTransacted** associate a registry key with a transaction.

The [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey) routine is similar to **ZwOpenKeyTransacted**, but does not associate a key with a transaction.

After a kernel-mode driver obtains a handle to a transaction (for example, by calling **ZwCreateTransaction**), the driver can perform a series of registry operations that are part of this transaction. The driver can close the transaction either by committing to the changes that were made in the transaction or by rolling back the transaction.

After the driver successfully completes all registry operations that are part of a transaction, it can call the [ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction) routine to commit to the changes. The driver can call the [ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction) routine to roll back the transaction.

During a transaction, a registry operation is part of the transaction if the system call that performs the operation meets either of the following conditions:

* The call specifies, as an input parameter, the transaction handle. For example, calls to **ZwCreateKeyTransacted** and **ZwOpenKeyTransacted** can associate one or more keys with the transaction.
* The call specifies, as an input parameter, a registry key handle that was obtained by a call to **ZwCreateKeyTransacted** or **ZwOpenKeyTransacted** to which the transaction handle was supplied. For example, a call to the [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey) routine can use a key handle that was obtained in this way to set the value of a registry key as part of a transaction.

For more information about kernel-mode transactions, see [Using Kernel Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-kernel-transaction-manager).

**ZwOpenKeyTransacted** ignores the security information in the structure that the *ObjectAttributes* parameter points to.

If the kernel-mode caller is not running in a system thread context, it must ensure that any handles it creates are kernel handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

For more information about how to work with registry keys in kernel mode, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[ObOpenObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obopenobjectbypointer)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwCreateKeyTransacted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekeytransacted)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwOpenKeyTransactedEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkeytransactedex)

[ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)