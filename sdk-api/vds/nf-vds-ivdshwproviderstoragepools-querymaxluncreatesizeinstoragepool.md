# IVdsHwProviderStoragePools::QueryMaxLunCreateSizeInStoragePool

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the maximum size of the LUN that can be created in the [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object) based on the specified LUN type and hints.

## Parameters

### `type` [in]

A [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type) enumeration value that specifies the LUN type. This parameter is required and must be a valid LUN type.

### `StoragePoolId` [in]

A VDS_OBJECT_ID (GUID) value that identifies the storage pools to be used to create the new LUN. This parameter is required and cannot be GUID_NULL.

### `pHints2` [in]

A pointer to a [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure that contains hints to be used in creating the LUN.

### `pullMaxLunSize` [out]

The address of a ULONGLONG value that receives the maximum LUN size, in bytes.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsHwProviderStoragePools](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwproviderstoragepools)