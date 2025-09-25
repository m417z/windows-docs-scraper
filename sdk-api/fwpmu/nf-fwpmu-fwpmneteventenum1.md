# FwpmNetEventEnum1 function

## Description

The **FwpmNetEventEnum1** function returns the next page of results from the network event enumerator.

**Note** **FwpmNetEventEnum1** is the specific implementation of FwpmNetEventEnum used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [FwpmNetEventEnum2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventenum2) is available. For Windows Vista, [FwpmNetEventEnum0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventenum0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumHandle` [in]

Type: **HANDLE**

Handle for a network event enumeration created by a call to [FwpmNetEventCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventcreateenumhandle0).

### `numEntriesRequested` [in]

Type: **UINT32**

The number of enumeration entries requested.

### `entries` [out]

Type: [FWPM_NET_EVENT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1)***

Addresses of enumeration entries.

### `numEntriesReturned` [out]

Type: **UINT32***

The number of enumeration entries returned.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The network events were enumerated successfully. |
| **FWP_E_NET_EVENTS_DISABLED**<br><br>0x80320013 | The collection of network diagnostic events is disabled. Call [FwpmEngineSetOption0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginesetoption0) to enable it. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

A subsequent call that uses the same *enumHandle* parameter will return the next set of events following those in the current *entries* buffer.

**FwpmNetEventEnum1** returns only events that were logged prior to the creation of the *enumHandle* parameter. See [Logging](https://learn.microsoft.com/windows/desktop/FWP/logging) for more information.

## See also

[FWPM_NET_EVENT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1)

[FwpmNetEventCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventcreateenumhandle0)

[WFP Logging](https://learn.microsoft.com/windows/desktop/FWP/logging)