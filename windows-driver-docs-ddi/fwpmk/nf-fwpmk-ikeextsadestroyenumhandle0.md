## Description

The **IkeextSaDestroyEnumHandle0** function frees a handle returned by **[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsacreateenumhandle0)**.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `enumHandle` [in]

Handle of the enumeration to destroy. Previously created by a call to **[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsacreateenumhandle0)**.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The enumeration was deleted successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

**IkeextSaDestroyEnumHandle0** is a specific implementation of **IkeextSaDestroyEnumHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsacreateenumhandle0)**
- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)
- [IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)
- [Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)