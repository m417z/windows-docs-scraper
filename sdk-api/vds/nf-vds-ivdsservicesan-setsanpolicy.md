# IVdsServiceSAN::SetSANPolicy

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the disk [SAN policy](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy) for the operating system.

## Parameters

### `SanPolicy` [in]

A value from the [VDS_SAN_POLICY](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy) enumeration that specifies the SAN policy.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **VDS_E_SET_SAN_POLICY** | A driver error was reported when setting the SAN policy. |

## See also

[IVdsServiceSAN](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservicesan)

[IVdsServiceSAN::GetSANPolicy](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservicesan-getsanpolicy)