# IVdsAdvancedDisk::AssignDriveLetter

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Assigns a drive letter to an existing OEM, ESP, or unknown partition.

## Parameters

### `ullOffset` [in]

The partition offset.

### `wcLetter` [in]

The drive letter to assign.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The drive letter was assigned successfully. |
| **VDS_E_DRIVE_LETTER_NOT_FREE**<br><br>0x8004255CL | The specified drive letter is already assigned to another partition or volume. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The partition is on a removable media; otherwise, the partition is not an OEM, ESP or unknown partition. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |

## Remarks

VDS implements this method.

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)