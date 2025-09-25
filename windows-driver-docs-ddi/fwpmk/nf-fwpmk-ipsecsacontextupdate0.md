## Description

The **IPsecSaContextUpdate0** function updates an IPsec security association (SA) context.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `flags` [in]

Flags indicating the specific field in the IPSEC_SA_CONTEXT1 structure that is being updated.

Possible values:

| IPsec SA flag | Meaning |
|--|--|
| **IPSEC_SA_DETAILS_UPDATE_TRAFFIC** | Updates the [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure. |
| **IPSEC_SA_DETAILS_UPDATE_UDP_ENCAPSULATION** | Updates the [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_FLAGS** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_NAP_CONTEXT** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_KEY_MODULE_STATE** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_PEER_V4_PRIVATE_ADDRESS** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |
| **IPSEC_SA_BUNDLE_UPDATE_MM_SA_ID** | Updates the [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure. |

### `newValues` [in]

An inbound and outbound SA pair.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The IPsec SA context was updated successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

**IPsecSaContextUpdate0** is a specific implementation of **IPsecSaContextUpdate**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [IPSEC_SA_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context1)
- [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1)
- [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)