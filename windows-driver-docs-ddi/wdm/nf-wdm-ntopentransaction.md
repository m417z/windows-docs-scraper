# NtOpenTransaction function

## Description

The **ZwOpenTransaction** routine obtains a handle to an existing [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects).

## Parameters

### `TransactionHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the transaction object if **ZwOpenTransaction** returns STATUS_SUCCESS.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the transaction object. For information about how to specify this parameter, see the *DesiredAccess* parameter of [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction).

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object's attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure, but specify only that routine's *InitializedAttributes* and *Attributes* parameters. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE flag in the *Attributes* parameter. The *ObjectAttributes* parameter is optional and can be **NULL**.

### `Uow` [in]

A pointer to a GUID that is a transaction object's [unit of work (UOW) identifier](https://learn.microsoft.com/windows-hardware/drivers/kernel/ktm-objects). This GUID identifies the transaction object to open.

### `TmHandle` [in, optional]

A handle to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects). If this parameter is not **NULL**, KTM searches only for transaction objects that belong to the specified transaction manager object. If this parameter is **NULL**, KTM searches all transaction objects.

## Return value

**ZwCreateTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *DesiredAccess* or *Uow* parameter was zero. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_TRANSACTION_NOT_FOUND** | KTM could not find the transaction object. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Typically, a resource manager calls **ZwOpenTransaction** after it receives a transaction UOW from a transactional client that had previously called [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction).

For more information about **ZwOpenTransaction**, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtOpenTransaction** and **ZwOpenTransaction** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)

[ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction)