# FwpmIPsecTunnelAdd2 function

## Description

The **FwpmIPsecTunnelAdd2** function adds a new Internet Protocol Security (IPsec) tunnel mode policy to the system.

**Note** **FwpmIPsecTunnelAdd2** is the specific implementation of FwpmIPsecTunnelAdd used in Windows 8. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpmIPsecTunnelAdd1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmipsectunneladd1) is available. For Windows Vista, [FwpmIPsecTunnelAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmipsectunneladd0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `flags` [in]

Type: **UINT32**

Possible values:

| IPsec tunnel flag | Meaning |
| --- | --- |
| **FWPM_TUNNEL_FLAG_POINT_TO_POINT** | Adds a point-to-point tunnel to the system. |
| **FWPM_TUNNEL_FLAG_ENABLE_VIRTUAL_IF_TUNNELING** | Enables virtual interface-based IPsec tunnel mode. |

### `mainModePolicy` [in, optional]

Type: [FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)*

The Main Mode policy for the IPsec tunnel.

### `tunnelPolicy` [in]

Type: [FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)*

The Quick Mode policy for the IPsec tunnel.

### `numFilterConditions` [in]

Type: **UINT32**

Number of filter conditions present in the *filterConditions* parameter.

### `filterConditions` [in]

Type: [FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)*

Array of filter conditions that describe the traffic which should be tunneled by IPsec.

### `keyModKey` [in, optional]

Type: **const GUID***

Pointer to a GUID that uniquely identifies the keying module key.

If the caller supplies this parameter, only that keying module will be used for the tunnel. Otherwise, the default keying policy applies.

### `sd` [in, optional]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)**

The security information associated with the IPsec tunnel.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec tunnel mode policy was successfully added. |
| **FWP_E_INVALID_PARAMETER**<br><br>0x80320035 | FWPM_TUNNEL_FLAG_POINT_TO_POINT was not set and conditions other than local/remote address were specified. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

## See also

[FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)

[FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)