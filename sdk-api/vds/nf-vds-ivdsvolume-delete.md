# IVdsVolume::Delete

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Deletes the volume and all plexes,
releasing the extents.

## Parameters

### `bForce` [in]

If **TRUE**, VDS deletes the volume even if it is in use; otherwise, the volume is not deleted if it is in use.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The plexes were deleted successfully. |

## Remarks

You can only delete volumes from an online pack. Use the
[IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties) method to confirm
that the pack status is **VDS_PS_ONLINE**.

You cannot delete a volume that is on removable media.

VDS dismounts the file system before deleting a volume—an operation required by FAT and FAT32, but not NTFS. In
addition, VDS deletes all access paths to the volume after deleting the volume itself. If the dismount operation
fails, and *bForce* is **true**, VDS deletes the volume without a dismount. File system client
applications must handle this situation. If the dismount succeeds, and the delete operation fails, VDS attempts
to remount the volume.

VDS prevents the deletion of the current system and boot volumes, as well as the pagefile, crashdump, and
hibernate volumes. You can move or reset the crashdump and pagefile. The hibernate volume must remain on the boot
partition.

**Windows Server 2003:** The crashdump and hibernate volumes must remain on the boot partition.

**Windows Server 2003:** After the volume has been deleted, VDS tries to delete the mounted folders. If this fails,
**Delete** will return
**VDS_S_ACCESS_PATH_NOT_DELETED**, even though the volume was successfully deleted.

## See also

[IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[VDS_PACK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_status)