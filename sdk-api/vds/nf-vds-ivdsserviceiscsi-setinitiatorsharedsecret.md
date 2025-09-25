# IVdsServiceIscsi::SetInitiatorSharedSecret

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the initiator CHAP shared secret that is used for mutual CHAP authentication when the initiator
authenticates the target.

## Parameters

### `pInitiatorSharedSecret` [in]

The address of a [VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)
structure that contains the shared secret. If the **pSharedSecret** member is **NULL** and the **ulSharedSecretSize** is zero, the **SetInitiatorSharedSecret** method clears any existing secret. If this parameter is **NULL** and the *targetId*
parameter is not **GUID_NULL**, **SetInitiatorSharedSecret** clears the association between the initiator and the target.

### `targetId` [in]

The **VDS_OBJECT_ID** of the target. This parameter is set to
**GUID_NULL** if the shared secret is not to be target-specific.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The shared secret was set successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |
| **VDS_E_TARGET_SPECIFIC_NOT_SUPPORTED**<br><br>0x80042706L | The initiator service does not support setting target-specific shared secrets. |

## Remarks

An initiator may support setting a different CHAP shared secret for each target.

There is no way to determine programmatically whether an initiator supports target-specific secrets. If the call to **SetInitiatorSharedSecret** returns VDS_E_TARGET_SPECIFIC_NOT_SUPPORTED, call the method again, setting the *targetId* parameter to GUID_NULL.

The Microsoft iSCSI Software Initiator does not support setting target-specific secrets.

## See also

[IVdsIscsiTarget::RememberInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-rememberinitiatorsharedsecret)

[IVdsIscsiTarget::SetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-setsharedsecret)

[IVdsServiceIscsi](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsserviceiscsi)

[IVdsServiceIscsi::RememberTargetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-remembertargetsharedsecret)

[VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)