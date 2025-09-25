# ZwRecoverResourceManager function

## Description

The **ZwRecoverResourceManager** routine tries to recover the transaction that is associated with each enlistment of a specified [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Parameters

### `ResourceManagerHandle` [in]

A handle to a resource manager object that was obtained by a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager). The handle must have RESOURCEMANAGER_RECOVER access to the object.

## Return value

**ZwRecoverResourceManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a resource manager object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_TRANSACTIONMANAGER_NOT_ONLINE** | The transaction manager that is associated with the specified resource manager is not available. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the resource manager object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

When a resource manager calls **ZwRecoverResourceManager**, KTM sends a TRANSACTION_NOTIFY_RECOVER notification to the resource manager for each of the resource manager's enlistments. (If the enlistment is a superior enlistment, KTM sends TRANSACTION_NOTIFY_RECOVER_QUERY instead of TRANSACTION_NOTIFY_RECOVER.)

The final notification that KTM sends to the resource manager is TRANSACTION_NOTIFY_LAST_RECOVER.

For more information about **ZwRecoverResourceManager**, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

**NtRecoverResourceManager** and **ZwRecoverResourceManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TmRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmrecoverresourcemanager)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager)

[ZwSetInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationresourcemanager)