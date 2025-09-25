# _DOT11_AVAILABLE_CHANNEL_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_AVAILABLE_CHANNEL_LIST structure specifies the available operating frequency channel list
of the
[DSSS, HRDSSS, and ERP PHY
configurations](https://learn.microsoft.com/windows-hardware/drivers/network/dsss--hrdsss--and-erp-phy-configuration) that the NIC can operate with.

## Members

### `Header`

The type, revision, and size of the DOT11_AVAILABLE_CHANNEL_LIST structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_AVAILABLE_CHANNEL_LIST_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_AVAILABLE_CHANNEL_LIST).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfEntries`

The number of entries in the
**uChannelNumber** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**uChannelNumber** array can contain.

### `uChannelNumber`

An array that specifies the list of available operating frequency channels of the
[DSSS, HRDSSS, and ERP PHY
configurations](https://learn.microsoft.com/windows-hardware/drivers/network/dsss--hrdsss--and-erp-phy-configuration) that the NIC can operate with.

## Syntax

```cpp
typedef struct _DOT11_AVAILABLE_CHANNEL_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  ULONG              uChannelNumber[1];
} DOT11_AVAILABLE_CHANNEL_LIST, *PDOT11_AVAILABLE_CHANNEL_LIST;
```

## Remarks

This structure is used with
[OID_DOT11_AVAILABLE_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-available-channel-list).

## See also

[OID_DOT11_AVAILABLE_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-available-channel-list)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)