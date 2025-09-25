# IVdsVolumeMF::Format

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Formats a file system on
the current volume.

## Parameters

### `type` [in]

A [VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type) enumeration value that specifies the file system to be used. Must be one of the following: VDS_FST_NTFS, VDS_FST_FAT, VDS_FST_FAT32, or VDS_FST_UDF.

### `pwszLabel` [in]

A string representing the file system label.

### `dwUnitAllocationSize` [in]

The size of the allocation unit for the file system in bytes, which is usually between 512 and
65536.

### `bForce` [in]

If **TRUE**, the file system is formatted unconditionally even while in use;
otherwise, the operation fails.

### `bQuickFormat` [in]

If **TRUE**, VDS performs a quick format (it does not verify each sector on the
volume).

### `bEnableCompression` [in]

If **TRUE**, compression is enabled on the newly formatted file system. Compression
is a feature of NTFS, and is ignored for FAT and FAT32.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which
VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query
the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The file system was formatted successfully. |
| **VDS_E_OPERATION_DENIED**<br><br>0x8004240AL | The operation is denied if the caller tries to format the system, boot, crashdump, hibernation, or pagefile volumes. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume has failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. All volumes in an offline pack are inaccessible. |

In addition, the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface can return the
following related warnings and error codes.

| Return code/value | Description |
| --- | --- |
| **VDS_S_VOLUME_COMPRESS_FAILED**<br><br>0x00042443L | The file system is formatted but not compressed. |
| **VDS_E_INCOMPATIBLE_FILE_SYSTEM**<br><br>0x80042425L | The file system is incompatible. |
| **VDS_E_INCOMPATIBLE_MEDIA**<br><br>0x80042426L | The media is incompatible. |
| **VDS_E_ACCESS_DENIED**<br><br>0x80042427L | Access is denied. |
| **VDS_E_MEDIA_WRITE_PROTECTED**<br><br>0x80042428L | The media is write-protected. |
| **VDS_E_BAD_LABEL**<br><br>0x80042429L | The label is not valid. |
| **VDS_E_CANT_QUICK_FORMAT**<br><br>0x8004242AL | The volume cannot be quick formatted. |
| **VDS_E_IO_ERROR**<br><br>0x8004242BL | An IO error occurred during format. |
| **VDS_E_VOLUME_TOO_SMALL**<br><br>0x8004242CL | The volume size is too small to format. |
| **VDS_E_VOLUME_TOO_BIG**<br><br>0x8004242DL | The volume size is too large to format. |
| **VDS_E_CLUSTER_SIZE_TOO_SMALL**<br><br>0x8004242EL | The cluster size is too small to allow formatting. |
| **VDS_E_CLUSTER_SIZE_TOO_BIG**<br><br>0x8004242FL | The cluster size is too large to allow formatting. |
| **VDS_E_CLUSTER_COUNT_BEYOND_32BITS**<br><br>0x80042430L | The number of clusters is too large to represent as a 32-bit integer. |
| **VDS_E_INVALID_FS_TYPE**<br><br>0x80042561L | The value of the *type* parameter was not VDS_FST_NTFS, VDS_FST_FAT, VDS_FST_FAT32, or VDS_FST_UDF. |
| **VDS_E_CANT_INVALIDATE_FVE**<br><br>0x80042592L | BitLocker encryption could not be disabled for the volume. |

## Remarks

To create a boot volume on a dynamic disk, you must call [IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags) to set the **VDS_VF_INSTALLABLE** flag before calling **Format** to format the volume.

If an OEM partition is formatted as FAT or FAT32, the partition type does not change. If it is formatted with NTFS, the partition type changes to PARTITION_IFS (0x07). For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

If this method is called for a volume that is protected by BitLocker full-volume encryption, BitLocker encryption is disabled for the volume until the user re-enables it.

For more information about file system limits such as minimum and maximum allocation unit size (also called cluster size), see [NTFS Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758691(v=ws.10)) and [FAT Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758586(v=ws.10)).

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)