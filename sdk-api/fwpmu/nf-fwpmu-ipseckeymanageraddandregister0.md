# IPsecKeyManagerAddAndRegister0 function

## Description

The **IPsecKeyManagerAddAndRegister0** function registers a Trusted Intermediary Agent (TIA) with IPsec.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `keyManager` [in]

Type: **const [IPSEC_KEY_MANAGER0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_key_manager0)***

The set of key management callbacks which IPsec will invoke.

### `keyManagerCallbacks` [in]

Type: **const [IPSEC_KEY_MANAGER_CALLBACKS0](https://learn.microsoft.com/windows/desktop/api/fwpmu/ns-fwpmu-ipsec_key_manager_callbacks0)***

The set of callbacks which should be invoked by IPsec at various stages of SA negotiation.

### `keyMgmtHandle` [out]

Type: **HANDLE***

Address of the newly created registration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The TIA was successfully registered. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **FWP_E_ALREADY_EXISTS**<br><br>0x80320009L | The TIA was not registered successfully because another TIA has already been registered to dictate keys. |
| **FWP_E_INVALID_INTERVAL**<br><br>0x80320021L | The TIA was not registered successfully because *keyDictationTimeoutHint* exceeded the maximum allowed value of 10 seconds. |
| **SEC_E_CANNOT_INSTALL**<br><br>0x80090307L | The TIA was not registered successfully because the binary image has not set the **IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY** property. |

## Remarks

If the **IPSEC_KEY_MANAGER_FLAG_DICTATE_KEY** flag is set for **keyManager**, all three callback members of **keyManagerCallbacks** must be specified; otherwise, only the **keyNotify** callback should be specified

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

## See also

[IPSEC_KEY_MANAGER0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_key_manager0)

[IPSEC_KEY_MANAGER_CALLBACKS0](https://learn.microsoft.com/windows/desktop/api/fwpmu/ns-fwpmu-ipsec_key_manager_callbacks0)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)