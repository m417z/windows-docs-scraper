# DOT11_DISASSOCIATION_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_DISASSOCIATION_PARAMETERS structure specifies the results of the disassociation operation
performed by the 802.11 station with either an access point (AP) or peer station. The Native 802.11
miniport driver includes a DOT11_ASSOCIATION_DISASSOCIATION_PARAMETERS structure when the driver makes an
[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation) status indication.

## Members

### `Header`

The type, revision, and size of the DOT11_DISASSOCIATION_PARAMETERS structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_DISASSOCIATION_PARAMETERS_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_DISASSOCIATION_PARAMETERS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `MacAddr`

The media access control (MAC) address of the AP or peer station that the 802.11 station has
disassociated from.

If the miniport driver sets
**MacAddr** to the wildcard value of 0xFFFFFFFFFFFF, the 802.11 station has disassociated from the AP
or all peer stations.

### `uReason`

The reason for the disassociation formatted as a
[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes) value.

### `uIHVDataOffset`

The offset of a block of data in a proprietary format that is defined by the IHV. The IHV can use
this data block for any purposes that are related to the
[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation) status indication.

This offset is relative to the start of the buffer, which contains the
DOT11_DISASSOCIATION_PARAMETERS structure.

If the miniport driver is not returning IHV data in the
NDIS_STATUS_DOT11_DISASSOCIATION indication, it must set uIHVDataOffset to
zero.

### `uIHVDataSize`

The length of the block of data that is used by the IHV for the
[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation) status indication. If the miniport driver is not returning IHV
data in this indication, it must set
**uIHVDataSize** to zero.

## Syntax

```cpp
typedef struct DOT11_DISASSOCIATION_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  MacAddr;
  DOT11_ASSOC_STATUS uReason;
  ULONG              uIHVDataOffset;
  ULONG              uIHVDataSize;
} DOT11_DISASSOCIATION_PARAMETERS, *PDOT11_DISASSOCIATION_PARAMETERS;
```

## Remarks

For more information about the disassociation operation, see
[Disassociation Operations](https://learn.microsoft.com/windows-hardware/drivers/network/disassociation-operations).

## See also

[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation)

[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)