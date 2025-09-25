# IVdsVolumeMF::AddAccessPath

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Adds an
access path.

## Parameters

### `pwszPath` [in]

A string indicating the access path, which is a user-mode path that can be used to open the volume. An access path can be a drive letter or a path to an empty directory on an NTFS volume. The access path string must include a trailing
backslash, for example, "F:\".

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The path was added successfully. |
| **S_FALSE** | The access path was added successfully, however, an error occurred. VDS possibly failed to update the GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER attribute of a partition or failed to add a default network share (such as F$) while adding the drive letter. For more information, see [PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_gpt). |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. |

## Remarks

VDS adds the access path by creating a mounted folder (also called a volume mount point). Note that mounted folders are supported only on NTFS volumes. For more information, see [Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points).

This method returns ERROR_DIR_NOT_EMPTY if the *pwszPath* parameter contains a path to a mounted folder that is already in use (even if the directory is empty) or if *pwszPath* contains a path to a nonempty directory.

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa)