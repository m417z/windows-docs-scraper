## Description

The **IPsecSaContextCreate1** function creates an IPsec security association (SA) context.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `outboundTraffic` [in]

The outbound traffic of the SA.

### `virtualIfTunnelInfo` [in, optional]

Details related to virtual interface tunneling.

### `inboundFilterId` [out, optional]

Optional filter identifier of the cached inbound filter corresponding to the *outboundTraffic* parameter specified by the caller. Base filtering engine (BFE) may cache the inbound filter identifier and return the cached value, if available. Caller must handle the case when BFE does not have a cached value, in which case this parameter will be set to 0.

### `id` [out]

The identifier of the IPsec SA context.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The IPsec SA context was created successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function cannot be called from within a transaction, it fails with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function cannot be called from within a dynamic session. The call fails with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about dynamic sessions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecSaContextCreate1** is a specific implementation of **IPsecSaContextCreate**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [IPSEC_TRAFFIC1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic0)
- [IPSEC_VIRTUAL_IF_TUNNEL_INFO0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-ipsec_virtual_if_tunnel_info0)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)