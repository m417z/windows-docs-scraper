# IVdsServiceIscsi::RememberTargetSharedSecret

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Communicates the CHAP shared secret of a target to the initiator service. This shared secret is used
during target login when the target authenticates the initiator.

## Parameters

### `targetId` [in]

The **VDS_OBJECT_ID** of the target that has the specified shared secret. This parameter is required and cannot be GUID_NULL.

### `pTargetSharedSecret` [in]

The address of a [VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret) structure
that contains the CHAP shared secret.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The shared secret was remembered successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## See also

[IVdsIscsiTarget::RememberInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-rememberinitiatorsharedsecret)

[IVdsIscsiTarget::SetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-setsharedsecret)

[IVdsServiceIscsi](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsserviceiscsi)

[IVdsServiceIscsi::SetInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-setinitiatorsharedsecret)

[VDS_ISCSI_SHARED_SECRET](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_shared_secret)