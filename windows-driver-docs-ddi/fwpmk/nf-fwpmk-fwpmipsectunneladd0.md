## Description

The **FwpmIPsecTunnelAdd0** function adds a new Internet Protocol Security (IPsec) tunnel mode policy to the system.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `flags` [in]

Possible values:

| IPsec tunnel flag | Meaning |
| --- | --- |
| **FWPM_TUNNEL_FLAG_POINT_TO_POINT** | Adds a point-to-point tunnel to the system. |

### `mainModePolicy` [in, optional]

The Main Mode policy for the IPsec tunnel.

### `tunnelPolicy` [in]

The Quick Mode policy for the IPsec tunnel.

### `numFilterConditions` [in]

Number of filter conditions present in the *filterConditions* parameter.

### `filterConditions` [ in, reads(numFilterConditions)]

Array of filter conditions that describe the traffic which should be tunneled by IPsec.

### `sd` [in, optional]

The security information associated with the IPsec tunnel.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br>0 | The IPsec tunnel mode policy was successfully added. |
| **FWP_E_INVALID_PARAMETER**<br>0x80320035 | FWPM_TUNNEL_FLAG_POINT_TO_POINT was not set and conditions other than local/remote address were specified. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function cannot be called from within a read-only transaction, it fails with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

**FwpmIPsecTunnelAdd0** is a specific implementation of **FwpmIPsecTunnelAdd**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)**
- **[FWPM_PROVIDER_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context0)**
- [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)