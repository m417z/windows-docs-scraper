# IVdsStoragePool::QueryDriveExtents

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an array of the drive extents that are used by a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Parameters

### `ppExtentArray` [out]

A pointer to the array of [VDS_STORAGE_POOL_DRIVE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_drive_extent) structures passed in by the caller. These structures describe the drive extents used by the storage pool. Callers must free this array by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfExtents` [out]

A pointer to the number of extents returned in the *ppExtentArray* array.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsStoragePool](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsstoragepool)