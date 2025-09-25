# FwpmFilterEnum0 function

## Description

The **FwpmFilterEnum0** function returns the next page of results from the filter enumerator.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumHandle` [in]

Type: **HANDLE**

Handle for a filter enumeration created by a call to [FwpmFilterCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfiltercreateenumhandle0).

### `numEntriesRequested` [in]

Type: **UINT32**

The number of filter objects requested.

### `entries` [out]

Type: [FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0)***

Addresses of enumeration entries.

### `numEntriesReturned` [out]

Type: **UINT32***

The number of filter objects returned.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The filters were enumerated successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

A subsequent call using the same enumeration handle will return the next set of items following those in the last output buffer.

**FwpmFilterEnum0** works on a snapshot of the filters taken at the time the enumeration handle was created.

**FwpmFilterEnum0** is a specific implementation of FwpmFilterEnum. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0)

[FwpmFilterCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfiltercreateenumhandle0)