# NtQueryInformationResourceManager function

## Description

The **ZwQueryInformationResourceManager** routine retrieves information about a specified [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Parameters

### `ResourceManagerHandle` [in]

A handle to a resource manager object that was obtained by a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager). The handle must have RESOURCEMANAGER_QUERY_INFORMATION access to the object.

### `ResourceManagerInformationClass` [in]

A [RESOURCEMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_resourcemanager_information_class)-typed value that specifies the information to retrieve. This value must be **ResourceManagerBasicInformation**.

### `ResourceManagerInformation` [out]

A pointer to a caller-allocated [RESOURCEMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_basic_information) structure that receives information from **ZwQueryInformationResourceManager**.

### `ResourceManagerInformationLength` [in]

The length, in bytes, of the buffer that the *ResourceManagerInformation* parameter points to.

### `ReturnLength` [out, optional]

A pointer to a caller-allocated variable that receives the length, in bytes, of the information that KTM writes to the *ResourceManagerInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**ZwQueryInformationResourceManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a resource manager object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_INVALID_INFO_CLASS** | The *ResourceManagerInformationClass* parameter's value is invalid. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer size that the *ResourceManagerInformationLength* parameter specifies is smaller than the RESOURCEMANAGER_BASIC_INFORMATION structure. |
| **STATUS_BUFFER_OVERFLOW** | The buffer size that the *ResourceManagerInformationLength* parameter specifies is too small to receive all the variable-length information that is available. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the resource manager object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about the **ZwQueryInformationResourceManager** routine, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtQueryInformationResourceManager** and **ZwQueryInformationResourceManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[RESOURCEMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_basic_information)

[RESOURCEMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_resourcemanager_information_class)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverresourcemanager)

[ZwSetInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationresourcemanager)