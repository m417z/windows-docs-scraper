# IVdsDisk::ClearFlags

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Clears the flags of a disk object.

## Parameters

### `ulFlags` [in]

A bitmask of [VDS_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_flag) enumeration values specifying the flags to be cleared. Only the **VDS_DF_READ_ONLY** flag can be cleared using this method. All other flags are set or cleared by the VDS service.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The flag was cleared successfully. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The flag is not supported. Neither the basic provider nor the dynamic provider support this flag. |

## See also

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[IVdsDisk3::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-getproperties2)

[IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties)

[IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags)

[VDS_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_flag)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)