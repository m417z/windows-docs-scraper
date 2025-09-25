# IVdsPack2::CreateVolume2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a volume in a disk pack with an optional alignment parameter.

## Parameters

### `type` [in]

Value from the [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration that indicates the type of volume to create.

### `pInputDiskArray` [in]

Array of [VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk) structures that indicate the disks on which to create the volume.

**Note** This array's size must be 32 objects or less, because Windows imposes a limit where no more than 32 disks may be used with a single volume.

### `lNumberOfDisks` [in]

Number of elements in the array pointed to by the *pInputDiskArray* parameter.

### `ulStripeSize` [in]

Stripe size, in bytes, of the new volume.

**Note** The stripe size must be 65536 if the type is VDS_VT_STRIPE or VDS_VT_PARITY; otherwise, the stripe size MUST be 0.

### `ulAlign` [in]

Number of bytes for volume alignment. This parameter is optional and can be zero. If zero is specified, the server will determine the alignment value depending on the size of the disk on which the volume is created.

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** On a basic disk, the **CreateVolume2** method ignores this parameter and the **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment** registry key. This is a known issue and is being addressed. As a workaround, use the [IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition) or [IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex) method to create partitions on the basic disk so that they are aligned correctly.Dynamic partitions and volumes are aligned using the values under the following registry key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\vds\Alignment**

The default alignment is 1 MB if the disk is 4 GB or larger, or 64 KB if the disk is smaller than 4 GB.

### `ppAsync` [out]

Pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they are done with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The volume was created successfully. |
| **VDS_S_NO_NOTIFICATION**<br><br>0x00042517L | No volume arrival notification was received. You may need to call [IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh). |
| **VDS_S_UPDATE_BOOTFILE_FAILED**<br><br>0x00042434L | The volume is created successfully, but VDS failed to update the boot options in the Boot Configuration Data (BCD) store. |
| **VDS_E_ALIGN_IS_ZERO**<br><br>0x80042590L | The specified alignment is zero. |
| **VDS_E_ALIGN_NOT_A_POWER_OF_TWO**<br><br>0x8004258FL | The specified alignment is not a power of two. |
| **VDS_E_DISK_NOT_FOUND_IN_PACK**<br><br>0x8004252DL | The specified disks do not belong to the same pack. |
| **VDS_E_DMADMIN_METHOD_CALL_FAILED**<br><br>0x80042420L | The LDM service failed a method. |
| **VDS_E_EXTENT_SIZE_LESS_THAN_MIN**<br><br>0x80042433L | The extent size passed in is too small. |
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
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The volume type is not supported. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | At least one of the disks passed in is not found. |
| **VDS_E_ONE_EXTENT_PER_DISK**<br><br>0x80042531L | A single disk cannot contribute to multiple members or multiple plexes of the same volume. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The target pack is inaccessible. |
| **VDS_E_PARTITION_LIMIT_REACHED**<br><br>0x80042407L | The maximum number of partitions (primary partitions or primary partitions with an extended partition) already exists when the caller tries to create an additional primary partition or extended partition. |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | The dynamic provider cache is corrupt. |
| **VDS_E_VOLUME_DISK_COUNT_MAX_EXCEEDED**<br><br>0x80042529L | No more than 32 disks are allowed per volume. |
| **VDS_E_VOLUME_TOO_SMALL**<br><br>0x8004242CL | The volume size is too small. |

## See also

[IVdsPack2](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdspack2)

[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume)