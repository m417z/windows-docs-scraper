# IVdsServiceUninstallDisk::UninstallDisks

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Uninstalls a set of disks.

## Parameters

### `pDiskIdArray` [in]

Address of a buffer containing an array of VDS object IDs, one for each disk to be uninstalled. Each ID in
the array must be unique.

### `ulCount` [in]

Number of VDS object IDs in the buffer that the *pDiskIdArray* parameter points
to.

### `bForce` [in]

If **TRUE**, VDS uninstalls the disks even if the volumes cannot be locked or
dismounted.

### `pbReboot` [out]

Address of a **BOOLEAN** variable that receives **TRUE** if
the user must restart the computer to complete the uninstall process.

### `pResults` [out]

The address of a caller-allocated array of **HRESULT** values. The number of elements in the array is pointed to by the
*pDiskIdArray* parameter. The first element of this array corresponds to the
first element in the *pDiskIdArray*, and so on. If any of the disks fails to initialize
properly, the specific error code for the failure is returned in the corresponding element of this array.

## Return value

This method can return standard **HRESULT** values, such as
**E_INVALIDARG** or **E_OUTOFMEMORY**, and
[VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It
can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using
the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate
from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is
being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0 | The disks were successfully uninstalled. |
| **S_FALSE**<br><br>1 | This method returned a warning or error code for one or more disks. |
| **VDS_S_UNABLE_TO_GET_GPT_ATTRIBUTES**<br><br>0x0004245BL | The disks were successfully uninstalled, but the GUID partition table (GPT) attributes could not be retrieved for one or more disks. |
| **VDS_E_INTERNAL_ERROR**<br><br>0x80042448L | VDS encountered an internal error. Check the event log for more information. |
| **VDS_E_MISSING_DISK**<br><br>0x80042454L | One or more disks were missing. |
| **VDS_E_NO_DISK_PATHNAME**<br><br>0x8004270FL | The path could not be retrieved for one or more disks. |
| **VDS_E_NO_VOLUME_PATHNAME**<br><br>0x80042711L | The path could not be retrieved for one or more volumes. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | One or more of the specified VDS object IDs correspond to disks that are no longer present. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | One or more of the specified VDS object IDs correspond to disks that do not exist. |
| **VDS_E_PROVIDER_CACHE_OUTOFSYNC**<br><br>0x80042712L | The provider's cache is not in sync with the driver cache. |

## Remarks

VDS implements this method.

This method, which is synchronous, first uninstalls the volumes on the specified disks, and then uninstalls the
disks. After the disks are uninstalled, the corresponding LUNs can be masked (hidden) or deleted.

This method cleans up the drive letters that were assigned to the volumes on the disks. In addition, it sets
the volumes offline to prevent a volume from being remounted after the dismount handle has been closed but before
the disk is actually removed.

When removing a dynamic volume that spans more than one disk, you must call this method instead of using device manager functions.

For instructions on how to uninstall a disk on Windows Server 2003 releases where the
**UninstallDisks**
method is not supported, see the Remarks section of the [IVdsLun::SetMask](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-setmask)
method.

## See also

[IVdsServiceUninstallDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsserviceuninstalldisk)