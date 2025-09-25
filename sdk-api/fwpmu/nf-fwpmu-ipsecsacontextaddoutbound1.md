# IPsecSaContextAddOutbound1 function

## Description

The **IPsecSaContextAddOutbound1** function adds an outbound IPsec security association (SA) bundle to an existing SA context.

**Note** **IPsecSaContextAddOutbound1** is the specific implementation of IPsecSaContextAddOutbound used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows Vista, [IPsecSaContextAddOutbound0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextaddoutbound0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

Identifier for the existing IPsec SA context. This is the value returned in the *id* parameter by the call to [IPsecSaContextCreate1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate1).

### `outboundBundle` [in]

Type: [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1)*

The outbound IPsec SA bundle to be added to the SA context.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec SA bundle was successfully added to the SA context. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## See also

[IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1)

[IPsecSaContextCreate1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate1)