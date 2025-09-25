# IVdsIscsiTarget::SetSharedSecret

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the target CHAP shared secret that is used for CHAP authentication when the target authenticates the
initiator.

## Parameters

### `pTargetSharedSecret` [in]

The address of an [VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)
structure that contains the shared secret. If the **pSharedSecret** member is **NULL** and the **ulSharedSecretSize** is zero, the **SetSharedSecret** method clears any existing secret.

### `pwszInitiatorName` [in]

The string specifying the iSCSI name to which the shared secret is to be associated, if the secret is
initiator-specific. The value passed is used as the CHAP name. If the address is **NULL**
the changes apply to the default secret for all initiators.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The shared secret was set successfully. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The target object is no longer present. |
| ****VDS_E_NOT_SUPPORTED****<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |
| ****VDS_E_INITIATOR_SPECIFIC_NOT_SUPPORTED****<br><br>0x80042707L | The target does not support initiator-specific shared secrets. |

## Remarks

The hardware provider must configure the subsystem itself to change the target shared secret. Secrets that are used for
security are not persisted by VDS nor should they be persisted by the hardware providers on the local computer.
The hardware provider should transmit the secret to the subsystem in a secure manner, and the subsystem is
responsible for persisting it.

Some iSCSI targets may support setting a different CHAP shared secret for each initiator. If a target does not support initiator-specific secrets, the call to **SetSharedSecret** returns VDS_E_INITIATOR_SPECIFIC_NOT_SUPPORTED.

## See also

[IVdsIscsiTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsitarget)

[IVdsIscsiTarget::RememberInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-rememberinitiatorsharedsecret)

[IVdsIscsiTarget::SetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-setsharedsecret)

[IVdsServiceIscsi::SetInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-setinitiatorsharedsecret)

[VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)