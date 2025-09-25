## Description

The **IPsecSaContextSetSpi0** function sets the security parameters index (SPI) for a security association (SA) context.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `id` [in]

A runtime identifier for the SA context. This identifier was received from the system when the application called **[IPsecSaContextCreate1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ipsecsacontextcreate1)**.

### `getSpi` [in]

The inbound IPsec traffic.

### `inboundSpi` [in]

The inbound SA SPI. The **IPSEC_SA_SPI** data type maps to the **UINT32** data type.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The SPI for the IPsec SA context was set successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecSaContextSetSpi0** is a specific implementation of **IPsecSaContextSetSpi**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[IPsecSaContextCreate1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ipsecsacontextcreate1)**
- [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [IPSEC_GETSPI1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_getspi1)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)