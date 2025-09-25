# IVdsDrive::QueryExtents

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an array of
the extents on a drive, including both allocated and unallocated extents.

## Parameters

### `ppExtentArray` [out]

A pointer to the array of [VDS_DRIVE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_extent) structures passed in by the caller. Callers must free this array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfExtents` [out]

A pointer to the number of drive extents returned in the
[VDS_DRIVE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_extent) structure.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The extents information was returned successfully. For a drive without extents, the array is empty, the value of *plNumberOfExtents* is set to 0, and the value of *ppExtentArray* is set to **NULL**. |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The drive object no longer exists. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The drive is in a failed state, and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The subsystem does not support this method. |

## Remarks

A drive can contribute extents to any number of LUNs, and these LUNs can be unmasked to any number of different
computers on the network. Use the
[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents) method to see all
the extents of a LUN plex.

The **LunId** member of each
[VDS_DRIVE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_extent) structure specifies the GUID for the LUN to which each allocated extent contributes. Consequently, you can use
the result of this method to determine the number of LUNs to which the drive contributes by counting the number
of distinct **LunId** values returned in *ppExtentArray*.

## See also

[IVdsDrive](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsdrive)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents)

[VDS_DRIVE_EXTENT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_extent)