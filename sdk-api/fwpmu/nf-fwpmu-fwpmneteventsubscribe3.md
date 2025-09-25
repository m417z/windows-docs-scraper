## Description

Used to request the delivery of notifications regarding a particular net event.

## Parameters

### `engineHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to an open session with the filter engine. To open a session with the filter engine, call [FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0).

### `subscription`

An [FWPM_NET_EVENT_SUBSCRIPTION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_subscription0) structure that describes which notifications will be delivered.

### `callback`

Pointer to a function of type [FWPM_NET_EVENT_CALLBACK3](https://learn.microsoft.com/windows/win32/api/fwpmu/nc-fwpmu-fwpm_net_event_callback3), which will be invoked when a notification is ready for delivery.

### `context`

Optional context pointer. This pointer is passed to the *callback* function along with details of the event.

### `eventsHandle`

Handle to the newly created subscription. Call [FwpmNetEventUnsubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventunsubscribe0) to close this handle when the subscription is no longer needed.

## Return value

|Return code/value|Description|
|-|-|
|ERROR_SUCCESS<br>0|The subscription was created successfully.|
|FWP_E_* error code<br>0x80320001—0x80320039|A Windows Filtering Platform (WFP)-specific error. For details, see [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes).|
|RPC_* error code<br>0x80010001—0x80010122|Failure to communicate with the remote or local firewall engine.|

## Remarks

You can't call this function within a transaction. It will fail with **FWP_E_TXN_IN_PROGRESS**. For more info about transactions, see [Object management](https://learn.microsoft.com/windows/win32/fwp/object-management).

To call this function, you need [FWPM_ACTRL_SUBSCRIBE](https://learn.microsoft.com/windows/win32/fwp/access-right-identifiers) access to the net event's container.

## See also