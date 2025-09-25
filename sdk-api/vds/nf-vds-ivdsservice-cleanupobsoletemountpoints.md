# IVdsService::CleanupObsoleteMountPoints

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes user-mode paths and mounted folders for volumes that no longer exist.

## Return value

This method can return standard **HRESULT** values, such as
**E_INVALIDARG** or **E_OUTOFMEMORY**, and
[VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes).
It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)
using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can
originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds)
that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | Outdated user-mode paths and mounted folders were removed successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

By default, the registry retains the drive-letter mapping information for uninstalled volumes. If the disk
that contains the volume is removed from the computer, the registry entry is retained, so that if the disk and
volume return to the same computer, the volume receives the same drive letter. If the disk is moved to a new
computer, the registry entries do not move with it, so the volume might receive a different drive letter and
volume GUID.

The
**CleanupObsoleteMountPoints**
method removes these registry entries. There are three types of registry entries that are removed:

* If the volume does not have a drive letter or a volume GUID, it has a "no drive letter"
  registry entry, which is removed by this method.
* Otherwise, the volume has registry entries for a volume GUID and possibly a drive letter. Both are removed
  by this method.

In addition, if the volume contains any mounted folders,
**CleanupObsoleteMountPoints**
removes them. For example, if *Volume1* on *Disk1* is being
removed and *Volume1* is mounted as
*x*:\*MountVolume1* on *Disk2*, the
\*MountVolume1* folder on *Disk2* is also deleted.

## See also

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)