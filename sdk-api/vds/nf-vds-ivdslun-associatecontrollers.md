# IVdsLun::AssociateControllers

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the subsystem controllers to active or inactive with respect to the LUN.

## Parameters

### `pActiveControllerIdArray` [in]

A pointer to an array of controller GUIDs. The provider sets these controllers to active. This array
includes controllers already set to active that are to remain so.

### `lNumberOfActiveControllers` [in]

The number of controllers specified in the *pActiveControllerArray* parameter.

### `pInactiveControllerIdArray` [in]

A pointer to an array of controller GUIDs. The provider sets these controllers to inactive. This array
includes controllers already set to inactive that are to remain so.

### `lNumberOfInactiveControllers` [in]

The number of controllers specified in the *pInactiveControllerIdArray* parameter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | One or more of the GUIDs specified in the active or inactive arrays do not refer to an existing object. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## Remarks

The caller must include each subsystem controller in exactly one of either the
*pActiveControllerIdArray* parameter or the
*pInactiveControllerIdArray* parameter for each method call. The composition of the
*pActiveControllerIdArray* and *pInactiveControllerIdArray*
parameters can be different for each of the subsystem LUNs. Most subsystems implement only one active controller,
but some allow for multiple active controllers.

**Note** The **E_INVALIDARG** return value can indicate that the caller did not specify all
controllers in the subsystem. The
**AssociateControllers** method requires
that all controllers in the subsystem be present in one of the two arrays supplied.

Use the [IVdsLun::QueryActiveControllers](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-queryactivecontrollers)
method to query controller associations. Use the
[IVdsController::QueryAssociatedLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-queryassociatedluns)
method to query the LUNs associated with a particular controller.

## See also

[IVdsController::QueryAssociatedLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-queryassociatedluns)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)

[IVdsLun::QueryActiveControllers](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-queryactivecontrollers)