# _NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS structure

## Description

The **NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS** structure sets Specific Absorption Rate (SAR) transmission status in a mobile broadband (MBB) modem.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetTransmissionStatus`

A formatted [**WWAN_SET_SAR_TRANSMISSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_transmission_status) structure that specifies the SAR transmission status to be set in the modem.

## Remarks

This structure is used in an [OID_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-transmission-status) Set request.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-transmission-status)

[NDIS_STATUS_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sar-transmission-status)

[**WWAN_SET_SAR_TRANSMISSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_transmission_status)