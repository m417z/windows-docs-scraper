# IVdsHwProviderPrivateMpio::SetAllPathStatusesFromHbaPort

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the statuses of paths originating from a particular HBA port to a specified status.

## Parameters

### `hbaPortProp`

The properties of the HBA port from which the paths to be set originate. The only fields that need to be
provided are **wwnNode** and **wwnPort**. The hardware provider
must ignore all other fields.

### `status`

The status (enumerated by the [VDS_PATH_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_path_status) enumeration) to set the paths.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The association name was successfully set. |
| **VDS_S_STATUSES_INCOMPLETELY_SET**<br><br>0x00042702L | At least one path's status was not successfully set due to a nonfatal error (for example, the status conflicts with the current load balance policy). |

## See also

[IVdsHwProviderPrivateMpio](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwproviderprivatempio)

[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop)

[VDS_PATH_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_path_status)