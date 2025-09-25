# _NDIS_WWAN_DRIVER_CAPS structure

## Description

The NDIS_WWAN_DRIVER_CAPS structure represents the capabilities of the miniport driver.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DRIVER_CAPS structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DRIVER_CAPS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DRIVER_CAPS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `DriverCaps`

A
[WWAN_DRIVER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_driver_caps) structure that represents
the capabilities of the miniport driver.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_DRIVER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_driver_caps)