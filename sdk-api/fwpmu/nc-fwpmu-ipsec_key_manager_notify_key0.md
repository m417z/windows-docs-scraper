# IPSEC_KEY_MANAGER_NOTIFY_KEY0 callback function

## Description

The IPSEC_KEY_MANAGER_NOTIFY_KEY0 function is used to notify Trusted Intermediary Agents (TIAs) of the keys for the SA being negotiated.

## Parameters

### `inboundSa` [in]

Type: **const [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)***

Information about the inbound SA.

### `outboundSa` [in]

Type: **const [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)***

Information about the outbound SA.

## Remarks

Call [IPsecKeyManagerAddAndRegister](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0) to register this function pointer.

## See also

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)