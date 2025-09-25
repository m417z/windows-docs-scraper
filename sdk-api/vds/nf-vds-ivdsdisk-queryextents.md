# IVdsDisk::QueryExtents

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the details
of all the extents on a disk.

## Parameters

### `ppExtentArray` [out]

A pointer variable that receives an
array of [VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent) structures.
Callers must free this array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfExtents` [out]

The address of a type **LONG** representing the total number of extents.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The extent information was returned successfully. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack to which the disk belongs is inaccessible. |

## Remarks

Use this method to determine the amount of available free space for creating or extending volumes. You can
also use the extent information to determine how many volumes occupy the disk. Valid extent types are: unknown
extents, free extents, data extents, OEM extents, ESP extents, MSR extents, LDM metadata extents, and unusable
extents. A data extent contains a link to the volume on top of it.

If the disk is a dynamic disk, it must be online. If it is a basic disk or a raw disk, it can be online or offline.

## See also

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags)

[IVdsDisk::ConvertStyle](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-convertstyle)

[IVdsDisk::GetIdentificationData](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getidentificationdata)

[IVdsDisk::GetPack](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getpack)

[IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties)

[IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags)

[VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent)