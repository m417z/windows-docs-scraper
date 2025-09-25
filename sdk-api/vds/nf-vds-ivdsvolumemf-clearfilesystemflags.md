# IVdsVolumeMF::ClearFileSystemFlags

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Clears the file-system flags.

## Parameters

### `ulFlags` [in]

The flags enumerated by [VDS_FILE_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_flag). Callers can clear the **VDS_FPF_COMPRESSED** flag.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The volume is hidden. This method cannot be called on a hidden volume. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. |

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[IVdsVolumeMF::SetFileSystemFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-setfilesystemflags)