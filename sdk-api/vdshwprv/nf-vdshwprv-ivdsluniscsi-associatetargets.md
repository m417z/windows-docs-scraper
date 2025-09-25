# IVdsLunIscsi::AssociateTargets

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Associates LUNs with subsystem iSCSI targets.

## Parameters

### `pTargetIdArray` [in]

A pointer to an array of target **VDS_OBJECT_ID** data types. The provider
associates these iSCSI targets with the LUN. This array includes targets already associated with the LUN that
are to remain so.

### `lNumberOfTargets` [in]

The number of targets specified in the *pTargetArray* parameter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state, and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | Can be returned from any method that takes a **VDS_OBJECT_ID** constant. This return value indicates that the identifier does not refer to an existing object. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## Remarks

Most subsystems implement only one associated target per LUN, but some allow for multiple associated
targets.

Use the
[IVdsLunIscsi::QueryAssociatedTargets](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsluniscsi-queryassociatedtargets)
method to query target associations. Use the
[IVdsIscsiTarget::QueryAssociatedLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-queryassociatedluns)
method to query the LUNs associated with a target.

## See also

[IVdsLunIscsi](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsluniscsi)

[IVdsLunIscsi::QueryAssociatedTargets](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsluniscsi-queryassociatedtargets)