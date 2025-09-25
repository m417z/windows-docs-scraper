# DOT11_ENCAP_ENTRY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ENCAP_ENTRY structure defines an encapsulation type to be applied to the payload of an
802.11 packet based on the packet's IEEE EtherType.

## Members

### `usEtherType`

The value of the IEEE EtherType in big-endian byte order.

If the
**usEtherType** member is zero, the encapsulation that is specified by the
**usEncapType** member applies to all EtherType values. If the miniport driver sets
**usEtherType** to zero for an entry, it must be the only entry in the EtherType encapsulation
list.

### `usEncapType`

The type of encapsulation that is performed on the EtherType specified by the
**usEtherType** member. The
**usEncapType** member can have one of the following values:

#### DOT11_ENCAP_RFC_1042

The encapsulation that is defined through IETF RFC 1042.

#### DOT11_ENCAP_802_IH

The encapsulation that is defined through the IEEE 802.1h-1997 standard.

## Syntax

```cpp
typedef struct DOT11_ENCAP_ENTRY {
  USHORT usEtherType;
  USHORT usEncapType;
} DOT11_ENCAP_ENTRY, *PDOT11_ENCAP_ENTRY;
```

## Remarks

The miniport driver returns an encapsulation list when it makes an
[NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) indication. The encapsulation list specified in the
indication applies to the association with an access point (AP) in an infrastructure basic service set
(BSS) network.

**Note** The miniport driver cannot return an encapsulation list when associating with peer
stations within an independent BSS network.

For more information about 802.11 packet payload encapsulation, see
[802.11 Payload Encapsulation](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757419(v=ws.10)).

## See also

[NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion)

[DOT11_ASSOCIATION_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)