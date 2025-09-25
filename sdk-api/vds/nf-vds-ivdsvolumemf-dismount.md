# IVdsVolumeMF::Dismount

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Dismounts a mounted volume.

## Parameters

### `bForce` [in]

If **TRUE**, the volume is dismounted even if it is in use; otherwise, the operation fails if the volume is in use.

### `bPermanent` [in]

If **TRUE**, the volume remains dismounted until an access path is added.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_VOLUME_TEMPORARILY_DISMOUNTED**<br><br>0x8004245CL | The volume is already dismounted. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The volume cannot be dismounted. It does not support the operation. |
| **VDS_E_VOLUME_PERMANENTLY_DISMOUNTED**<br><br>0x8004245DL | The volume is already dismounted. It cannot be dismounted temporarily until it becomes mountable. |
| **VDS_E_VOLUME_HAS_PATH**<br><br>0x8004245EL | The volume cannot be dismounted because it still has an access path. |
| **VDS_E_DEVICE_IN_USE**<br><br>0x80042413L | The volume is in use and cannot be dismounted. |

## Remarks

 To mount a volume, use the [Mount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-mount) method.

## See also

[IVdsVolumeMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf)

[IVdsVolumeMF::Mount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-mount)