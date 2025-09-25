# _WWAN_MODEM_LOGGING_LEVEL_CONFIG enumeration

## Description

The **WWAN_MODEM_LOGGING_LEVEL_CONFIG** enumeration specifies the level for which modem logs are collected.

## Constants

### `WwanModemLoggingLevelProd`

Intended for telemetry collection from a retail or production population. The resulting log should be capsule-sized and contains key modem or MBB state or failure information only.

### `WwanModemLoggingLevelLabVerbose`

Intended for the development of MBB products with low maturity. Verbose full-stack capture of modems. The resulting modem capture should enable the IHV to replay and fully recover the capture during the log.

### `WwanModemLoggingLevelLabMedium`

Intended for verification and field testing of MBB products with relative maturity and stability. The level of detail and verbosity provides enough data points for IHV engineers to triage most MBB failures.

### `WwanModemLoggingLevelLabLow`

Intended for self-host-level logging. Summary-level capture of full-stack capture modems. Enables a highlight-level understanding of the modem's state and OS interactions.

### `WwanModemLoggingLevelOem`

Reserved for OEM and IHV internal usage.

### `WwanModemLoggingLevelMax`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_logging_config) structure.

## See also

[MB modem logging with DSS](https://learn.microsoft.com/windows-hardware/drivers/network/mb-modem-logging-with-dss)

[OID_WWAN_MODEM_LOGGING_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-logging-config)

[**WWAN_MODEM_LOGGING_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_logging_config)