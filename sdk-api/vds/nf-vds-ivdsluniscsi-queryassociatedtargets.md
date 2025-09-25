# IVdsLunIscsi::QueryAssociatedTargets

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an enumeration of currently associated iSCSI targets—the targets
through which the LUN is accessible.

## Parameters

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) interface pointer that can be used to enumerate the iSCSI targets as [target objects](https://learn.microsoft.com/windows/desktop/VDS/target-object). For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects). Callers must release the interface and each of the target objects when they are no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state, and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |

## Remarks

Most subsystems implement only one associated target per LUN, but some allow for multiple associated
targets.

Use the [IVdsLunIscsi::AssociateTargets](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsluniscsi-associatetargets)
method to associate the target. Use the
[IVdsIscsiTarget::QueryAssociatedLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-queryassociatedluns)
method to query the LUNs associated with a target.

## See also

[IVdsLunIscsi](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsluniscsi)

[IVdsLunIscsi::AssociateTargets](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsluniscsi-associatetargets)