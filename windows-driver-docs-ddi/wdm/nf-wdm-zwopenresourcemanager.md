# ZwOpenResourceManager function

## Description

The **ZwOpenResourceManager** routine returns a handle to an existing [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Parameters

### `ResourceManagerHandle` [out]

A pointer to a caller-allocated variable that receives the resource manager handle if the call to **ZwOpenResourceManager** succeeds.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the resource manager object. For more information about how to specify this parameter, see the *DesiredAccess* parameter of [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager). This parameter cannot be zero.

### `TmHandle` [in]

A handle to a transaction manager object that was obtained by a previous call to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager).

### `ResourceManagerGuid` [in]

A pointer to the GUID that identifies the resource manager to open.

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object's attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure, but specify only that routine's *InitializedAttributes* and *Attributes* parameters. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE flag in the *Attributes* parameter. This parameter is optional and can be **NULL**.

## Return value

**ZwOpenResourceManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that *TmHandle* specifies is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | The handle that *TmHandle* specifies is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the specified transaction manager object. |
| **STATUS_INVALID_PARAMETER** | The *DesiredAccess* parameter is zero or the *ResourceManagerGuid* parameter is invalid. |
| **STATUS_RESOURCEMANAGER_NOT_FOUND** | The specified resource manager could not be found. |
| **STATUS_TRANSACTIONMANAGER_NOT_ONLINE** | The specified transaction manager is not online. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Typically, a TPS component calls **ZwOpenResourceManager** after it receives an enlistment GUID from another TPS component that had previously called [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager). Most TPS designs do not require calling **ZwOpenResourceManager**.

A resource manager that calls **ZwOpenResourceManager** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

For more information about **ZwOpenResourceManager**, see [KTM Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/ktm-objects).

**NtOpenResourceManager** and **ZwOpenResourceManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)