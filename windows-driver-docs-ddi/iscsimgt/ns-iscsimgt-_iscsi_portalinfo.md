# _ISCSI_PortalInfo structure

## Description

The ISCSI_PortalInfo structure contains information about an iSCSI portal.

## Members

### `Index`

The unique port number associated with this portal.

### `PortalType`

The type of portal. This member can have the following symbolic constant values, which are defined in *Iscsimgt.h*.

| Portal Type | Meaning |
| --- | --- |
| InitiatorPortals | The portal that the initiator uses to access the network. In an initiator, a portal is identified by its IP address. |
| TargetPortals | The portal that the target uses to access the network. In a target, a portal is identified by its IP address and its listening TCP port. |

### `Protocol`

The portal's transport protocol. Currently, this member must hold the value that is associated with the symbolic constant, TCP. TCP is defined in *Iscsimgt.h*.

### `Reserved1`

Reserved for Microsoft use only.

### `Reserved2`

Reserved for Microsoft use only.

### `IPAddr`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that indicates the portal's network IP address.

### `Port`

The socket number for the portal.

### `PortalTag`

The portal group tag to which the portal belongs.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[ISCSI_PortalInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-portalinfo-wmi-class)