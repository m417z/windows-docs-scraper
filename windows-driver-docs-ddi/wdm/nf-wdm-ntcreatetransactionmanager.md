# NtCreateTransactionManager function

## Description

The **ZwCreateTransactionManager** routine creates a new transaction manager object.

## Parameters

### `TmHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the new [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the transaction manager object. In addition to the access rights that are defined for all kinds of objects (see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)), the caller can specify any of the following access right flags for transaction manager objects.

| ACCESS_MASK flag | Allows the caller to |
| --- | --- |
| TRANSACTIONMANAGER_CREATE_RM | Create a resource manager (see [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)). |
| TRANSACTIONMANAGER_QUERY_INFORMATION | Obtain information about the transaction manager (see [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) and [ZwEnumerateTransactionObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntenumeratetransactionobject)). Also required for [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager), [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction), and [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction).) |
| TRANSACTIONMANAGER_RECOVER | Recover the transaction manager (see [ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager) and [ZwRollforwardTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollforwardtransactionmanager)). |
| TRANSACTIONMANAGER_RENAME | Not used. |
| TRANSACTIONMANAGER_SET_INFORMATION | Not used. |

Alternatively, you can specify one or more of the following [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) bitmaps. These bitmaps combine the flags from the previous table with the STANDARD_RIGHTS_*XXX* flags that are described on the **ACCESS_MASK** reference page. You can also combine these bitmaps with additional flags from the preceding table. The following table shows how the bitmaps correspond to specific access rights.

| Rights bitmap | Set of specific access rights |
| --- | --- |
| TRANSACTIONMANAGER_GENERIC_READ | STANDARD_RIGHTS_READ and TRANSACTIONMANAGER_QUERY_INFORMATION |
| TRANSACTIONMANAGER_GENERIC_WRITE | STANDARD_RIGHTS_WRITE, TRANSACTIONMANAGER_SET_INFORMATION, TRANSACTIONMANAGER_RECOVER, TRANSACTIONMANAGER_RENAME, and TRANSACTIONMANAGER_CREATE_RM |
| TRANSACTIONMANAGER_GENERIC_EXECUTE | STANDARD_RIGHTS_EXECUTE |
| TRANSACTIONMANAGER_ALL_ACCESS | STANDARD_RIGHTS_REQUIRED, TRANSACTIONMANAGER_GENERIC_READ, TRANSACTIONMANAGER_GENERIC_WRITE, and TRANSACTIONMANAGER_GENERIC_EXECUTE |

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `LogFileName` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path and file name of a [CLFS log file stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-log-streams-with-ktm) to be associated with the transaction manager object. This parameter must be **NULL** if the *CreateOptions* parameter is TRANSACTION_MANAGER_VOLATILE. Otherwise, this parameter must be non-**NULL**. For more information, see the following Remarks section.

### `CreateOptions` [in, optional]

Optional object creation flags. The following table contains the available flags, which are defined in Ktmtypes.h.

| Option flag | Meaning |
| --- | --- |
| TRANSACTION_MANAGER_VOLATILE | The transaction manager object will be volatile. Therefore, it will not use a log file. |
| TRANSACTION_MANAGER_COMMIT_DEFAULT | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_LOWEST | For internal use only. |
| TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY | For internal use only. |
| TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS | For internal use only. |

### `CommitStrength` [in, optional]

Reserved for future use. This parameter must be zero.

## Return value

**ZwCreateTransactionManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The value of an input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | KTM could not allocate system resources (typically memory). |
| **STATUS_LOG_CORRUPTION_DETECTED** | KTM encountered an error while creating or opening the log file. |
| **STATUS_INVALID_ACL** | A security descriptor contains an invalid access control list (ACL). |
| **STATUS_INVALID_SID** | A security descriptor contains an invalid security identifier (SID). |
| **STATUS_OBJECT_NAME_EXISTS** | The object name that the *ObjectAttributes* parameter specifies already exists. |
| **STATUS_OBJECT_NAME_COLLISION** | The operating system detected a duplicate object name. The error might indicate that the log stream is already being used. |
| **STATUS_OBJECT_NAME_INVALID** | The object name that the *ObjectAttributes* parameter specifies is invalid. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

If the log file stream that the *LogFileName* parameter specifies does not exist, KTM calls CLFS to create the stream. If the stream already exists, KTM calls CLFS to open the stream.

Your TPS component must call [ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager) after it has called **ZwCreateTransactionManager**

If your TPS component specifies the TRANSACTION_MANAGER_VOLATILE flag in the *CreateOptions* parameter, all resource managers that are associated with the transaction manager object must specify the RESOURCE_MANAGER_VOLATILE flag when they call [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager).

A TPS component that calls **ZwCreateTransactionManager** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

For more information about how use **ZwCreateTransactionManager**, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtCreateTransactionManager** and **ZwCreateTransactionManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)

[ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager)

[ZwRollforwardTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollforwardtransactionmanager)