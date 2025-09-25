# _NDIS_WWAN_SERVICE_ACTIVATION structure

## Description

The NDIS_WWAN_SERVICE_ACTIVATION structure represents the command that is used to set the service
activation state of the MB device in order to obtain access to the provider's network.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SERVICE_ACTIVATION
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SERVICE_ACTIVATION _REVISION_1 |
| Size | sizeof(NDIS_WWAN_SERVICE_ACTIVATION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ServiceActivation`

A
[WWAN_SERVICE_ACTIVATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_service_activation) structure
that represents the service activation state of the device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SERVICE_ACTIVATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_service_activation)