# FwpmSubLayerUnsubscribeChanges0 function

## Description

The **FwpmSubLayerUnsubscribeChanges0** function is used to cancel a sublayer change subscription and stop receiving change notifications.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `changeHandle` [in]

Type: **HANDLE**

Handle of the subscribed change notification. This is the returned handle from the call to [FwpmSubLayerSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayersubscribechanges0).

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The subscription was deleted successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the callback is currently being invoked, this function will not return until it completes. Thus, when calling this function, you must not hold any locks that the callback may also try to acquire lest you deadlock.

It is not necessary to unsubscribe before closing a session; all subscriptions are automatically canceled when the subscribing session terminates.

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

**FwpmSubLayerUnsubscribeChanges0** is a specific implementation of FwpmSubLayerUnsubscribeChanges. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmSubLayerSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayersubscribechanges0)