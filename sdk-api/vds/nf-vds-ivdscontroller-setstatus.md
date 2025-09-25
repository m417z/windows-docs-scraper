# IVdsController::SetStatus

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the status of a
controller to the specified value.

## Parameters

### `status` [in]

Values enumerated by [VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status).
Callers can pass in a subset of the possible enumeration values. Passing in
**VDS_CS_UNKNOWN** returns **E_INVALIDARG**.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The controller object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The controller is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## Remarks

This method enables you to set the status of a single controller. You can set the status of all the controllers
in a subsystem at once by calling the
[IVdsSubSystem::SetControllerStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-setcontrollerstatus)
method. Use the
[IVdsController::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getproperties)
method to get the current status of the controller.

Implementers are responsible for performing any necessary operations to get the status to the specified state.
For example, if the caller passes in **VDS_CS_OFFLINE** as the controller status, you might
need to first clear the cache for the controller.

## See also

[IVdsController](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdscontroller)

[IVdsController::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getproperties)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsSubSystem::SetControllerStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-setcontrollerstatus)

[VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status)