## Description

The **NET_WAKE_SOURCE_TYPE** enumeration specifies the type for the source of a wake-on-LAN (WoL) wake-up event from a net adapter.

## Constants

### `NetWakeSourceTypeBitmapPattern:1`

The wake source is a bitmap pattern.

### `NetWakeSourceTypeMagicPacket:2`

The wake source is a magic packet, which is a special packet that contains 16 contiguous copies of the receiving net adapter's Ethernet address.

### `NetWakeSourceTypeMediaChange:3`

The wake source is a media connect or disconnect event.

### `NetWakeSourceTypePacketFilterMatch:4`

The wake source is a packet that matches a filter the driver supports, such as an Ethernet unicast frame.

### `NetWakeSourceTypeEapolPacket:5`

The wake source is an EAP over LAN (EAPOL) request identifier message.

## Remarks

Call [**NetWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegettype) to get the type for a WoL source.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NetWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegettype)