# IVdsAdvancedDisk::DeletePartition

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Deletes a partition from a basic disk.

## Parameters

### `ullOffset` [in]

The partition offset.

### `bForce` [in]

If this parameter is set to **TRUE**, VDS deletes all partitions unconditionally (excluding OEM, ESP or MSR). If it is set to **FALSE**, the operation
fails if the partition is in use. A partition is considered to be in use if calls to lock or dismount the volume fail.

### `bForceProtected` [in]

If this parameter is set to **TRUE**, VDS deletes all protected partitions (including OEM, ESP and MSR) unconditionally. If it is set to **FALSE**, the
operation fails if the partition is protected.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The partition was deleted successfully. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The media does not support this operation. For example, you cannot delete a partition on a CD-ROM. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation is not supported on dynamic disks. |
| **VDS_E_PARTITION_NOT_EMPTY**<br><br>0x80042408L | The extended partition is not empty. |
| **VDS_E_BAD_PROVIDER_DATA**<br><br>0x80042441L | This value indicates a provider error. The operation is aborted. |
| **VDS_E_DEVICE_IN_USE**<br><br>0x80042413L | The partition is in use. |
| **VDS_S_ACCESS_PATH_NOT_DELETED**<br><br>0x00044244L | The partition was deleted successfully, but VDS failed to remove the access paths. |
| **VDS_S_UPDATE_BOOTFILE_FAILED**<br><br>0x00042434L | The partition was deleted successfully, but VDS failed to update the boot options in the Boot Configuration Data (BCD) store.<br><br>**Windows Server 2003:** Boot options are stored in the boot.ini file on an x86 or x64 system or NVRAM on an Itanium system. |

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)