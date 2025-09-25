# IVdsDiskOnline::Offline

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Takes the disk offline.**Windows Vista:** This method is not supported until Windows Vista with Service Pack 1 (SP1). Use [IVdsDisk2::SetSANMode](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk2-setsanmode) instead.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **VDS_E_FAILED_TO_OFFLINE_DISK** | The offline operation failed. |

## Remarks

If a dynamic disk is read/write and online, it can be made read-only and taken offline as follows:

1. For each volume on the disk, call the [IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount) method, setting the *bForce* and *bPermanent* parameters to **TRUE**.
2. Call the **Offline** method.
3. Set the read-only bit. (This is the **VDS_DF_READ_ONLY** flag in the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) structure.)

If a basic disk is read/write and online, it can be made read-only and taken offline the same way, but the order of the steps does not matter.

## See also

[IVdsDiskOnline](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdiskonline)

[IVdsDiskOnline::Online](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskonline-online)