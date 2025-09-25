# IVdsVolumeOnline::Online

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns a volume to the healthy state, if possible. This method is supported only for dynamic disks.

## Return value

This method can return standard HRESULT values, such as E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_S_NO_NOTIFICATION**<br><br>0x00042517L | No volume arrival notification was received. You may need to call [IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh). |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This method is not supported for basic disks. |

## Remarks

Despite its name, this method does not bring a volume online. It attempts to return a volume on a dynamic disk to a healthy state.

This method checks whether the volume has a missing disk, plex, or RAID-5 column and attempts to make any needed repairs.

To bring the volume online, call [IVdsVolumeMF::Mount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-mount).

To take the volume offline, call [IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount) with the *bPermanent* parameter set to **TRUE**.

## See also

[IVdsVolumeOnline](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeonline)