# IVdsSubSystemImportTarget::GetImportTarget

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the Volume Shadow Copy service (VSS) import target for the computer for this subsystem. Whenever shadow copies are created and a LUN from a shadow copy set from the subsystem is imported onto this computer, it will be
associated with the import target by the VSS hardware provider.

## Parameters

### `ppwszIscsiName` [out]

The address of a pointer to a string. On successful return of this method, the string pointed to will
contain the import target iSCSI name. This string is initialized by VDS and must be freed by the caller using
the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The import target was retrieved successfully. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The subsystem object is no longer present. |
| ****VDS_E_NOT_SUPPORTED****<br><br>0x80042400L | The operation or combination of parameters is not supported by this provider. |
| ****VDS_E_NO_IMPORT_TARGET****<br><br>0x80042713L | No import target was set for this subsystem. |

## See also

[IVdsSubSystemImportTarget](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdssubsystemimporttarget)

[SetImportTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdssubsystemimporttarget-setimporttarget)