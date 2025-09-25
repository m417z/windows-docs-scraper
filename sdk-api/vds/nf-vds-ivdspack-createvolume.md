# IVdsPack::CreateVolume

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a volume within the pack. The interface pointer for the new
[volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object) can be retrieved by calling
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) through the
*ppAsync* parameter. The
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure returned contains the volume
object interface pointer in the **cv.pVolumeUnk** member.

## Parameters

### `type` [in]

A volume type enumerated by [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type).
Volumes on basic disks can have only one extent, and only the **VDS_VT_SIMPLE** flag is
valid.

### `pInputDiskArray` [in]

Pointer to an array of [VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk)
structures; one structure for each disk. A disk can be included in the array only once. All disks in the array
must be used, or the method fails. Callers must allocate and initialize the array, and free the memory when the
call returns.

### `lNumberOfDisks` [in]

The total number of disks contributing to the volume.

**Note** VDS imposes a 32-disk limit on spanned, striped, and striped with parity (RAID-5) volumes.

### `ulStripeSize` [in]

If the volume is striped, the size of each stripe in bytes. Pass in zero bytes for
**VDS_VT_SIMPLE**, **VDS_VT_SPAN**, and
**VDS_VT_MIRROR**; 64 kilobytes for **VDS_VT_STRIPE** and
**VDS_VT_PARITY**.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for,
or query the status of the operation.

If you call [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) on this method and a success HRESULT value is returned,
you must release the interfaces returned in the
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The volume was created successfully. |
| **VDS_S_NO_NOTIFICATION**<br><br>0x00042517L | No volume arrival notification was received. You may need to call [IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh). |
| **VDS_S_UPDATE_BOOTFILE_FAILED**<br><br>0x00042434L | The volume is created successfully, but VDS failed to update the boot options in the Boot Configuration Data (BCD) store.<br><br>**Windows Server 2003:** Boot options are stored in the boot.ini file on an x86 or x64 system or NVRAM on an Itanium system. |
| **VDS_E_DISK_NOT_FOUND_IN_PACK**<br><br>0x8004252DL | The specified disks do not belong to the same pack. |
| **VDS_E_DMADMIN_METHOD_CALL_FAILED**<br><br>0x80042420L | LDM service failed a method. |
| **VDS_E_EXTENT_SIZE_LESS_THAN_MIN**<br><br>0x80042433L | Extent size passed in is too small. |
| **VDS_E_INVALID_DISK_COUNT**<br><br>0x80042526L | The number of disks specified is not valid for this operation. |
| **VDS_E_INVALID_MEMBER_COUNT**<br><br>0x80042522L | The member count for the volume must be greater than zero. |
| **VDS_E_INVALID_MEMBER_ORDER**<br><br>0x80042524L | The member indexes must be monotonically increasing and begin with zero. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The disk passed in is a CD-ROM or DVD device. |
| **VDS_E_INVALID_PACK**<br><br>0x8004251AL | This operation is not allowed on this disk pack. |
| **VDS_E_INVALID_PLEX_COUNT**<br><br>0x80042521L | The plex count for the volume must be greater than zero. |
| **VDS_E_INVALID_PLEX_ORDER**<br><br>0x80042523L | The plex indexes must be monotonically increasing and begin with zero. |
| **VDS_E_INVALID_STRIPE_SIZE**<br><br>0x80042525L | The stripe size in bytes must be a power of 2 for striped and RAID-5 volume types and must be zero for all other volume types. |
| **VDS_E_MISSING_DISK**<br><br>0x80042454L | The specified disk is missing. |
| **VDS_E_NO_MEDIA**<br><br>0x80042412L | There is no media in a removable drive passed in through the disk array. |
| **VDS_E_NOT_ENOUGH_SPACE**<br><br>0x8004240FL | There is not enough space on one of the disks. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The volume type is not supported, or a volume already exists on the removable disk passed into the method. A removable disk can have only one volume. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | At least one of the disks passed in is not found. |
| **VDS_E_ONE_EXTENT_PER_DISK**<br><br>0x80042531L | A single disk cannot contribute to multiple members or multiple plexes of the same volume. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The target pack is inaccessible. |
| **VDS_E_PARTITION_LIMIT_REACHED**<br><br>0x80042407L | The maximum number of partitions (primary partitions or primary partitions with an extended partition) already exists when the caller tries to create an additional primary partition or extended partition. |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | The dynamic provider cache is corrupt. |
| **VDS_E_VOLUME_DISK_COUNT_MAX_EXCEEDED**<br><br>0x80042529L | No more than 32 disks are allowed per volume. |
| **VDS_E_VOLUME_TOO_SMALL**<br><br>0x8004242CL | The volume size is too small. |

## Remarks

**Note** This method cannot be used to create a volume on a removable disk.

Callers use this method to create a new simple, spanned, striped, mirrored, or striped with
parity (RAID-5) volume in the current pack. Simple and spanned volumes have exactly one plex and one member.
Striped and RAID-5 volumes have multiple columns and members. Mirrored volumes consist of multiple plexes.

Basic disks can contain only simple volumes. Dynamic disks can contain volumes of all types as
long as the operating system supports the binding operation; non-server platforms do not support fault-tolerant
binding operations. All newly created volumes lack a drive letter.

On a basic disk, this method creates a primary partition. If there are already three primary partitions on the disk, it creates an extended partition to cover the largest contiguous free disk space extent left on the disk, and then creates a logical drive within the extended partition.

A disk cannot contribute to more than one plex of the same volume; however, a single disk can
contribute to multiple volumes. A simple volume has only one
[VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk) structure, whereas, spanned, striped,
mirrored, and RAID-5 volumes have one structure for each contributing disk.

The size of the disk specified in the
[VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk) structure can be the full disk or a
portion of the disk. When two disks form a mirrored volume, VDS uses the smallest disk to calculate the size of
the mirror. (Provider policy determines the actual offset, length, and number of disk extents allocated on a
given input disk.) Use the
[IVdsPack::QueryVolumes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-queryvolumes) method to determine
the exact size of the created volume.

To create a logical volume with an optional alignment parameter, use the [IVdsPack2::CreateVolume2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack2-createvolume2) method or use the **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment** registry key to specify the alignment value in bytes.

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** On a basic disk, the CreateVolume method ignores the **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment** registry key. This is a known issue and is being addressed. As a workaround, use the [IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition) or [IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex) method to create partitions on the basic disk so that they are aligned correctly.

Dynamic partitions and volumes are aligned using the values under the following registry key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment**

The default alignment is 1 MB if the disk is 4 GB or larger, or 64 KB if the disk is smaller than 4 GB.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)
interface for this method, regardless of whether the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[IVdsPack](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdspack)

[IVdsPack2::CreateVolume2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack2-createvolume2)

[IVdsPack::QueryVolumes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-queryvolumes)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)

[VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk)

[VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type)