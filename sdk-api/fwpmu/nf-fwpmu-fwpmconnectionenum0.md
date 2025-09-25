# FwpmConnectionEnum0 function

## Description

The **FwpmConnectionEnum0** function returns the next page of results from the connection object enumerator.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumHandle` [in]

Type: **HANDLE**

Handle for a provider context enumeration created by a call to [FwpmConnectionCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectioncreateenumhandle0).

### `numEntriesRequested` [in]

Type: **UINT32**

Number of connection objects requested.

### `entries` [out]

Type: [FWPM_CONNECTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection0)***

Addresses of enumeration entries.

### `numEntriesReturned` [out]

Type: **UINT32***

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The connection objects were enumerated successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

A subsequent call using the same enumeration handle will return the next set of items following those in the last output buffer.

**FwpmConnectionEnum0** works on a snapshot of the connection objects taken at the time the enumeration handle was created.

## See also

[FWPM_CONNECTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection0)

[FwpmConnectionCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectioncreateenumhandle0)