## Description

The **IPSEC_KEY_MANAGER_DICTATE_KEY0** function is used by the Trusted Intermediary Agent (TIA) to dictate keys for the SA being negotiated.

## Parameters

### `inboundSaDetails`

Type: [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)*

Information about the inbound SA.

### `outboundSaDetails`

Type: [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)*

Information about the outbound SA.

### `keyingModuleGenKey`

Type: **BOOL***

True if the keying module should randomly generate keys in the event that the TIA is unable to supply keys; otherwise, false.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The keys were successfully dictated |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

Call [IPsecKeyManagerAddAndRegister0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0) to invoke this function pointer. If the weight specified in [IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_key_dictation_check0) for a TIA is higher than that of any peer, **IPSEC_KEY_MANAGER_DICTATE_KEY0** will be invoked.

## See also

[IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_key_dictation_check0)

[IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)

[IPsecKeyManagerAddAndRegister0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0)

[WFP functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)