## Description

Retrieves a provider context.

## Parameters

### `engineHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to an open session with the filter engine. To open a session with the filter engine, call [FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0).

### `key`

Type: \_In\_ **const [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

Pointer to a **GUID** that uniquely identifies the provider context. This is a pointer to the same **GUID** that was specified when your application called [FwpmProviderContextAdd3](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd3) for this object.

### `providerContext`

Type: \_Outptr\_ **[FWPM_PROVIDER_CONTEXT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)\*\***

The provider context information.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

|Return code/value|Description|
|-|-|
|ERROR_SUCCESS<br>0|The provider context was retrieved successfully.|
|FWP_E_* error code<br>0x80320001—0x80320039|A Windows Filtering Platform (WFP)-specific error. For details, see [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes).|
|RPC_* error code<br>0x80010001—0x80010122|Failure to communicate with the remote or local firewall engine.|

## Remarks

You must free the returned object by calling [FwpmFreeMemory0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmfreememory0).

To call this function, you need [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/win32/fwp/access-right-identifiers) access to the provider context. For more info, see [Access control](https://learn.microsoft.com/windows/win32/fwp/access-control).

## See also