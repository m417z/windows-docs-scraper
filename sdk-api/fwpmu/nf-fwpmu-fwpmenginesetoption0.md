# FwpmEngineSetOption0 function

## Description

The **FwpmEngineSetOption0** function changes the filter engine settings.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `option` [in]

Type: [FWPM_ENGINE_OPTION](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_engine_option)

The option to be set.

### `newValue` [in]

Type: [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)*

The new option value. The data type contained in the *newValue* parameter should be **FWP_UINT32**.

When *option* is **FWPM_ENGINE_COLLECT_NET_EVENTS**, *newValue* should be one of the following.

| Value | Meaning |
| --- | --- |
| 0 | Do not collect network events. |
| 1 | Collect network events. This is the default setting. |

When *option* is **FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS**, *newValue* should be either 0 (zero) or a bitwise combination of the following values.

**Note** If *newValue* is 0 the collection of inbound multicast and broadcast events is disabled. This is the default setting.

| Value | Meaning |
| --- | --- |
| **FWPM_NET_EVENT_KEYWORD_INBOUND_MCAST**<br><br>1 | Collect inbound multicast network events. |
| **FWPM_NET_EVENT_KEYWORD_INBOUND_BCAST**<br><br>2 | Collect inbound broadcast network events. |

When *option* is **FWPM_ENGINE_PACKET_QUEUING** (available only in Windows 8 and Windows Server 2012), *newValue* should be one of the following.

| Value | Meaning |
| --- | --- |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_NONE**<br><br>0 | Do not enable packet queuing. |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_INBOUND**<br><br>1 | Enable inbound packet queuing. |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_OUTBOUND**<br><br>2 | Enable outbound packet queuing. |

When *option* is **FWPM_ENGINE_MONITOR_IPSEC_CONNECTIONS** (available only in Windows 8 and Windows Server 2012), *newValue* should be the following. (**FwpmEngineSetOption0** may be used to enable connections, but will fail with **FWP_E_STILL_ON ERROR** when attempting to disable it.)

| Value | Meaning |
| --- | --- |
| 1 | The IPsec Connection Monitoring feature will be enabled. New IPsec connection events will be logged as well as notifications sent. |

When *option* is **FWPM_ENGINE_TXN_WATCHDOG_TIMEOUT_IN_MSEC** (available only in Windows 8 and Windows Server 2012), *newValue* should be the time in milliseconds that specifies the maximum duration for a single WFP transaction. Transactions taking longer than this duration will trigger a watchdog event.

The **FWPM_ENGINE_NAME_CACHE** option is reserved for internal use.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The option was set successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function cannot be called from within a dynamic session. It will fail with
**FWP_E_DYNAMIC_SESSION_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about sessions.

The caller needs [FWPM_ACTRL_WRITE](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

The default settings for network event collection are as follows:

* Outbound, all (unicast, multicast, and broadcast) events are collected.
* Inbound, only unicast events are collected.

Network event collection settings persist across reboots.

To collect inbound broadcast and/or multicast network events,

1. Call **FwpmEngineSetOption0** with *option* set to FWPM_ENGINE_COLLECT_NET_EVENTS and *newValue* set to 1.
2. Call **FwpmEngineSetOption0** with *option* set to FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS and *newValue* parameter set to FWPM_NET_EVENT_KEYWORD_INBOUND_MCAST and/or FWPM_NET_EVENT_KEYWORD_INBOUND_BCAST.

To stop collecting inbound broadcast and/or multicast network events,

* Call **FwpmEngineSetOption0** with *option* set to FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS and *newValue* parameter set to 0 (zero).

Disabling and re-enabling of network event collection (FWPM_ENGINE_COLLECT_NET_EVENTS) does not reset the collection of inbound broadcast and multicast events.

**FwpmEngineSetOption0** is a specific implementation of FwpmEngineSetOption. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_ENGINE_OPTION](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_engine_option)

[FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)

[FwpmEngineGetOption0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginegetoption0)