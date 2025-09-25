# _NDIS_WWAN_SET_MODEM_LOGGING_CONFIG structure

## Description

The **NDIS_WWAN_SET_MODEM_LOGGING_CONFIG** structure specifies modem logging configuration for a modem.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_MODEM_LOGGING_CONFIG** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_MODEM_LOGGING_CONFIG_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_MODEM_LOGGING_CONFIG) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ModemLoggingConfig`

A formatted [**WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_logging_config) structure that describes the modem logging configuration to set.

## Remarks

This structure is used in the payload of an [OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config) Set request.

## See also

[MB modem logging with DSS](https://learn.microsoft.com/windows-hardware/drivers/network/mb-modem-logging-with-dss)

[OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config)

[NDIS_STATUS_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-modem-logging-config)

[**WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_logging_config)