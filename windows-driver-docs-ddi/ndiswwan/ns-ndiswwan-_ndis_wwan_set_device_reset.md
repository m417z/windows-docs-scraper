# _NDIS_WWAN_SET_DEVICE_RESET structure

## Description

The **NDIS_WWAN_SET_DEVICE_RESET** structure represents a command to reset a modem device. It is sent as part of an [OID_WWAN_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-reset) set request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_DEVICE_RESET** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_DEVICE_RESET_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_DEVICE_RESET) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

## See also

[MB modem reset operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-modem-reset-operations)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_WWAN_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-reset)