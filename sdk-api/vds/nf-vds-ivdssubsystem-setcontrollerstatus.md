# IVdsSubSystem::SetControllerStatus

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets
the status (either online or offline) of the controllers in the subsystem.

## Parameters

### `pOnlineControllerIdArray` [in]

Pointer to an array of controller GUIDs. The provider sets these controllers to online. This array includes
controllers already set to online that are to remain so.

### `lNumberOfOnlineControllers` [in]

The number of controllers specified in
*pOnlineControllersArray*.

### `pOfflineControllerIdArray` [in]

Pointer to an array of controller GUIDs. The provider sets these controllers to offline. This array includes
controllers already set to offline that are to remain so.

### `lNumberOfOfflineControllers` [in]

The number of controllers specified in *pOfflineControllersArray*.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The subsystem object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The subsystem is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | Can be returned from any method that takes a **VDS_OBJECT_ID** constant. This return value indicates that the identifier does not refer to an existing object. |

## Remarks

This method enables a caller to set the status of all controllers at once. Use the
[IVdsController::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-setstatus) method to set the
status of a single controller.

Callers must pass the complete set of controllers in either the *pOnlineControllerIdArray*
or *pOfflineControllerIdArray* parameter for each method call. The
**E_INVALIDARG** return value can indicate that not all controllers in the subsystem have
been specified in the arguments to this method.
The **SetControllerStatus** method requires that
all controllers in the subsystem be present in one of the two arrays supplied.

## See also

[IVdsController::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-setstatus)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsSubSystem](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystem)