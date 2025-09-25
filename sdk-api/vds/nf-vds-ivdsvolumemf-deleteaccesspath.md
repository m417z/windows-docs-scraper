# IVdsVolumeMF::DeleteAccessPath

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes
the access path from the current volume.

## Parameters

### `pwszPath` [in]

A string that contains the access path to be removed. An access path can be a drive letter or a path to an empty directory on an NTFS volume. If it is a drive letter, you must include a trailing backslash, for example, "F:\". If it is a path to a directory, the trailing backslash is not required, for example, "C:\MyFolder\MyDocuments".

### `bForce` [in]

If **TRUE**, the access path is deleted unconditionally, even if the volume is in
use. This parameter is meaningful only when the access path is a drive letter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_OPERATION_DENIED**<br><br>0x8004240AL | The path leads to the system volume, the boot volume, the crashdump volume, the hibernation volume, or the pagefile volume. You cannot remove the drive letter from these volumes. |
| **VDS_E_PATH_NOT_FOUND**<br><br>0x80042416L | The specified path is not found. |
| **VDS_E_DEVICE_IN_USE**<br><br>0x80042413L | The access path was deleted successfully, however, an error occurred. VDS possibly failed to update the GUID partition table (GPT) attribute of a partition or failed to delete a default network share (such as F$) while deleting the drive letter. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. |

## Remarks

If there are no open handles on the volume, the drive letter is removed immediately. However, if there are open handles on the volume, the volume cannot be locked and the drive letter is removed when the computer is restarted.

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[IVdsVolumeMF::AddAccessPath](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-addaccesspath)

[IVdsVolumeMF::QueryAccessPaths](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-queryaccesspaths)