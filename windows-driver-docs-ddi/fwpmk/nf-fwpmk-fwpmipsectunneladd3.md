## Description

The **FwpmIPsecTunnelAdd3** function adds a new Internet Protocol Security (IPsec) tunnel mode policy to the system.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `flags` [in]

Possible values:

| IPsec tunnel flag | Meaning |
|--|--|
| **FWPM_TUNNEL_FLAG_POINT_TO_POINT** | Adds a point-to-point tunnel to the system. |
| **FWPM_TUNNEL_FLAG_ENABLE_VIRTUAL_IF_TUNNELING** | Enables virtual interface-based IPsec tunnel mode. |

### `mainModePolicy` [in, optional]

An optional Main Mode policy for the IPsec tunnel.

### `tunnelPolicy` [in]

The Quick Mode policy for the IPsec tunnel.

### `numFilterConditions` [in]

The number of filter conditions present in *filterConditions*.

### `filterConditions` [in, reads(numFilterConditions)]

An array of filter conditions that describe the traffic that should be tunneled by IPsec.

### `keyModKey` [in, optional]

An optional pointer to a GUID that uniquely identifies the keying module key. If you supply this parameter, then only that keying module will be used for the tunnel. Otherwise, the default keying policy applies.

### `sd` [in, optional]

The security information associated with the IPsec tunnel.

## Return value

| Return code/value | Description |
|--|--|
| **ERROR_SUCCESS**<br>0 | The IPsec tunnel mode policy was successfully added. |
| **FWP_E_INVALID_PARAMETER**<br>0x80320035 | FWPM_TUNNEL_FLAG_POINT_TO_POINT wasn't set, and conditions other than local/remote address were specified. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP)-specific error. For details, see [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes). |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

You can't call this function within a read-only transaction, it fails with **FWP_E_INCOMPATIBLE_TXN**. For more info about transactions, see [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management).

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)