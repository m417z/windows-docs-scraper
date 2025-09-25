# IVdsServiceUninstallDisk::GetDiskIdFromLunInfo

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Retrieves the VDS object ID for the disk that corresponds to a specified LUN.

## Parameters

### `pLunInfo` [in]

The address of a [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure that has been initialized by a VDS hardware provider.

### `pDiskId` [out]

The address of a VDS object ID variable passed in by the caller. This variable receives the GUID for the disk that corresponds to the LUN.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The disk's GUID was returned successfully. |
| **VDS_E_NO_DISK_PATHNAME**<br><br>0x8004270FL | The disk's path could not be retrieved. Some operations on the disk may fail. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The disk was not found. |

## Remarks

VDS implements this method. This method is called by VDS applications that need to uninstall a disk whose LUN is accessed through a VDS hardware provider on another computer. This method enables the application to uninstall a disk on a computer that does not have access to a VDS hardware provider and is thus unable to make an implicit link from disk to LUN.

## See also

[IVdsServiceUninstallDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsserviceuninstalldisk)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)