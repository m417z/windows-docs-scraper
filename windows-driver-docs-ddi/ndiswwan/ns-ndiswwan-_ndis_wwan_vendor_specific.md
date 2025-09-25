# _NDIS_WWAN_VENDOR_SPECIFIC structure

## Description

The NDIS_WWAN_VENDOR_SPECIFIC structure represents vendor-specific data.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_VENDOR_SPECIFIC
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_VENDOR_SPECIFIC_REVISION_1 |
| Size | sizeof(NDIS_WWAN_VENDOR_SPECIFIC) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `VendorSpecificData`

A formatted
[WWAN_VENDOR_SPECIFIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_vendor_specific) object that
represents vendor-specific data.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_VENDOR_SPECIFIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_vendor_specific)