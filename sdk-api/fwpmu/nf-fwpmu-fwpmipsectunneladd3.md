## Description

Adds a new Internet Protocol Security (IPsec) tunnel mode policy to the system.

## Parameters

### `engineHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to an open session with the filter engine. To open a session with the filter engine, call [FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0).

### `flags`

Type: \_In\_ **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Possible values:

|IPsec tunnel flag|Meaning|
|-|-|
|FWPM_TUNNEL_FLAG_POINT_TO_POINT|Adds a point-to-point tunnel to the system.|
|FWPM_TUNNEL_FLAG_ENABLE_VIRTUAL_IF_TUNNELING|Enables virtual interface-based IPsec tunnel mode.|

### `mainModePolicy`

Type: \_In\_opt\_ **const [FWPM_PROVIDER_CONTEXT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)\***

An optional Main Mode policy for the IPsec tunnel.

### `tunnelPolicy`

Type: \_In\_ **const [FWPM_PROVIDER_CONTEXT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)\***

The Quick Mode policy for the IPsec tunnel.

### `numFilterConditions`

Type: \_In\_ **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of filter conditions present in *filterConditions*.

### `filterConditions`

Type: \_In\_reads\_\(numFilterConditions\) **const [FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)\***

An array of filter conditions that describe the traffic that should be tunneled by IPsec.

### `keyModKey`

Type: \_In\_opt\_ **const [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

An optional pointer to a GUID that uniquely identifies the keying module key. If you supply this parameter, then only that keying module will be used for the tunnel. Otherwise, the default keying policy applies.

### `sd`

Type: \_In\_opt\_ **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor)**

The security information associated with the IPsec tunnel.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

|Return code/value|Description|
|-|-|
|ERROR_SUCCESS<br>0|The IPsec tunnel mode policy was successfully added.|
|FWP_E_INVALID_PARAMETER<br>0x80320035|FWPM_TUNNEL_FLAG_POINT_TO_POINT wasn't set, and conditions other than local/remote address were specified.|
|FWP_E_* error code<br>0x80320001—0x80320039|A Windows Filtering Platform (WFP)-specific error. For details, see [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes).|
|RPC_* error code<br>0x80010001—0x80010122|Failure to communicate with the remote or local firewall engine.|

## Remarks

You can't call this function within a read-only transaction. It will fail with **FWP_E_INCOMPATIBLE_TXN**. For more info about transactions, see [Object management](https://learn.microsoft.com/windows/win32/fwp/object-management).

## See also