# NtCreateEnlistment function

## Description

The **ZwCreateEnlistment** routine creates a new [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) for a transaction.

## Parameters

### `EnlistmentHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the new enlistment object if the call to **ZwCreateEnlistment** succeeds.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the enlistment object. In addition to the access rights that are defined for all kinds of objects (see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)), the caller can specify any of the following access right flags for enlistment objects:

| ACCESS_MASK flag | Allows the caller to |
| --- | --- |
| ENLISTMENT_QUERY_INFORMATION | Query information about the enlistment (see [ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)). |
| ENLISTMENT_SET_INFORMATION | Set information for the enlistment (see [ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment)). |
| ENLISTMENT_RECOVER | Recover the enlistment (see [ZwRecoverEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverenlistment)). |
| ENLISTMENT_SUBORDINATE_RIGHTS | Perform operations that a resource manager that is not superior performs (see [ZwRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackenlistment), [ZwPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepreparecomplete), [ZwPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreparecomplete), [ZwCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitcomplete), [ZwRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackcomplete), [ZwSinglePhaseReject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsinglephasereject), [ZwReadOnlyEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntreadonlyenlistment)). |
| ENLISTMENT_SUPERIOR_RIGHTS | Perform operations that a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) must perform (see [ZwPrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepareenlistment), [ZwPrePrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreprepareenlistment), [ZwCommitEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitenlistment)). |

Alternatively, you can specify one or more of the following [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) bitmaps. These bitmaps combine the flags from the previous table with the STANDARD_RIGHTS_*XXX* flags that are described on the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) reference page. You can also combine these bitmaps together with additional flags from the previous table. The following table shows how the bitmaps correspond to specific access rights.

| Generic access right | Set of specific access rights |
| --- | --- |
| ENLISTMENT_GENERIC_READ | STANDARD_RIGHTS_READ and ENLISTMENT_QUERY_INFORMATION |
| ENLISTMENT_GENERIC_WRITE | STANDARD_RIGHTS_WRITE, ENLISTMENT_SET_INFORMATION, ENLISTMENT_RECOVER, ENLISTMENT_REFERENCE, ENLISTMENT_SUBORDINATE_RIGHTS, and ENLISTMENT_SUPERIOR_RIGHTS |
| ENLISTMENT_GENERIC_EXECUTE | STANDARD_RIGHTS_EXECUTE, ENLISTMENT_RECOVER, ENLISTMENT_SUBORDINATE_RIGHTS, and ENLISTMENT_SUPERIOR_RIGHTS |
| ENLISTMENT_ALL_ACCESS | STANDARD_RIGHTS_REQUIRED, ENLISTMENT_GENERIC_READ, ENLISTMENT_GENERIC_WRITE, and ENLISTMENT_GENERIC_EXECUTE |

### `ResourceManagerHandle` [in]

A handle to the caller's [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects) that was obtained by a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager).

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects) that was obtained by a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction). KTM adds this transaction to the list of transactions that the calling resource manager is handling.

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `CreateOptions` [in, optional]

Enlistment option flags. The following table contains the only available flag.

| *CreateOptions* flag | Meaning |
| --- | --- |
| ENLISTMENT_SUPERIOR | The caller is enlisting as a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) for the specified transaction. |

This parameter is optional and can be zero.

### `NotificationMask` [in]

A bitwise OR of TRANSACTION_NOTIFY_*XXX* values that are defined in Ktmtypes.h. This mask specifies the types of [transaction notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications) that KTM sends to the caller.

### `EnlistmentKey` [in, optional]

A pointer to caller-defined information that uniquely identifies the enlistment. The resource manager receives this pointer when it calls [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) or when KTM calls the [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. The resource manager can maintain a reference count for this key by calling [TmReferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmreferenceenlistmentkey) and [TmDereferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmdereferenceenlistmentkey). This parameter is optional and can be **NULL**.

## Return value

**ZwCreateEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_INVALID_PARAMETER** | The *CreateOptions* or *NotificationMask* parameter's value is invalid, or KTM could not find the transaction that the *TransactionHandle* parameter specifies. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation failed. |
| **STATUS_TRANSACTIONMANAGER_NOT_ONLINE** | The enlistment failed because KTM or the resource manager is not in an operational state. |
| **STATUS_TRANSACTION_NOT_ACTIVE** | The enlistment failed because the transaction that the *TransactionHandle* parameter specifies is not active. |
| **STATUS_TRANSACTION_SUPERIOR_EXISTS** | The caller tried to register as a superior transaction manager but a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) already exists. |
| **STATUS_TM_VOLATILE** | The caller is trying to register as a superior transaction manager, but the caller's resource manager object is [volatile](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager) while the associated transaction manager object is not volatile. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A resource manager calls **ZwCreateEnlistment** to enlist in a transaction.

Resource managers that are not superior must include the ENLISTMENT_SUBORDINATE_RIGHTS flag in their access mask.

[Superior transaction managers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) must include the ENLISTMENT_SUPERIOR_RIGHTS flag in their access masks. Typically, a superior transaction manager includes code that calls [ZwRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackenlistment), so it must also include the ENLISTMENT_SUBORDINATE_RIGHTS flag.

A resource manager that calls **ZwCreateEnlistment** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

Your resource manager can use the *EnlistmentKey* parameter to assign a unique value to each enlistment, such as a pointer to a data structure that contains information about the enlistment. For example, if the resource manager stores the enlistment object's handle in the structure, the resource manager can do the following:

1. Call [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) to obtain a notification.
2. Obtain the enlistment key value from the [TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85)) structure.
3. Use the enlistment key to find the stored enlistment object handle.
4. Call routines that require the enlistment handle as input, such as [ZwCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitcomplete) or [ZwRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackcomplete).

For more information about **ZwCreateEnlistment**, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager) and [Creating a Superior Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85))

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitcomplete)

[ZwCommitEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitenlistment)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepreparecomplete)

[ZwPrePrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreprepareenlistment)

[ZwPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreparecomplete)

[ZwPrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepareenlistment)

[ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)

[ZwReadOnlyEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntreadonlyenlistment)

[ZwRecoverEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverenlistment)

[ZwRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackcomplete)

[ZwRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbackenlistment)

[ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment)

[ZwSinglePhaseReject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsinglephasereject)