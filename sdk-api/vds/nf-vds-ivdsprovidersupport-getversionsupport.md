# IVdsProviderSupport::GetVersionSupport

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns a bitmask of values enumerated by
[VDS_VERSION_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_version_support_flag) indicating the versions
of the VDS interfaces supported by this provider. This method is implemented only by hardware providers.

## Parameters

### `ulVersionSupport` [out]

Address of a **ULONG** that receives a bitmask of one or more of the values enumerated by
[VDS_VERSION_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_version_support_flag) indicating the
versions of the VDS interfaces supported by the provider.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used.

## See also

[IVdsProviderSupport](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsprovidersupport)

[VDS_VERSION_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_version_support_flag)