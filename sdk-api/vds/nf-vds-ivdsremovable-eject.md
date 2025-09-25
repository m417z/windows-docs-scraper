# IVdsRemovable::Eject

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Ejects the media from the current device.

## Return value

This method can return standard HRESULT values, such as E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The media was ejected successfully. |
| **VDS_E_DEVICE_IN_USE**<br><br>0x80042413L | The call to the device failed because the device was performing another operation. |

## See also

[IVdsRemovable](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsremovable)

[IVdsRemovable::QueryMedia](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsremovable-querymedia)