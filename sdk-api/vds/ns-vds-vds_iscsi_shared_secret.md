# VDS_ISCSI_SHARED_SECRET structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a CHAP shared secret.

## Members

### `pSharedSecret`

A pointer to an array of bytes that contains the CHAP shared secret. If a shared secret is not necessary, this parameter should be **NULL**.

### `ulSharedSecretSize`

The number of bytes in the array that the **pSharedSecret** member points to. If the **pSharedSecret** member is **NULL**, this parameter must be zero. If **pSharedSecret** is not **NULL**, this parameter must be greater than or equal to 12 and less than or equal to 16.

## Remarks

This structure is used by the following methods:

* [IVdsServiceIscsi::SetInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-setinitiatorsharedsecret) sets the shared secret for an iSCSI initiator. If the **pSharedSecret** member is **NULL** and the **ulSharedSecretSize** member is zero, **SetInitiatorSharedSecret** clears any existing shared secrets.
* [IVdsIscsiTarget::SetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-setsharedsecret) sets the shared secret for an iSCSI target. If the **pSharedSecret** member is **NULL** and the **ulSharedSecretSize** member is zero, **SetSharedSecret** clears any existing shared secrets.
* [IVdsServiceIscsi::RememberTargetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-remembertargetsharedsecret) tells the initiator to remember the secret of the target.
* [IVdsIscsiTarget::RememberInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-rememberinitiatorsharedsecret) tells the target to remember the secret of the initiator.

For one-way CHAP, the secret is set on the target. The initiator must remember the CHAP secret of the target in order to do a successful login.

For mutual CHAP, secrets are set on the target and the initiator. To do a successful login, the target and the initiator must remember each other's secrets.

## See also

[IVdsIscsiTarget::RememberInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-rememberinitiatorsharedsecret)

[IVdsIscsiTarget::SetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-setsharedsecret)

[IVdsServiceIscsi::RememberTargetSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-remembertargetsharedsecret)

[IVdsServiceIscsi::SetInitiatorSharedSecret](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsserviceiscsi-setinitiatorsharedsecret)