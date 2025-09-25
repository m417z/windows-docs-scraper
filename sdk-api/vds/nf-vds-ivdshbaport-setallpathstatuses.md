# IVdsHbaPort::SetAllPathStatuses

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the statuses of all paths originating from the HBA port to a specified status.

## Parameters

### `status`

The status to be assigned to the paths.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The statuses were successfully set. |
| ****VDS_S_STATUSES_INCOMPLETELY_SET****<br><br>0x00042702L | At least one path's status was not set successfully due to a nonfatal error (for example, the status conflicts with the current load balance policy). |

## See also

[IVdsHbaPort](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdshbaport)

[VDS_PATH_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_path_status)