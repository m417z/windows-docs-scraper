# _NDIS_WWAN_IP_ADDRESS_STATE structure

## Description

The NDIS_WWAN_IP_ADDRESS_STATE structure represents the IP address of a PDP context.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_IP_ADDRESS_STATE structure. The MB
Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_IP_ADDRESS_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_IP_ADDRESS_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `WwanIpAddressState`

The PDP context's IP address.

## See also

[WWAN_IP_ADDRESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ip_address_state)