# IPsecSaContextGetSpi1 function

## Description

The **IPsecSaContextGetSpi1** function retrieves the security parameters index (SPI) for a security association (SA) context.

**Note** **IPsecSaContextGetSpi1** is the specific implementation of IPsecSaContextGetSpi used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows Vista, [IPsecSaContextGetSpi0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextgetspi0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

A runtime identifier for the SA context. This identifier was received from the system when the application called [IPsecSaContextCreate1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate1).

### `getSpi` [in]

Type: [IPSEC_GETSPI1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_getspi1)*

The inbound IPsec traffic.

### `inboundSpi` [out]

Type: **IPSEC_SA_SPI***

The inbound SA SPI. The **IPSEC_SA_SPI** data type maps to the **UINT32** data type.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The SPI for the IPsec SA context was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[IPSEC_GETSPI1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_getspi1)

[IPsecSaContextCreate0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate0)