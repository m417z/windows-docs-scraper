# IVdsAdvancedDisk::CreatePartition

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a partition on a basic disk.

The
[IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex)
method supersedes this method.

## Parameters

### `ullOffset` [in]

The partition offset.

### `ullSize` [in]

The size, in bytes, of the new partition.

### `para` [in]

The pointer to parameters defined by the
[CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters)
structure.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which
VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query
the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The partition was created successfully. |
| **VDS_E_NO_MEDIA**<br><br>0x80042412L | There is no media in a removable drive. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The media does not support this operation. For example, the caller cannot create a partition on a CD-ROM. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | Creating a second partition on removable media is not supported. Alternatively, this error indicates the disk is a dynamic disk. |
| **VDS_E_PARTITION_LIMIT_REACHED**<br><br>0x80042407L | The maximum number of partitions (four primary, or three primary and one extended) already exists when the caller tries to create an additional primary partition or extended partition. |
| **VDS_S_UPDATE_BOOTFILE_FAILED**<br><br>0x00042434L | The partition was created successfully, but VDS failed to update the boot options in the Boot Configuration Data (BCD) store.<br><br>**Windows Server 2003:** Boot options are stored in the boot.ini file on an x86 or x64 system or NVRAM on an Itanium system. |

## See also

[CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters)

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex)