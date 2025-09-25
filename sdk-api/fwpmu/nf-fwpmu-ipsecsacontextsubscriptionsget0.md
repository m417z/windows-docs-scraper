# IPsecSaContextSubscriptionsGet0 function

## Description

The **IPsecSaContextSubscriptionsGet0** function retrieves an array of all the current IPsec security association (SA) change notification subscriptions.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `entries` [out]

Type: **[IPSEC_SA_CONTEXT_SUBSCRIPTION0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_subscription0)*****

The current IPsec SA notification subscriptions.

### `numEntries` [out]

Type: **UINT32***

The number of entries returned.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The subscriptions were retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The returned array (but not the individual entries in the array) must be freed through a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

## See also

[IPSEC_SA_CONTEXT_SUBSCRIPTION0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_subscription0)