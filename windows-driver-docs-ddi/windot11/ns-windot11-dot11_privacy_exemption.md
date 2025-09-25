# DOT11_PRIVACY_EXEMPTION structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PRIVACY_EXEMPTION structure defines a decryption exemption for a specified network
EtherType.

## Members

### `usEtherType`

The value of the IEEE EtherType in big-endian byte order.

### `usExemptionActionType`

The type of exemption for the specified EtherType. The following exemption types are defined:

#### DOT11_EXEMPT_ALWAYS

The 802.11 station must discard the received packet if the Protected Frame subfield of the Frame
Control field in the 802.11 MAC header is set to one.

#### DOT11_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE

The 802.11 station must discard the received packet if a key-mapping key for the source MAC
address is available and the Protected Frame subfield of the Frame Control field in the 802.11 MAC
header is set to zero.

### `usExemptionPacketType`

The type of packet that the exemption for the specified EtherType applies to. The following packet
types are defined:

#### DOT11_EXEMPT_UNICAST

Exempt only unicast packets.

#### DOT11_EXEMPT_MULTICAST

Exempt only multicast or broadcast packets.

#### DOT11_EXEMPT_BOTH

Exempt all packet types.

## Syntax

```cpp
typedef struct DOT11_PRIVACY_EXEMPTION {
  USHORT usEtherType;
  USHORT usExemptionActionType;
  USHORT usExemptionPacketType;
} DOT11_PRIVACY_EXEMPTION, *PDOT11_PRIVACY_EXEMPTION;
```

## Remarks

The 802.11 station's packet exemption list if configured through a set request of
[OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list). For each packet the 802.11 station receives, it will apply the
decryption exemption specified by the list entry with a
**usEtherType** value that matches the EtherType of the packet.

## See also

[OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list)