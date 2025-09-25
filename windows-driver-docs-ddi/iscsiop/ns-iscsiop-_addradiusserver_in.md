# _AddRADIUSServer_IN structure

## Description

The AddRADIUSServer_IN structure holds the input data for the [AddRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/addradiusserver) method, which is used to add a new RADIUS server entry to existing list.

## Members

### `RADIUSIPAddress`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that contains an IP version-independent address of the RADIUS server.

## Remarks

It is optional that you implement this method.

## See also

[AddRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/addradiusserver)

[AddRADIUSServer_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addradiusserver_out)

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)