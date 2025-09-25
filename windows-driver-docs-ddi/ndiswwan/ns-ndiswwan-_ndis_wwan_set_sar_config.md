# _NDIS_WWAN_SET_SAR_CONFIG structure

## Description

The **NDIS_WWAN_SET_SAR_CONFIG** structure describes Specific Absorption Rate (SAR) information that a mobile broadband (MB) modem should use to set its SAR configuration.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_SAR_CONFIG** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_SAR_CONFIG_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_SAR_CONFIG) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetSarConfig`

A formatted [**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config) structure that describes the SAR information for the modem to set.

## Remarks

This structure is used in an [OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-config) Set request.

After completing the Set request, the modem should return an [NDIS_STATUS_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sar-config) status notification as a response to inform the OS of the SAR configuration.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-config)

[NDIS_STATUS_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sar-config)

[**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config)