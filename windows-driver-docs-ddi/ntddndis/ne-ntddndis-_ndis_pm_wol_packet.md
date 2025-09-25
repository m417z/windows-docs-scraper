# _NDIS_PM_WOL_PACKET enumeration

## Description

The **NDIS_PM_WOL_PACKET** enumeration identifies the type of a wake-on-LAN (WOL) packet.

## Constants

### `NdisPMWoLPacketUnspecified`

The WOL packet type is not specified.

### `NdisPMWoLPacketBitmapPattern`

Specifies a bitmap pattern. This packet type is specified in the
**WoLBitMapPattern** member of the
[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure.

### `NdisPMWoLPacketMagicPacket`

WOL packets based on WOL magic packet. The media access control (MAC) address in the
[magic packet](https://learn.microsoft.com/windows/deployment/deploy-whats-new) is the current MAC
address of the network adapter.

### `NdisPMWoLPacketIPv4TcpSyn`

An IPv4 TCP SYN wake-on-LAN packet pattern. This packet pattern is specified in the
**IPv4TcpSynParameters** member of the [NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure.

### `NdisPMWoLPacketIPv6TcpSyn`

An IPv6 TCP SYN wake-on-LAN packet pattern. This packet pattern is specified in the
**IPv6TcpSynParameters** member of the [NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure.

### `NdisPMWoLPacketEapolRequestIdMessage`

Specifies an EAPOL request message packet. This packet type is specified in the
**EapolRequestIdMessageParameters** member of the [NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure.

### `NdisPMWoLPacketMaximum`

The maximum value for this enumeration. This value might change in future versions of NDIS header
files and binaries.

## Remarks

The **NDIS_PM_WOL_PACKET** enumeration is used in the
**WoLPacketType** member of the
[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure.

**Note** The **NDIS_PM_WOL_PACKET** enumeration type specifies packet based wake-on-LAN (WOL)
patterns. Wake-on-LAN that is based on NETBIOS over TCP is obsolete and, if necessary, it can be set with
the pattern bitmap method.

## See also

[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern)