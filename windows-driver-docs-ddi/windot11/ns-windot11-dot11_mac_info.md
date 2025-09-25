# DOT11_MAC_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_MAC_INFO structure specifies a new 802.11 MAC entity that the 802.11 miniport driver has
created.

## Members

### `uReserved`

Reserved for system use.

### `uNdisPortNumber`

A ULONG value that specifies the number of the NDIS port that the 802.11 miniport driver has
allocated to reference a newly created 802.11 MAC entity. This value is equal to the
**PortNumber** member of the
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure.

### `MacAddr`

The media access control (MAC) address of a newly created 802.11 MAC entity.

## Syntax

```cpp
typedef struct DOT11_MAC_INFO {
  ULONG             uReserved;
  ULONG             uNdisPortNumber;
  DOT11_MAC_ADDRESS MacAddr;
} DOT11_MAC_INFO, *PDOT11_MAC_INFO;
```

## Remarks

This structure is used with
[OID_DOT11_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-create-mac).

## See also

[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics)

[OID_DOT11_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-create-mac)