## Description

The **FwpmProviderContextDeleteById0** function removes a provider context from the system.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `id` [in]

A runtime identifier for the object being removed from the system. This is the runtime identifier that was received from the system when the application called **[FwpmProviderContextAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmprovidercontextadd0)** for this object.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The provider context was successfully deleted. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function cannot be called from within a read-only transaction, it fails with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function can be called within a dynamic session if the corresponding object was added during the same session. If this function is called for an object that was added during a different dynamic session, it will fail with **FWP_E_WRONG_SESSION**. If this function is called for an object that was not added during a dynamic session, it fails with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**.

The caller needs [DELETE](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) access to the provider context. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmProviderContextDeleteById0** is a specific implementation of **FwpmProviderContextDeleteById**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmProviderContextAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmprovidercontextadd0)**
- [DELETE](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)