# IkeextSaEnum2 function

## Description

The **IkeextSaEnum2** function returns the next page of results from the IKE/AuthIP security association (SA) enumerator.

**Note** **IkeextSaEnum2** is the specific implementation of IkeextSaEnum used in Windows 8. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [IkeextSaEnum1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsaenum1) is available. For Windows Vista, [IkeextSaEnum0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsaenum0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumHandle` [in]

Type: **HANDLE**

Handle for an IKE/AuthIP SA enumeration. Call [IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsacreateenumhandle0) to obtain an enumeration handle.

### `numEntriesRequested` [in]

Type: **UINT32**

Number of enumeration entries requested.

### `entries` [out]

Type: [IKEEXT_SA_DETAILS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details2)***

Addresses of the enumeration entries.

### `numEntriesReturned` [out]

Type: **UINT32***

The number of enumeration entries returned.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The SAs were enumerated successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

A subsequent call using the same enumeration handle will return the next set of items following those in the last output buffer.

**IkeextSaEnum2** works on a snapshot of the SAs taken at the time the enumeration handle was created.

## See also

[IKEEXT_SA_DETAILS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details2)

[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsacreateenumhandle0)