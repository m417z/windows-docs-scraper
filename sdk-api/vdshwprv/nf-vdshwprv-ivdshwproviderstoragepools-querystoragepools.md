# IVdsHwProviderStoragePools::QueryStoragePools

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) enumeration object containing a list of the [storage pools](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object) managed by the hardware provider.

## Parameters

### `ulFlags` [in]

A bitmask of one or more [VDS_STORAGE_POOL_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_storage_pool_type) flags that specify the types of storage pools to be queried. One of the flags must be either VDS_SPT_CONCRETE or VDS_SPT_PRIMORDIAL. The default value of this parameter is zero. A value of zero means that all storage pools should be queried.

### `ullRemainingFreeSpace` [in]

The minimum amount of free space, in bytes, that each storage pool must contain. The default value for this parameter is zero. A value of zero means that the storage pools can contain any amount of free space.

### `pPoolAttributes` [in]

A pointer to a [VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) structure that specifies the attribute values that the returned storage pools must have. The default value for this parameter is **NULL**. A value of **NULL** means that the storage pools can have any attribute values.

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) interface
pointer that can be used to enumerate the storage pools. For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects). Callers must release the interface and each of the storage pool objects when they are no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.
This parameter is required and cannot be **NULL**.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

If the hardware provider does not manage any storage pools, this method returns an empty enumeration object.

If a non-**NULL** value is specified in the *pPoolAttributes* parameter, this method returns only storage pools that satisfy all of the attributes that are specified in the [VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) structure. If any minimum and maximum attributes are specified, the storage pools that are returned must match these attributes exactly. The hint attributes are used as hints to further filter the storage pools that satisfy all the specified attributes. If a specified attribute does not apply to any of the storage pools, this method returns S_OK with an empty enumeration object.

## See also

[IVdsHwProviderStoragePools](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwproviderstoragepools)