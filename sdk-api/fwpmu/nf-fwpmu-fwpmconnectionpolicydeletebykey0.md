## Description

Removes the Connection Policy that was created with the GUID specified in the [FWPM_PROVIDER_CONTEXT::providerContextKey](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3) when you called [FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmconnectionpolicyadd0).

## Parameters

### `engineHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to an open session with the filter engine. To open a session with the filter engine, call [FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0).

### `key`

Type: \_In\_ **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The GUID of the Connection Policy that was created when you called [FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmconnectionpolicyadd0).

## Return value

## Remarks

## See also