# IPsecKeyManagersGet0 function

## Description

The **IPsecKeyManagersGet0** function returns a list of current Trusted Intermediary Agents (TIAs).

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `entries` [out]

Type: **[IPSEC_KEY_MANAGER0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_key_manager0)*****

All of the current TIAs.

### `numEntries` [out]

Type: **UINT32***

The number of entries returned.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The list of current TIAs was successfully returned. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The returned array of entries (but not the individual entries themselves) must be freed by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

## See also

[IPSEC_KEY_MANAGER0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_key_manager0)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)