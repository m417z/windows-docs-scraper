# IPsecSaContextUpdate0 function

## Description

The **IPsecSaContextUpdate0** function updates an IPsec security association (SA) context.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `flags` [in]

Type: **UINT32**

Flags indicating the specific field in the [IPSEC_SA_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context1) structure that is being updated.

Possible values:

| IPsec SA flag | Meaning |
| --- | --- |
| **IPSEC_SA_DETAILS_UPDATE_TRAFFIC** | Updates the [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure. |
| **IPSEC_SA_DETAILS_UPDATE_UDP_ENCAPSULATION** | Updates the [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_FLAGS** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_NAP_CONTEXT** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_KEY_MODULE_STATE** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_PEER_V4_PRIVATE_ADDRESS** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_MM_SA_ID** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |

### `newValues` [in]

Type: [IPSEC_SA_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context1)*

An inbound and outbound SA pair.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec SA context was updated successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

**IPsecSaContextUpdate0** is a specific implementation of IPsecSaContextUpdate. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_SA_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context1)