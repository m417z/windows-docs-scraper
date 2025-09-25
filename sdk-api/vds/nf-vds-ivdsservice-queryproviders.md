# IVdsService::QueryProviders

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an enumeration object containing a list of the hardware and software providers known to VDS.

## Parameters

### `masks` [in]

The provider mask enumerated by [VDS_QUERY_PROVIDER_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_query_provider_flag). Callers can specify a software provider mask, a hardware provider mask, or both.

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) interface pointer that can be used to enumerate the providers as [provider objects](https://learn.microsoft.com/windows/desktop/VDS/provider-object). For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects). Callers must release the interface and each of the provider objects when they are no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The enumeration is returned successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

To determine the provider type for hardware providers, call the [IVdsHwProviderType2::GetProviderType2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype2-getprovidertype2) method or the [IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype) method for each provider object.

## See also

[IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject)

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type)

[VDS_QUERY_PROVIDER_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_query_provider_flag)