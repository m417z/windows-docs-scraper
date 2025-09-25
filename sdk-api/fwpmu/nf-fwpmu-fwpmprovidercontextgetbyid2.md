# FwpmProviderContextGetById2 function

## Description

The **FwpmProviderContextGetById2** function retrieves a provider context.

**Note** **FwpmProviderContextGetById2** is the specific implementation of FwpmProviderContextGetById used in Windows 8. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpmProviderContextGetById1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextgetbyid1) is available. For Windows Vista, [FwpmProviderContextGetById0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextgetbyid0) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

A run-time identifier for the desired object. This must be the run-time identifier that was received from the system when the application called [FwpmProviderContextAdd2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd2) for this object.

### `providerContext` [out]

Type: [FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)**

The provider context information.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The provider context was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free the returned object by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the provider context. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)

[FwpmProviderContextAdd2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd2)