# IVdsSubSystem::QueryMaxLunCreateSize

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the size of the maximum LUN that can be created using the specified LUN type and hints.

## Parameters

### `type` [in]

The LUN type enumerated by [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type).

### `pDriveIdArray` [in]

A pointer to an array containing a **VDS_OBJECT_ID** for each of the drives to be
used in the LUN creation. The provider should attempt to use the drives in the order provided. This parameter
can be **NULL** if the *lNumberOfDrives* parameter is 0, in which
case the provider should automatically pick drives.

### `lNumberOfDrives` [in]

The number of entries in *pDriveIdArray*. This can be set to 0.

### `pHints` [in]

A pointer to the [VDS_HINTS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints) structure used for creating the LUN. The
hints always take lower priority than parameters listed before. This argument must be non-NULL.

### `pullMaxLunSize` [out]

A pointer to a buffer containing the maximum size of the LUN in bytes. This argument must be non-NULL.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The subsystem object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The subsystem is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | Can be returned from any method that takes a **VDS_OBJECT_ID** constant. This return value indicates that the identifier does not refer to an existing object. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## See also

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsSubSystem](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystem)

[VDS_HINTS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints)

[VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type)