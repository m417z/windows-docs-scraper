## Description

The **IPsecDospGetStatistics0** function retrieves Internet Protocol Security (IPsec) DoS Protection statistics.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `idpStatistics` [out]

Top-level object of IPsec DoS Protection statistics organization.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The IPsec DoS Protection statistics were successfully returned. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function cannot be called from within a transaction, it fails with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec DoS Protection component. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecDospGetStatistics0** is a specific implementation of **IPsecDospGetStatistics**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [IPSEC_DOSP_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_dosp_statistics0)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)