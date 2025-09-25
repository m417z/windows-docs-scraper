# _DOT11_SECURITY_PACKET_HEADER structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_SECURITY_PACKET_HEADER structure specifies security data used in a network packet
header.

## Members

### `PeerMac`

A
[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address) type that defines the
MAC address of the peer node.

### `usEtherType`

The value of the
[IEEE EtherType](https://learn.microsoft.com/windows-hardware/drivers/network/ieee-ethertype-handling) in big-endian byte
order.

### `Data`

The contents of the security packet, excluding the 801.11 MAC header.

## Syntax

```cpp
typedef struct _DOT11_SECURITY_PACKET_HEADER {
  DOT11_MAC_ADDRESS PeerMac;
  USHORT            usEtherType;
  UCHAR             Data[1];
} DOT11_SECURITY_PACKET_HEADER, *PDOT11_SECURITY_PACKET_HEADER;
```

## See also

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)