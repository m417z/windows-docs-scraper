# IVdsAdvancedDisk2::ChangePartitionType

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Changes the partition type on the disk at a specified byte offset.

## Parameters

### `ullOffset` [in]

Byte offset of the partition from the beginning of the disk. This offset must be the offset of the start of a partition.

### `bForce` [in]

Boolean value that indicates whether change will be forced.

### `para` [in]

Pointer to a [CHANGE_PARTITION_TYPE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-change_partition_type_parameters) structure that contains the partition type that the partition at the location specified by the *ullOffset* parameter will be changed to.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The partition type was changed successfully. |
| **VDS_E_DEVICE_IN_USE**<br><br>0x80042413L | The partition is in use. |
| **VDS_E_INTERNAL_ERROR**<br><br>0x80042448L | An internal error occurred. Check the event log for more details. |
| **VDS_E_INVALID_PARTITION_TYPE**<br><br>0x80042565L | The specified partition type is not valid for this operation. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The changing of the partition type on dynamic disks is not supported. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |
| **VDS_E_PARTITION_LDM**<br><br>0x8004258DL | This operation is not supported on LDM partitions. |
| **VDS_E_PARTITION_MSR**<br><br>0x8004258CL | This operation is not supported on MSR partitions. |
| **VDS_E_PARTITION_STYLE_MISMATCH**<br><br>0x80042571L | The specified partition style does not match that of the disk. |

## Remarks

If an OEM partition is formatted as FAT or FAT32, the partition type does not change. If it is formatted with NTFS, the partition type changes to PARTITION_IFS (0x07). For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[IVdsAdvancedDisk2](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk2)