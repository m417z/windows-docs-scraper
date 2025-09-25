# IVdsHwProviderPrivate::QueryIfCreatedLun

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Enables VDS to determine whether the hardware provider manages the specified LUN.

## Parameters

### `pwszDevicePath` [in]

A pointer to the path to the LUN on the local computer; a zero-terminated, human-readable string.

### `pVdsLunInformation` [in]

A pointer to the identification data of the specified LUN. See the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure.

### `pLunId` [out]

A pointer to the returned LUN GUID. If the provider does not manage the LUN, set this parameter to GUID_NULL.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The provider owns the LUN; returns the GUID of the LUN. |
| **S_FALSE** | The provider does not own the LUN. |

## Remarks

Only VDS calls this method.

## See also

[IVdsHwProviderPrivate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwproviderprivate)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)