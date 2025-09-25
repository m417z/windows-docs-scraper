## Description

The **FwpmNetEventEnum0** function returns the next page of results from the network event enumerator.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `enumHandle` [in]

Handle for a network event enumeration created by a call to **[FwpmNetEventCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmneteventcreateenumhandle0)**.

### `numEntriesRequested` [in]

The number of enumeration entries requested.

### `entries` [out]

Addresses of enumeration entries.

### `numEntriesReturned` [out]

The number of enumeration entries returned.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | Success |
| **FWP_E_NET_EVENTS_DISABLED**<br>0x80320013 | The collection of network diagnostic events is disabled. Call **[FwpmEngineSetOption0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmenginesetoption0)** to enable it. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**.

A subsequent call that uses the same *enumHandle* parameter will return the next set of events following those in the current entries buffer.

**FwpmNetEventEnum0** returns only events that were logged prior to the creation of the *enumHandle* parameter. See [Logging](https://learn.microsoft.com/windows/desktop/FWP/logging) for more information.

**FwpmNetEventEnum0** is a specific implementation of **FwpmNetEventEnum**. See **WFP Version-Independent Names and Targeting Specific Versions of Windows** for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmNetEventCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmneteventcreateenumhandle0)**
- **[FwpmEngineSetOption0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmenginesetoption0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- [FWPM_NET_EVENT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event0)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Logging](https://learn.microsoft.com/windows/desktop/FWP/logging)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)