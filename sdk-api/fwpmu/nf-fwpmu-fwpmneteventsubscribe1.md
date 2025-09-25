# FwpmNetEventSubscribe1 function

## Description

The **FwpmNetEventSubscribe1** function is used to request the delivery of notifications regarding a particular net event.

**Note** **FwpmNetEventSubscribe1** is the specific implementation of FwpmNetEventSubscribe used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpmNetEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `subscription` [in]

Type: [FWPM_NET_EVENT_SUBSCRIPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_subscription0)*

The notifications which will be delivered.

### `callback` [in]

Type: **[FWPM_NET_EVENT_CALLBACK1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_net_event_callback1)**

Function pointer that will be invoked when a notification is ready for delivery.

### `context` [in, optional]

Type: **void***

Optional context pointer. This pointer is passed to the *callback* function along with details of the event.

### `eventsHandle` [out]

Type: **HANDLE***

Handle to the newly created subscription.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The subscription was created successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_SUBSCRIBE](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the net event's container.

## See also

[FWPM_NET_EVENT_CALLBACK1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_net_event_callback1)

[FWPM_NET_EVENT_SUBSCRIPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_subscription0)

[FwpmNetEventUnsubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventunsubscribe0)