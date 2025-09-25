# IVdsPack::AddDisk

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Adds a disk to an online pack.

## Parameters

### `DiskId` [in]

The GUID of the disk.

### `PartitionStyle` [in]

The style can be MBR or GPT. See the [VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style) enumeration.

### `bAsHotSpare` [in]

If true, VDS can use the disk as a hot spare; otherwise, the disk cannot be used for this operation. Only hardware providers support hot sparing.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The disk was added successfully. |
| **VDS_E_NOT_AN_UNALLOCATED_DISK**<br><br>0x80042418L | The disk is raw. |
| **VDS_E_OPERATION_DENIED**<br><br>0x8004240AL | The disk to be added is being cleaned. |
| **VDS_E_PROVIDER_FAILURE**<br><br>0x80042442L | There is a provider failure during the operation. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | Adding a second disk to a basic pack is not supported. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The target pack is inaccessible. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The disk is not found. |
| **VDS_E_DMADMIN_METHOD_CALL_FAILED**<br><br>0x80042420L | The logical disk manager (LDM) service failed to complete a method. |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | The dynamic provider cache is corrupt. |

## Remarks

VDS implements this method.

This method initializes a raw disk (a disk that has no partitioning defined) and adds it to the pack. Before this method is called, the raw disk is owned by the VDS service. After this method returns, the disk is owned by the basic provider.

To undo the effect of this method—that is, to remove the partitioning format and cause the disk to be a raw disk that is owned by the VDS service—use the [IVdsAdvancedDisk::Clean](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-clean) method.

You cannot use **AddDisk** to redefine the partitioning on an existing disk.

If you add a GPT disk to a basic pack, the operation automatically creates a MSR partition on the disk. Devices running the WinPE operating system are the exception because an administrator might prefer to create an ESP partition on the disk. The ESP partition, if present, must be the first partition on the disk.

If you add the disk to a dynamic pack, the operation does not create a MSR partition.

## See also

[IVdsPack](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdspack)

[VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop)

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)