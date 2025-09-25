# FwpmProviderAdd0 function

## Description

The **FwpmProviderAdd0** function adds a new provider to the system.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `provider` [in]

Type: [FWPM_PROVIDER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider0)*

The provider object to be added.

### `sd` [in, optional]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)**

Security information for the provider object.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The provider was successfully added. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the caller supplies a null security descriptor, the system will assign a default security descriptor.

Boot-time objects are added to the Base Filtering Engine (BFE) when the TCP/IP driver starts, and are removed once the BFE finishes initialization. Persistent objects are added when the BFE starts. If a policy provider has a persistent policy that is not intended to be enforced if its associated service is disabled, the caller can specify an optional service name in the [FWPM_PROVIDER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider0) structure. This service then owns the persistent policy object. At start, the BFE only adds the following types of persistent objects to the system.

* The object is not associated with a provider.
* The object has an associated provider that does not specify a service name.
* The object has an associated provider and an associated service set to auto-start.

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the provider's container. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmProviderAdd0** is a specific implementation of FwpmProviderAdd. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_PROVIDER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider0)