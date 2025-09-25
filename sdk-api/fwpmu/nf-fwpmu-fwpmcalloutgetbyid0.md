# FwpmCalloutGetById0 function

## Description

The **FwpmCalloutGetById0** function retrieves a callout object.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT32**

The runtime identifier for the callout. This identifier was received from the system when the application called [FwpmCalloutAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutadd0) for this object.

### `callout` [out]

Type: [FWPM_CALLOUT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout0)**

Information about the state associated with the callout.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The callout was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free the returned object by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the callout. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmCalloutGetById0** is a specific implementation of FwpmCalloutGetById. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CALLOUT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout0)

[FwpmCalloutAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutadd0)