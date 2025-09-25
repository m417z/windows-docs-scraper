# IVdsDisk3::QueryFreeExtents

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the free extents on the disk and aligns them to the specified alignment size.

## Parameters

### `ulAlign` [in]

The alignment size, in bytes. This value must be a multiple of the disk sector size. If this parameter is zero, the default alignment value for the volume is used. The default alignment depends on the size of the disk where the volume is located. All partitions and volumes are aligned using the values under the following registry key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment**

If this registry key is not set, the default alignment is 1 MB if the disk is 4 GB or larger, or 64 KB if the disk is smaller than 4 GB.

### `ppFreeExtentArray` [out]

The address of a pointer variable that receives an
array of [VDS_DISK_FREE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_free_extent) structures, one for each free extent.
Callers must free this array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. If there are no free extents, the pointer is set to **NULL** on output and does not need to be freed.

### `plNumberOfFreeExtents` [out]

A pointer to a variable that receives the total number of [VDS_DISK_FREE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_free_extent) structures. If there are no free extents, the pointer is set to **NULL** on output and does not need to be freed.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The free extent information was returned successfully. |
| **S_FALSE** | There are no free extents on the disk. |
| **VDS_E_ALIGN_NOT_SECTOR_SIZE_MULTIPLE**<br><br>0x80042554L | The alignment value that is specified in the *ulAlign* parameter is not a multiple of the disk sector size. |

## See also

[IVdsDisk3](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk3)