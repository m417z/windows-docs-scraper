# NtCreateResourceManager function

## Description

The **ZwCreateResourceManager** routine creates a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Parameters

### `ResourceManagerHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the new resource manager object if the call to **ZwCreateResourceManager** is successful.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the resource manager object. In addition to the access rights that are defined for all kinds of objects (see **ACCESS_MASK**), the caller can specify any of the following access right flags for resource manager objects:

| ACCESS_MASK flag | Allows the caller to |
| --- | --- |
| RESOURCEMANAGER_ENLIST | Enlist in transactions (see [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)). |
| RESOURCEMANAGER_GET_NOTIFICATION | Receive notifications about the transactions that are associated with this resource manager (see [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)). |
| RESOURCEMANAGER_REGISTER_PROTOCOL | Not used. |
| RESOURCEMANAGER_QUERY_INFORMATION | Query information about the resource manager (see [ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager)). |
| RESOURCEMANAGER_SET_INFORMATION | Not used. |
| RESOURCEMANAGER_RECOVER | Recover the resource manager (see [ZwRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverresourcemanager)). |
| RESOURCEMANAGER_COMPLETE_PROPAGATION | Not used. |

Alternatively, you can specify one or more of the following generic [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags. (The STANDARD_RIGHTS_*Xxx* flags are predefined system values that are used to enforce security on system objects.) You can also combine these generic flags with additional flags from the preceding table. The following table shows how generic access rights correspond to specific access rights.

| Generic access right | Set of specific access rights |
| --- | --- |
| RESOURCEMANAGER_GENERIC_READ | STANDARD_RIGHTS_READ, RESOURCEMANAGER_QUERY_INFORMATION, and SYNCHRONIZE |
| RESOURCEMANAGER_GENERIC_WRITE | STANDARD_RIGHTS_WRITE, RESOURCEMANAGER_SET_INFORMATION, RESOURCEMANAGER_RECOVER, RESOURCEMANAGER_ENLIST, RESOURCEMANAGER_GET_NOTIFICATION, RESOURCEMANAGER_REGISTER_PROTOCOL, RESOURCEMANAGER_COMPLETE_PROPAGATION, and SYNCHRONIZE |
| RESOURCEMANAGER_GENERIC_EXECUTE | STANDARD_RIGHTS_EXECUTE, RESOURCEMANAGER_RECOVER, RESOURCEMANAGER_ENLIST, RESOURCEMANAGER_GET_NOTIFICATION, RESOURCEMANAGER_COMPLETE_PROPAGATION, and SYNCHRONIZE |
| RESOURCEMANAGER_ALL_ACCESS | STANDARD_RIGHTS_REQUIRED, RESOURCEMANAGER_GENERIC_READ, RESOURCEMANAGER_GENERIC_WRITE, and RESOURCEMANAGER_GENERIC_EXECUTE |

### `TmHandle` [in]

A handle to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) that was obtained by a previous all to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager).

### `RmGuid` [in]

A pointer to a GUID that KTM will use to identify the resource manager. If this pointer is **NULL**, KTM generates a GUID.

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `CreateOptions` [in, optional]

Optional object creation flags. The following table contains the available flags, which are defined in Ktmtypes.h.

| *CreateOptions* flag | Meaning |
| --- | --- |
| RESOURCE_MANAGER_COMMUNICATION | For internal use only. |
| RESOURCE_MANAGER_VOLATILE | The caller will manage volatile resources. It will be non-persistent and will not perform recovery. |

This parameter is optional and can be zero.

### `Description` [in, optional]

A pointer to a caller-supplied [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a NULL-terminated string. The string provides a description of the resource manager. KTM stores a copy of the string and includes the string in messages that it writes to the log stream. The maximum string length is MAX_RESOURCEMANAGER_DESCRIPTION_LENGTH. This parameter is optional and can be **NULL**.

## Return value

**ZwCreateResourceManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that *TmHandle* specifies is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | The handle that *TmHandle* specifies is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the specified transaction manager object. |
| **STATUS_TRANSACTION_OBJECT_EXPIRED** | The handle that *TmHandle* specifies is closed. |
| **STATUS_INVALID_PARAMETER** | The *CreateOptions* parameter's value is invalid or the *Description* parameter's string is too long. |
| **STATUS_TM_VOLATILE** | The *CreateOptions* parameter does not specify RESOURCE_MANAGER_VOLATILE but the transaction manager that *TmHandle* specifies is volatile. |
| **STATUS_OBJECT_NAME_COLLISION** | The GUID that *ResourceManagerGuid* specifies already exists. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A resource manager that calls **ZwCreateResourceManager** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

For more information about **ZwCreateResourceManager**, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)

[ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager)

[ZwRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverresourcemanager)