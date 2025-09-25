# _RemoveRADIUSServer_IN structure

## Description

The RemoveRADIUSServer_IN structure holds the input data for the user-mode **RemoveRADIUSServer** method, which is used to remove a RADIUS server entry.

## Members

### `RADIUSIPAddress`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that specifies the address of the RADIUS server to remove.

## Remarks

It is optional that you implement this method.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[RemovePersistentLogin_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_removepersistentlogin_out)