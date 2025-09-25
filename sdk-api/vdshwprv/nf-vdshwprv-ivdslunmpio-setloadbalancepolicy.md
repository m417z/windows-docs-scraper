# IVdsLunMpio::SetLoadBalancePolicy

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the load balance policy on the LUN.

## Parameters

### `policy`

The load balance policy enumerated by the
[VDS_LOADBALANCE_POLICY_ENUM](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_loadbalance_policy_enum) enumeration.

### `pPaths`

A
pointer to an array of members of the [VDS_PATH_POLICY](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_policy) structure
that contain the path-specific policy information.

### `lNumberOfPaths`

The number of members of the [VDS_PATH_POLICY](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_policy) structure in the array
pointed to by the *pPaths* parameter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The load balance policy was successfully set. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The LUN object is no longer present. |
| ****VDS_E_OBJECT_STATUS_FAILED****<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| ****VDS_E_ANOTHER_CALL_IN_PROGRESS****<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until previous operations are complete. |

## See also

[IVdsLunMpio](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslunmpio)

[IVdsLunMpio::GetLoadBalancePolicy](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-getloadbalancepolicy)

[VDS_LOADBALANCE_POLICY_ENUM](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_loadbalance_policy_enum)

[VDS_PATH_POLICY](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_policy)