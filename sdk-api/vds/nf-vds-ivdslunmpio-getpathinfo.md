# IVdsLunMpio::GetPathInfo

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an array of [VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info) structures,
one for each path to the LUN.

## Parameters

### `ppPaths` [out]

The address of a variable that receives an array of [VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info) structures. Callers must free each element in the array, and the array itself, by using
the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfPaths` [out]

The address of a variable that receives the number of elements in the array returned in the
*ppPaths* parameter.

The number of paths returned by this method will match the number of paths returned by the
[IVdsLunMpio::GetLoadBalancePolicy](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-getloadbalancepolicy)
method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The path information was successfully returned. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The LUN object is no longer present. |
| ****VDS_E_OBJECT_STATUS_FAILED****<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| ****VDS_E_ANOTHER_CALL_IN_PROGRESS****<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until previous operations are complete. |

## Remarks

Hardware providers do not need to return the **VDS_OBJECT_ID** at hbaPortProp.id of
[VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info) and should just set this to
**GUID_NULL**. This ID will be filled in by the system when this call is passed back to
applications. If the service cannot find the corresponding HBA port, **GUID_NULL** will be
used. The application will interpret this to mean that the HBA port is unknown to VDS.

## See also

[IVdsLunMpio](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslunmpio)

[VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)