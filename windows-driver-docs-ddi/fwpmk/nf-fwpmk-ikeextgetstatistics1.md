## Description

The **IkeextGetStatistics1** function retrieves Internet Key Exchange (IKE) and Authenticated Internet Protocol (AuthIP) statistics.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `ikeextStatistics` [out]

The top-level object of IKE/AuthIP statistics organization.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The information was retrieved successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The caller needs [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IKE/AuthIP security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IkeextGetStatistics1** is a specific implementation of **IkeextGetStatistics**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)
- [IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)
- [Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)