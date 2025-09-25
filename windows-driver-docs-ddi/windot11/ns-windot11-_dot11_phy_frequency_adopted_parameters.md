# _DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS structure specifies the channel or frequency that the
802.11 station has adopted to communicate with a peer station on an infrastructure BSS.

## Members

### `Header`

The type, revision, and size of the DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS structure. This member
is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ulPhyId`

The value of an entry in the list of active PHY types defined by the
**msDot11ActivePhyList** MIB object that specifies the current channel or frequency that the NIC has
adopted to communicate over the BSS network.

The miniport driver sets
**msDot11ActivePhyList** object to the list of PHYs that have been activated for use over the current
BSS network connection. For more information about the
**msDot11ActivePhyList** MIB object, see
[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list).

This member should not be set to DOT11_PHY_ID_ANY.

### `ulChannel`

The channel number of the
[DSSS, HRDSSS, and ERP PHY
configurations](https://learn.microsoft.com/windows-hardware/drivers/network/dsss--hrdsss--and-erp-phy-configuration) that the NIC has adopted to communicate over the BSS network.

### `ulFrequency`

The orthogonal frequency division multiplexing (OFDM) frequency that the NIC has adopted to
communicate over the BSS network.

## Syntax

```cpp
typedef struct _DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              ulPhyId;
  union {
    ULONG ulChannel;
    ULONG ulFrequency;
  };
} DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS, *PDOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS;
```

## Remarks

The Native 802.11 miniport driver includes a DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS structure when the
driver makes an
[NDIS_STATUS_DOT11_PHY_FREQUENCY_ADOPTED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-phy-frequency-adopted) status indication.

## See also

[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list)

[NDIS_STATUS_DOT11_PHY_FREQUENCY_ADOPTED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-phy-frequency-adopted)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)