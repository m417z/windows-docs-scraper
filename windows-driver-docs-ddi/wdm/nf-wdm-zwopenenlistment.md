# ZwOpenEnlistment function

## Description

The **ZwOpenEnlistment** routine obtains a handle to an existing [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Parameters

### `EnlistmentHandle` [out]

A pointer to a caller-allocated variable that receives a handle to an enlistment object if the call to **ZwOpenEnlistment** succeeds.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies the requested access to the enlistment object. For more information about how to specify this parameter, see the *DesiredAccess* parameter of [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). This parameter cannot be zero.

### `RmHandle` [in]

A handle to a resource manager object that was obtained by a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager).

### `EnlistmentGuid` [in]

A pointer to a GUID that identifies the enlistment. For more information, see the following Remarks section.

### `ObjectAttributes` [in, optional]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object's attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure, but specify only that routine's *InitializedAttributes* and *Attributes* parameters. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE flag in the *Attributes* parameter. This parameter is optional and can be **NULL**.

## Return value

**ZwOpenEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |
| **STATUS_INVALID_PARAMETER** | The *DesiredAccess* parameter's value is zero, or the *EnlistmentGuid* parameter's value is **NULL**. |
| **STATUS_ENLISTMENT_NOT_FOUND** | The enlistment that the *EnlistmentGuid* parameter specifies does not exist for the resource manager that the *RmHandle* parameter specifies. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Typically, a TPS component calls **ZwOpenEnlistment** after it receives an enlistment GUID from another TPS component that had previously called [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). Most TPS designs do not require calling **ZwOpenEnlistment**.

A resource manager that calls **ZwOpenEnlistment** must eventually call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the object handle.

For more information about **ZwOpenEnlistment**, see [Enlistment Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

**NtOpenEnlistment** and **ZwOpenEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)

[ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment)