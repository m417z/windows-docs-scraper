# FwpmProviderContextAdd0 function

## Description

The **FwpmProviderContextAdd0** function adds a new provider context to the system.

**Note** **FwpmProviderContextAdd0** is the specific implementation of FwpmProviderContextAdd used in Windows Vista. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpmProviderContextAdd1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd1) is available. For Windows 8, [FwpmProviderContextAdd2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd2) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `providerContext` [in]

Type: [FWPM_PROVIDER_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context0)*

The provider context object to be added.

### `sd` [in, optional]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)**

Security information associated with the provider context object.

### `id` [out, optional]

Type: **UINT64***

Pointer to a variable that receives a runtime identifier for this provider context.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The provider context was successfully added. |
| **ERROR_NOT_SUPPORTED**<br><br>0x32 | The [FWPM_IPSEC_IKE_MM_CONTEXT](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)and the [IKEEXT_IPV6_CGA](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_authentication_method_type) authentication method in the **authenticationMethods** array, but cryptographically generated address (CGA) is not enabled in the registry. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

Some fields in the [FWPM_PROVIDER_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context0) structure are assigned by the system, not the caller, and are ignored in the call to **FwpmProviderContextAdd0**.

If the caller supplies a **NULL** security descriptor, the system will assign a default security descriptor.

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the provider context's container and **FWPM_ACTRL_ADD_LINK** access to the provider (if any). See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[FWPM_PROVIDER_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context0)