# IVdsVolumeMF::QueryAccessPaths

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns a list of access paths and a drive letter, if one exists, for the current volume.

## Parameters

### `pwszPathArray` [out]

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

### `plNumberOfAccessPaths` [out]

A pointer to the number of access paths on the volume.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The volume failed. |
| **VDS_E_PACK_OFFLINE**<br><br>0x80042444L | The pack containing the volume is not accessible. |

## Remarks

The drive letter appears as the first access path in *pwszPathArray*.

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[IVdsVolumeMF::AddAccessPath](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-addaccesspath)

[IVdsVolumeMF::DeleteAccessPath](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-deleteaccesspath)