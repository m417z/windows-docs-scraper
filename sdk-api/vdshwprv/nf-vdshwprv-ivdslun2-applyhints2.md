# IVdsLun2::ApplyHints2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Applies a new set of
hints to the LUN. Hints that are applied to a LUN are simultaneously applied to all plexes. This method is identical to the [IVdsLun::ApplyHints](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-applyhints) method, except that it uses a [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure instead of a [VDS_HINTS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints) structure.

## Parameters

### `pHints2` [in]

A pointer to the new hints to be applied to the LUN. See the
[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | There is a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state and unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## Remarks

Callers can also specify hints by passing in the *pHints*
parameter to the [IVdsSubSystem2::CreateLun2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)
method when creating a LUN. To query for existing hints, use the
[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2) method.

## See also

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun2)

[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2)

[IVdsSubSystem2::CreateLun2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)

[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints)