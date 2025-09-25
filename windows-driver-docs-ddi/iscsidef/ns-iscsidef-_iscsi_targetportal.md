# _ISCSI_TargetPortal structure

## Description

The ISCSI_TargetPortal structure provides a definition of a target portal.

## Members

### `Address`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that indicates the IP address of the portal. The ISCSI_IP_Address structure provides a way to define an IP address that is independent of the version of the IP protocol that the initiator and the target use.

### `Reserved`

Reserved for Microsoft use only.

### `Socket`

Socket number associated with the target.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[ISCSI_TargetPortal WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-targetportal-wmi-class)