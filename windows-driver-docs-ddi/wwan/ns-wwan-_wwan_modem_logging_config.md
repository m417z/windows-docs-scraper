# _WWAN_MODEM_LOGGING_CONFIG structure

## Description

The **WWAN_MODEM_LOGGING_CONFIG** structure describes the current modem logging configuration for a modem.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `MaxSegmentSize`

The segment size, in kilobytes (KB), for each fragment sent by the modem. If the maximum fragment size supported by the modem for Device Service Commands exceeds the value set, then this value is set to the maximum supported segment size.

### `MaxFlushTime`

The time, in milliseconds, indicating the maximum time the modem waits before sending a log fragment. If the logs collected don't reach **MaxSegmentSize** within the **MaxFlushTime** duration since the last log fragment was sent, then a log fragment is sent regardless of its size. If there is no logging data, then no notification is sent. If the device cannot handle smaller flush times, then the device returns the time that it can handle in the response. The response to an [OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config) Query or Set request contains the currently configured **MaxFlushTime**.

### `LevelConfig`

A [**WWAN_MODEM_LOGGING_LEVEL_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_modem_logging_level_config) value that configures the level for which logs are collected. The response to an [OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config) Query or Set request contains the currently configured **LevelConfig**.

## Remarks

This structure is used in the [**NDIS_WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_modem_logging_config) structure.

## See also

[MB modem logging with DSS](https://learn.microsoft.com/windows-hardware/drivers/network/mb-modem-logging-with-dss)

[OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config)

[**NDIS_WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_modem_logging_config)