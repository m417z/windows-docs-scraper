# IVdsSubSystemNaming::SetFriendlyName

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the friendly name of a subsystem.

## Parameters

### `pwszFriendlyName`

A pointer to a null-terminated string specifying the name to assign to the subsystem.

## Return value

This method can return standard **HRESULT** values, such as **E_INVALIDARG** or **E_OUTOFMEMORY**, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The name was successfully set. |
| ****VDS_S_NAME_TRUNCATED****<br><br>0x00042700L | The name was set successfully but had to be truncated due to limitations in the subsystem. The name that was set might not match the name passed in the *pwszName* parameter. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The subsystem object is no longer present. |
| ****VDS_E_OBJECT_STATUS_FAILED****<br><br>0x80042431L | The subsystem is in a failed state and is unable to perform the requested operation. |
| ****VDS_E_ANOTHER_CALL_IN_PROGRESS****<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until previous operations are complete. |
| ****VDS_E_NOT_SUPPORTED****<br><br>0x80042400L | This operation is not supported by this provider. |

## See also

[IVdsSubSystemNaming](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystemnaming)