## Description

The **FwpmConnectionSubscribe0** function is used to request the delivery of notifications about changes to a connection object.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `subscription` [in]

Type: **[FWPM_CONNECTION_SUBSCRIPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection_subscription0)\***

The notifications which will be delivered.

### `callback` [in]

Type: **[FWPM_CONNECTION_CALLBACK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_connection_callback0)**

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

The caller needs [FWPM_ACTRL_SUBSCRIBE](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the connection object's container.

## See also

[FWPM_CONNECTION_CALLBACK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_connection_callback0)

[FWPM_CONNECTION_SUBSCRIPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection_subscription0)

[FwpmConnectionUnsubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectionunsubscribe0)