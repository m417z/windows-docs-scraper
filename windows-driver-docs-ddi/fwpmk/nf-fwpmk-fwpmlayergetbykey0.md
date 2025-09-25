## Description

The **FwpmLayerGetByKey0** function retrieves a layer object.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `key` [in]

Unique identifier of the layer. See [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-) for a list of possible GUID values.

### `layer` [out]

The layer information.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The layer was retrieved successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The caller must free the returned object by a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**.

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the layer. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmLayerGetByKey0** is a specific implementation of **FwpmLayerGetByKey**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- **[FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)**
- [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)