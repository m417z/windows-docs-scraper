# FwpmCalloutAdd0 function

## Description

The **FwpmCalloutAdd0** function adds a new callout object to the system.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `callout` [in]

Type: [FWPM_CALLOUT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout0)*

The callout object to be added.

### `sd` [in, optional]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)**

The security information associated with the callout.

### `id` [out, optional]

Type: **UINT32***

Runtime identifier for this callout.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The callout was successfully added. |
| **FWP_E_INVALID_PARAMETER**<br><br>0x80320035 | FWPM_TUNNEL_FLAG_POINT_TO_POINT was not set and conditions other than local/remote address were specified. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

Some fields in the [FWPM_CALLOUT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout0) structure are assigned by the system, not the caller, and are ignored in the call to **FwpmCalloutAdd0**. If the caller supplies a null security descriptor, the system will assign a default security descriptor.

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the callout's container,
**FWPM_ACTRL_ADD_LINK**  access to the provider (if any), and
**FWPM_ACTRL_ADD_LINK**  access to the applicable layer. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

To add a filter that references a callout, invoke the functions in the following order.

* Call [FwpsCalloutRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) (documented in the Windows Driver Kit (WDK)), to register the callout with the filter engine.
* Call **FwpmCalloutAdd0** to add the callout to the system.
* Call [FwpmFilterAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfilteradd0) to add the filter that references the callout to the system.

By default filters that reference callouts that have been added but have not yet registered with the filter engine are treated as Block filters.

**FwpmCalloutAdd0** is a specific implementation of FwpmCalloutAdd. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CALLOUT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout0)

[Kernel-Mode FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)