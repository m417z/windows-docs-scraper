# _DOT11_ADDITIONAL_IE structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ADDITIONAL_IE structure specifies characteristics of additional information elements (IEs)
for a BSS 802.11 Beacon or Probe Response frame.

## Members

### `Header`

The type, revision, and size of the DOT11_ADDITIONAL_IE structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_ADDITIONAL_IE_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_ADDITIONAL_IE).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uBeaconIEsOffset`

The offset of the additional IEs, in bytes, in the beacon frame sent by the NIC. This offset is
relative to the start of the buffer that contains the DOT11_ADDITIONAL_IE structure. The default value
is 0.

### `uBeaconIEsLength`

The length of the additional IEs, in bytes, in the beacon frame sent by the NIC. The default value
is 0.

### `uResponseIEsOffset`

The offset of the additional IEs, in bytes, in the probe response frame sent by the NIC. This
offset is relative to the start of the buffer that contains the DOT11_ADDITIONAL_IE structure. The
default value is 0.

### `uResponseIEsLength`

The length of the additional IEs, in bytes, in the probe response frame sent by the NIC. The
default value is 0.

## Syntax

```cpp
typedef struct _DOT11_ADDITIONAL_IE {
  NDIS_OBJECT_HEADER Header;
  ULONG              uBeaconIEsOffset;
  ULONG              uBeaconIEsLength;
  ULONG              uResponseIEsOffset;
  ULONG              uResponseIEsLength;
} DOT11_ADDITIONAL_IE, *PDOT11_ADDITIONAL_IE;
```

## Remarks

This structure is used with
[OID_DOT11_ADDITIONAL_IE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-additional-ie).

The miniport driver should reset the members of the DOT11_ADDITIONAL_IE structure to the default
values when it receives an
[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request) request.

## See also

[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request)

[OID_DOT11_ADDITIONAL_IE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-additional-ie)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)