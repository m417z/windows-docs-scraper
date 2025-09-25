## Description

The **FwpmEngineGetOption0** function retrieves a filter engine option.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `option` [in]

The option to be retrieved.

### `value` [out]

The option value. The data type contained in the value parameter will be **FWP_UINT32**.

If option is **FWPM_ENGINE_COLLECT_NET_EVENTS**, value will be one of the following.

| Value | Meaning |
| ----- | ------- |
| 0 | Network events are not being collected. |
| 1 | Network events are being collected. |

If *option* is **FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS**, *value* will be a bitwise combination of the following values.

| Value | Meaning |
| ----- | ------- |
| FWPM_NET_EVENT_KEYWORD_INBOUND_MCAST (1) | Inbound multicast network events are being collected. |
| FWPM_NET_EVENT_KEYWORD_INBOUND_BCAST (2) | Inbound broadcast network events are not being collected. |

If *option* is **FWPM_ENGINE_PACKET_QUEUING** (available only in Windows 8 and Windows Server 2012), *value* will be one of the following.

| Value | Meaning |
| ----- | ------- |
| FWPM_ENGINE_OPTION_PACKET_QUEUE_NONE (0) | No packet queuing is enabled. |
| FWPM_ENGINE_OPTION_PACKET_QUEUE_INBOUND (1) | Inbound packet queuing is enabled. |
| FWPM_ENGINE_OPTION_PACKET_QUEUE_OUTBOUND (2) | Outbound packet queuing is enabled. |

If *option* is **FWPM_ENGINE_MONITOR_IPSEC_CONNECTIONS** (available only in Windows 8 and Windows Server 2012), *value* will be one of the following.

| Value | Meaning |
| ----- | ------- |
| 0 | The IPsec Connection Monitoring feature is disabled. No IPsec connection events or notifications are being logged. |
| 1 | The IPsec Connection Monitoring feature is enabled. New IPsec connection events and notifications are being logged. |

If *option* is **FWPM_ENGINE_TXN_WATCHDOG_TIMEOUT_IN_MSEC** (available only in Windows 8 and Windows Server 2012), *value* will be the time in milliseconds that specifies the maximum duration for a single WFP transaction. Transactions taking longer than this duration will trigger a watchdog event.

The **FWPM_ENGINE_NAME_CACHE** option is reserved for internal use.

## Return value

| Return code/value | Description |
| ----------------- | ----------- |
| **ERROR_SUCCESS** 0 | The option was retrieved successfully. |
| **FWP_E_\* error code** 0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_\* error code** 0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The caller must free the returned object by a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**.

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmEngineGetOption0** is a specific implementation of FwpmEngineGetOption. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)