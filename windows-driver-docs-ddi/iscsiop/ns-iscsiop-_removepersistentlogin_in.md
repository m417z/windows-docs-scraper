# _RemovePersistentLogin_IN structure

## Description

The RemovePersistentLogin_IN structure holds the input data for the [RemovePersistentLogin](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistentlogin) method, which is used to remove persistent login information.

## Members

### `PortNumber`

The port number from which the initiator established the logon session.

### `TargetName`

The iSCSI target name to be removed from the initiator's list of persistent logon targets.

### `TargetPortal`

A [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structure that specifies the target portal for which the initiator should delete persistent logons. ISCSI_TargetPortal has an **Address** member of type [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address). If the **Type** member of ISCSI_IP_Address is set to ISCSI_IP_ADDRESS_EMPTY, the [RemovePersistentLogin](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistentlogin) method removes the persistent logons to the target for all portals.

## Remarks

You must implement this method.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[RemovePersistentLogin](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistentlogin)

[RemovePersistentLogin_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_removepersistentlogin_out)