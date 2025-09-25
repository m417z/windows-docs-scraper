# IPsecSaContextGetById0 function

## Description

The **IPsecSaContextGetById0** function retrieves an IPsec security association (SA) context.

**Note** **IPsecSaContextGetById0** is the specific implementation of IPsecSaContextGetById used in Windows Vista. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7 and later, [IPsecSaContextGetById1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextgetbyid1) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

A runtime identifier for the SA context. This identifier was received from the system when the application called [IPsecSaContextCreate0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate0).

### `saContext` [out]

Type: [IPSEC_SA_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context0)**

Address of the IPsec SA context.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec SA context was successfully retrieved. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free the returned object, *saContext*, by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[IPSEC_SA_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context0)

[IPsecSaContextCreate0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate0)