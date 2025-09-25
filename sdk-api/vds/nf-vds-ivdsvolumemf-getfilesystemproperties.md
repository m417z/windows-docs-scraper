# IVdsVolumeMF::GetFileSystemProperties

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns property details about the file system on the current volume.

## Parameters

### `pFileSystemProp` [out]

The address of the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop)
structure allocated and passed in by the caller. VDS allocates memory for the
**pwszLabel** member string. Callers must free the string by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_VOLUME_NOT_MOUNTED**<br><br>0x8004244FL | The volume has been taken offline. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. |

## Remarks

If the volume is encrypted by BitLocker, the type member of the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure will be set to **VDS_FST_UNKNOWN** on return.

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)