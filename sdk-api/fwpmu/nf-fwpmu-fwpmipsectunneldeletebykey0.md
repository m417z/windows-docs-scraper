# FwpmIPsecTunnelDeleteByKey0 function

## Description

The **FwpmIPsecTunnelDeleteByKey0** function removes an Internet Protocol Security (IPsec) tunnel mode policy from the system.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `key` [in]

Type: **const GUID***

Unique identifier of the IPsec tunnel. This GUID was specified in the **providerContextKey** member of the *tunnelPolicy* parameter of the [FwpmIPsecTunnelAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmipsectunneladd0) function.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec tunnel mode policy was successfully deleted. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

**FwpmIPsecTunnelDeleteByKey0** is a specific implementation of FwpmIPsecTunnelDeleteByKey. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmIPsecTunnelAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmipsectunneladd0)