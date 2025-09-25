# IVdsHwProviderType2::GetProviderType2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Not implemented.

Retrieves the type of the hardware provider. If the provider wants to maintain backward compatibility with clients that do not recognize the new provider type, the provider should continue to return the old provider type in the [IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype) method.

**Note** This method is identical to [IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype) and should not be used.

## Parameters

### `pType` [out]

A pointer to a caller-allocated variable that receives a [VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type) enumeration value that specifies the hardware provider type. This parameter is required and cannot be **NULL**.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The hardware provider type was returned successfully. |

## Remarks

If the provider object supports the [IVdsHwProviderType2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwprovidertype2) interface, the server must call the **GetProviderType2** method on the provider object to retrieve the provider type and then return an HRESULT indicating failure or success.

## See also

[IVdsHwProviderType2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwprovidertype2)

[IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype)

[IVdsService::QueryProviders](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryproviders)

[VDS Interfaces](https://learn.microsoft.com/windows/desktop/VDS/vds-interfaces)

[VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type)