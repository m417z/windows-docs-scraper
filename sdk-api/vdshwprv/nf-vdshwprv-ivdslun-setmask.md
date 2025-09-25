# IVdsLun::SetMask

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Specifies the unmasking list,
which is the list of computers to be granted access to the LUN.

## Parameters

### `pwszUnmaskingList` [in]

A list specifying the computers to be granted access to the LUN. The list is a semicolon-delimited,
NULL-terminated, human-readable string.

If the value is "*", all computers that have an HBA
port attached to the storage subsystem are to be granted access to the LUN.

**Note** In practice, if the value is "*", most hardware providers only grant the ports and initiators on the local computer access to the LUN.

If the value is
"", access is revoked for all computers that were previously granted access to the LUN.

If "*" or "" is specified, no other value can be specified.

For Fibre Channel networks and serial attached SCSI (SAS) networks, each entry is a 64-bit World-Wide Name (WWN) of each port to which the LUN is
unmasked, formatted as a hexadecimal string (16 characters long), most significant byte first. For example, a
WWN address of 01:23:45:67:89:AB:CD:EF is represented as "0123456789ABCDEF". For more information, see the T10 specifications for [Fibre Channel](https://t10.org/drafts.htm#FibreChannel) and [SAS](https://t10.org/drafts.htm#SCSI3_SAS).

For iSCSI networks, each entry is an iSCSI qualified name (IQN) of each initiator to which the LUN is
unmasked. A LUN unmasked to a particular initiator is considered to be associated with that initiator.

**Note** The unmasking list can contain the same WWN or IQN more than once. The caller is not expected to remove
duplicates from the list or to validate the format of the WWN or iSCSI name. In addition, access is not
cumulative. In other words, if this method is called twice in succession, only the computers specified in the
second call are granted access.

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
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state, and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |

## Remarks

Before calling the **SetMask** method to mask a LUN,
the caller should uninstall the corresponding disks as follows. First, retrieve the VDS object ID of the disk that
corresponds to the LUN being masked by calling
[IVdsServiceUninstallDisk::GetDiskIdFromLunInfo](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceuninstalldisk-getdiskidfromluninfo).
Then call
[IVdsServiceUninstallDisk::UninstallDisks](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceuninstalldisk-uninstalldisks)
with the VDS object ID of the disk.

**Windows Server 2003 and Windows Server 2003 with SP1:** To uninstall the corresponding disks, perform the following steps. Note that these steps became obsolete
with Windows Server 2003 R2.

1. Locate the volumes on the disks to be masked as follows:
   1. For each disk, call the
      [IVdsDisk::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-queryextents) method to enumerate
      the disk extents. This method returns a list of
      [VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent) structures. The
      **volumeId** member of this structure contains the volume
      **GUID**.
   2. Enumerate the volumes managed by the software provider by calling the
      [IVdsSwProvider::QueryPacks](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsswprovider-querypacks) method to
      enumerate the packs and calling
      [IVdsPack::QueryVolumes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-queryvolumes) to enumerate the
      volumes in each pack. Call
      [IVdsVolume::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-getproperties) to obtain the
      [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure for each volume. The
      **id** member of this structure contains the volume **GUID**.
      The **pwszName** member contains the volume name to be passed to
      [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) to obtain a volume handle.
   3. Use the volume GUIDs that were obtained by calling
      [IVdsDisk::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-queryextents) to determine which of
      the volume names you will need from the list of enumerated volumes.
2. Lock each volume by using the [FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lock_volume)
   control code. If the LUN is being moved to another machine as an intact volume, and another application holds a
   volume lock, you should retry the **FSCTL_LOCK_VOLUME**
   operation if possible before continuing on to the next step. However, if the volume is only being locked and
   dismounted because it is being deleted, there is no need to retry the
   **FSCTL_LOCK_VOLUME** operation.

   **Note** This step is optional. The purpose of this step is to allow other applications that may hold locks to
   release them. Even if the lock operation fails, you should continue on to the next step.
3. Dismount each volume by using the
   [FSCTL_DISMOUNT_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_unlock_volume) control code.
4. If the volumes are on basic disks, take them offline by using the
   [IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_offline) control code.
5. Uninstall each volume using the **SetupDiCallClassInstaller** function,
   passing **DIF_REMOVE** for the *InstallFunction* parameter.
6. Uninstall each disk using the **SetupDiCallClassInstaller** function, passing
   **DIF_REMOVE** for the *InstallFunction* parameter.
7. Remove user-mode paths, such as mounted folders and drive-letter assignments, from the registry by calling
   the
   [IVdsService::CleanupObsoleteMountPoints](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-cleanupobsoletemountpoints)
   method.

After a LUN is unmasked to a target machine or masked from a target machine, the LUN's visibility on that
machine may not change until a bus rescan is performed. The VDS application on the target machine initiates the
bus rescan by calling [IVdsService::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-reenumerate).
The initiating of the bus rescan is the responsibility of the VDS application, not the hardware provider.

## See also

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)