# IVdsVolumeMF3::OfflineVolume

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Takes the volume offline by using the [IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_volume_offline) control code.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

If the volume is already offline, the **OfflineVolume** method returns S_OK.

When a volume is offline, all read, write, and IOCTL requests fail with
**ERROR_NOT_READY**. You cannot take the system or boot volume offline.

When a volume is online, all requests sent to the volume are honored.

When a volume that is online
is dismounted, the next call to open the volume causes it to be mounted. Taking the volume offline prevents the
dismounted volume from being mounted again. To dismount a volume, use the [IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount) method.

## See also

[IVdsVolumeMF3](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumemf3)