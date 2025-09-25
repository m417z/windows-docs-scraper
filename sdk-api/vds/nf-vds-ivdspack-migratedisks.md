# IVdsPack::MigrateDisks

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Migrates a set of disks
from one pack to another pack.

## Parameters

### `pDiskArray` [in]

A pointer to an array of GUIDs; one for each disk.

### `lNumberOfDisks` [in]

The number of disks to migrate.

### `TargetPack` [in]

The GUID of the pack object.

### `bForce` [in]

If this parameter is set to **TRUE**, VDS ignores all errors from this method and attempts to migrate the disks unconditionally. If it is set to **FALSE**, the
operation does not proceed. In some cases, a forced migration can cause data loss.

### `bQueryOnly` [in]

If this parameter is set to **TRUE**, the migration does not occur. If it is set to **FALSE**, the operation proceeds.

### `pResults` [out]

The address of a caller-allocated array of **HRESULT** values.
The number of elements in the array is *lNumberOfDisks*.

If a disk can be migrated, or was migrated successfully, the corresponding array element receives
**S_OK**; otherwise, it receives the warning code or error code that was returned by the provider. For the list
of additional result codes, see Return Values.

### `pbRebootNeeded` [out]

If this parameter is set to **TRUE**, you must restart the computer to complete the operation. If it is set to **FALSE**, the operation completes without restarting.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The migration completed successfully. |
| **S_FALSE** | At least one of the disks cannot be converted, or can be converted with warning. |
| **VDS_E_DISK_NOT_ONLINE**<br><br>0x8004244BL | One of the disks is unavailable. |
| **VDS_E_IMPORT_SET_INCOMPLETE**<br><br>0x80042451L | An attempt was made to import a subset of the disks in the foreign pack. |

The following warnings and errors can be returned through *pResults*:

| Return code/value | Description |
| --- | --- |
| **VDS_S_BOOT_PARTITION_NUMBER_CHANGE**<br><br>0x00042436L | The partition number of the boot partition changed as the result of the migration operation. |
| **VDS_E_NO_FREE_SPACE**<br><br>0x80042437L | The selected disk does not have enough free space to complete the operation. |
| **VDS_E_ACTIVE_PARTITION**<br><br>0x80042438L | An active partition was detected on the selected disk, and it is not the active partition used to boot the active operating system. |
| **VDS_E_PARTITION_OF_UNKNOWN_TYPE**<br><br>0x80042439L | The partition information cannot be read. |
| **VDS_E_LEGACY_VOLUME_FORMAT**<br><br>0x8004243AL | A partition with an unknown type was detected on the selected disk. |
| **VDS_E_NON_CONTIGUOUS_DATA_PARTITIONS**<br><br>0x8004243BL | The selected GPT disk contains a non-basic data partition, which is both preceded by and followed by one or more basic data partitions. |
| **VDS_E_MIGRATE_OPEN_VOLUME**<br><br>0x8004243CL | A volume on the selected disk cannot be opened. |

## Remarks

VDS implements this method.

A single pack can have only one basic disk. As such, you can migrate only one disk at a time between a basic and dynamic pack.

You should force this operation when converting a basic disk to dynamic disk format and the end of the disk lacks
enough space for the LDM database. Set the *bForce* parameter to **true** and force the
operation despite the space limitation. Likewise, if an OEM partition is in the middle of a MBR disk with free
space or data volumes on either side.

After migrating dynamic disks to a dynamic pack, you should use the [IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties) method to determine whether the source or destination pack is now the online pack.

For information about using the **MigrateDisks** method to add foreign disks to a pack, see [Adding Foreign Disks to a Pack](https://learn.microsoft.com/windows/desktop/VDS/adding-foreign-disks-to-a-pack).

## See also

[IVdsPack](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdspack)

[IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties)