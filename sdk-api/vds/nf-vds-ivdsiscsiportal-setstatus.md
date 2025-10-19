# IVdsIscsiPortal::SetStatus

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Not supported.

Sets the status of a portal to the specified value.

## Parameters

### `status` [in]

Values enumerated by [VDS_ISCSI_PORTAL_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_portal_status).
Only **VDS_IPS_ONLINE** and **VDS_IPS_OFFLINE** enumeration values
are supported; the remaining values are only to be used by a provider to report status.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The status was set successfully. |
| **VDS_E_PROVIDER_CACHE_CORRUPT** | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED** | The portal object is no longer present. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS** | Another operation is in progress. This operation cannot proceed until the previous operations are complete. |
| **VDS_E_NOT_SUPPORTED** | The operation or combination of parameters is not supported by this provider. |

## See also

[IVdsIscsiPortal](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsiportal)

[VDS_ISCSI_PORTAL_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_portal_status)