# IVdsAdvancedDisk::ChangeAttributes

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Modifies the attributes of the partition.

## Parameters

### `ullOffset` [in]

The partition offset.

### `para` [in]

The attribute parameters defined by the [CHANGE_ATTRIBUTES_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-change_attributes_parameters) structure.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The parameter was changed successfully. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The operation is not supported on dynamic disks, or the disk is removable. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The partition is an extended partition. Extended partitions have no attributes to change. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |

## Remarks

For GPT disks, this method changes the hidden, read only, and no drive letter attributes. For MBR disks, the method controls whether the boot indicator bit is active.

## See also

[CHANGE_ATTRIBUTES_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-change_attributes_parameters)

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)