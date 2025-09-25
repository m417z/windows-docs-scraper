# IVdsVolumePlex::QueryExtents

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns all
extents for the current plex.

## Parameters

### `ppExtentArray` [out]

A pointer to the array of [VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent) structures passed in by the caller. Callers must free this array by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfExtents` [out]

A pointer to a buffer containing the number of extents.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsVolumePlex](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeplex)

[VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent)