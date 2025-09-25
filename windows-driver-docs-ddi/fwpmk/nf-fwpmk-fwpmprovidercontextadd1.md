## Description

The **FwpmProviderContextAdd1** function adds a new provider context to the system.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `providerContext` [in]

The provider context object to be added.

### `sd` [in, optional]

Security information associated with the provider context object.

### `id` [out, optional]

Pointer to a variable that receives a runtime identifier for this provider context.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The provider context was successfully added. |
| **ERROR_NOT_SUPPORTED**<br>0x32 | The [FWPM_IPSEC_IKE_MM_CONTEXT](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)and the [IKEEXT_IPV6_CGA](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_authentication_method_type) authentication method in the **authenticationMethods** array, but cryptographically generated address (CGA) is not enabled in the registry. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

Some fields in the [FWPM_PROVIDER_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context1) structure are assigned by the system, not the caller, and are ignored in the call to **FwpmProviderContextAdd1**.

If the caller supplies a **NULL** security descriptor, the system assigns a default security descriptor.

This function cannot be called from within a read-only transaction, it fails with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the provider context's container and **FWPM_ACTRL_ADD_LINK** access to the provider (if any). See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmProviderContextAdd0** is a specific implementation of **FwpmProviderContextAdd**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [FWPM_IPSEC_IKE_MM_CONTEXT](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)
- [FWPM_PROVIDER_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context1)
- [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [IKEEXT_IPV6_CGA](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_authentication_method_type)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)