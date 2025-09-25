# ZwOpenTransactionManager function

## Description

The **ZwOpenTransactionManager** routine obtains a handle to an existing transaction manager object.

## Parameters

### `TmHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) if **ZwOpenTransactionManager** returns STATUS_SUCCESS.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the transaction manager object. For information about how to specify this parameter, see the *DesiredAccess* parameter of [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager).

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `LogFileName` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path and file name of the [log file stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-log-streams-with-ktm) that was created when the transaction manager object was created. For more information, see the *LogFileName* parameter of **ZwCreateTransactionManager**. This parameter is optional and can be **NULL**.

### `TmIdentity` [in, optional]

A pointer to a GUID that identifies the transaction manager object. This parameter is optional and can be **NULL**.

### `OpenOptions` [in, optional]

This parameter is not used and must be zero.

## Return value

**ZwOpenTransactionManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The value of an input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | KTM could not allocate system resources (typically memory). |
| **STATUS_OBJECT_NAME_INVALID** | The object name that the *ObjectAttributes* parameter specifies is invalid. |
| **STATUS_LOG_CORRUPTION_DETECTED** | KTM encountered an error while creating or opening the log file. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The caller can identify which transaction manager object to open by using one of the following three techniques:

* Use the *LogFileName* parameter to specify the path and file name of a log file stream that was created when the transaction manager object was created.
* Use the *TmIdentity* parameter to specify the GUID that identifies the transaction manager object.
* Use the *ObjectAttributes* parameter to supply an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that contains the object name that the caller previously specified to the [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) routine.

You must specify only one of the above-listed parameters (an object name, a log file name, or a GUID) and set the other two parameters to **NULL**.

Your TPS component must call [ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager) after it has called **ZwOpenTransactionManager**.

A TPS component that calls **ZwOpenTransactionManager** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

For more information about how to use **ZwOpenTransactionManager**, see [Transaction Manager Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) and [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtOpenTransactionManager** and **ZwOpenTransactionManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)