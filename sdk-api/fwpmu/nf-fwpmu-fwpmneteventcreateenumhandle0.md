# FwpmNetEventCreateEnumHandle0 function

## Description

The **FwpmNetEventCreateEnumHandle0** function creates a handle used to enumerate a set of network events.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumTemplate` [in, optional]

Type: [FWPM_NET_EVENT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_enum_template0)*

 Template to selectively restrict the enumeration.

### `enumHandle` [out]

Type: **HANDLE***

The handle for network event enumeration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The enumerator was created successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If *enumTemplate* is **NULL**, all network event objects are returned.

The caller must call [FwpmNetEventDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventdestroyenumhandle0) to free the returned handle.

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the events' containers. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmNetEventCreateEnumHandle0** is a specific implementation of FwpmNetEventCreateEnumHandle. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_NET_EVENT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_enum_template0)

[FwpmNetEventDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventdestroyenumhandle0)