# FWPM_ENGINE_OPTION enumeration

## Description

The **FWPM_ENGINE_OPTION** enumerated type specifies configurable options for the filter engine.

## Constants

### `FWPM_ENGINE_COLLECT_NET_EVENTS:0`

The filter engine will collect WFP network events.

### `FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS`

The filter engine will collect WFP network events that match any supplied key words.

### `FWPM_ENGINE_NAME_CACHE`

Reserved for internal use.

**Note** Available only in Windows Server 2008 R2, Windows 7, and later.

### `FWPM_ENGINE_MONITOR_IPSEC_CONNECTIONS`

Enables the connection monitoring feature and starts logging creation and deletion events (and notifying any subscribers).

If the ETW operational log is already enabled, [FwpmEngineGetOption0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginegetoption0) will return showing the option as enabled. [FwpmEngineSetOption0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginesetoption0) can be used set the value (but fails with FWP_E_STILL_ON ERROR when attempting to disable it).

**Note** Available only in Windows 8 and Windows Server 2012.

### `FWPM_ENGINE_PACKET_QUEUING`

Enables inbound or forward packet queuing independently. When enabled, the system is able to evenly distribute CPU load to multiple CPUs for site-to-site IPsec tunnel scenarios.

**Note** Available only in Windows 8 and Windows Server 2012.

### `FWPM_ENGINE_TXN_WATCHDOG_TIMEOUT_IN_MSEC`

Transactions lasting longer than this time (in milliseconds) will trigger a
watchdog event.

**Note** Available only in Windows 8 and Windows Server 2012.

### `FWPM_ENGINE_OPTION_MAX`

Maximum value for testing purposes.

## See also

[Logging](https://learn.microsoft.com/windows/desktop/FWP/logging)

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)