# IVdsIscsiTarget::RememberInitiatorSharedSecret

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Communicates the initiator CHAP secret that is used for mutual CHAP authentication when the initiator
authenticates the target.

## Parameters

### `pwszInitiatorName` [in]

The string specifying the iSCSI name of the initiator. This parameter is required and cannot be **NULL**.

### `pInitiatorSharedSecret` [in]

The address of a [VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)
structure that contains the shared secret.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The shared secret was remembered successfully. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The target object is no longer present. |
| ****VDS_E_NOT_SUPPORTED****<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |

## See also

[IVdsIscsiTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsitarget)

[VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)