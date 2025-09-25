# IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0 callback function

## Description

The **IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0** function indicates whether the Trusted Intermediary Agent (TIA) will dictate the keys for the SA being negotiated.

## Parameters

### `ikeTraffic` [in]

Type: [IKEEXT_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_traffic0)*

Specifies the traffic for which keys should be set or retrieved.

### `willDictateKey` [out]

Type: **BOOL***

True if the TIA will dictate the keys; otherwise, false.

### `weight` [out]

Type: **UINT32***

Specifies the weight that this TIA should be given compared to any peers.

## Remarks

Call [IPsecKeyManagerAddAndRegister](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0) to register this function pointer.

If the TIA wants to dictate the keys, and its weight is higher than that of any peers, IPsec will subsequently call [IPSEC_KEY_MANAGER_DICTATE_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_dictate_key0).

## See also

[IKEEXT_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_traffic0)

[IPSEC_KEY_MANAGER_DICTATE_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_dictate_key0)

[IPsecKeyManagerAddAndRegister](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)