# IVdsAdvancedDisk::FormatPartition

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Formats an existing OEM, ESP, or unknown partition.

## Parameters

### `ullOffset` [in]

The partition offset.

### `type` [in]

A
[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type) enumeration value that specifies the file system to be used. Must be one of the following: VDS_FST_NTFS, VDS_FST_FAT, VDS_FST_FAT32, or VDS_FST_UDF.

### `pwszLabel` [in]

A string representing the volume label.

### `dwUnitAllocationSize` [in]

The size of the allocation unit for the file system in bytes, which is usually between 512 and
65536.

### `bForce` [in]

If **TRUE**, the partition is formatted even while in use; otherwise, the operation
fails.

### `bQuickFormat` [in]

If **TRUE**, VDS performs a quick format. A quick format does not verify each sector
on the volume.

### `bEnableCompression` [in]

If **TRUE**, enables compression on the newly formatted file system. Compression is a
feature of NTFS and cannot be
set for FAT and FAT32 file systems.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which
VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query
the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The partition was formatted successfully. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The disk is removable, or the partition is not of type OEM, ESP, or unknown. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |

## Remarks

VDS implements this method.

This method formats only OEM, ESP, and unknown partitions. For other partitions, you must instead format the corresponding volume by using the [IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) or [IVdsVolumeMF2::FormatEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf2-formatex) method. Note that OEM, ESP, and unknown partitions are not exposed as volumes and therefore cannot be formatted with **Format** or **FormatEx**.

This method cannot be used to format removable media.

For information about file system limits such as minimum and maximum allocation unit size (also called cluster size), see [NTFS Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758691(v=ws.10)) and [FAT Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758586(v=ws.10)).

If an OEM partition is formatted as FAT or FAT32, the partition type does not change. If it is formatted with NTFS, the partition type changes to PARTITION_IFS (0x07). For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsDiskPartitionMF::FormatPartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf-formatpartitionex)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)