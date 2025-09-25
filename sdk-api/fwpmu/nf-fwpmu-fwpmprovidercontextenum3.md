## Description

Returns the next page of results from the provider context enumerator.

## Parameters

### `engineHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to an open session with the filter engine. To open a session with the filter engine, call [FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0).

### `enumHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to a network event enumeration created by a call to [FwpmProviderContextCreateEnumHandle0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmprovidercontextcreateenumhandle0).

### `numEntriesRequested`

Type: \_In\_ **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of provider context objects requested.

### `entries`

Type: \_Outptr\_result\_buffer\_\(*numEntriesReturned\) **[FWPM_PROVIDER_CONTEXT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)\*\*\***

The returned provider context objects.

### `numEntriesReturned`

Type: \_Out\_ **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The number of provider context objects returned.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

|Return code/value|Description|
|-|-|
|ERROR_SUCCESS<br>0|The provider contexts were enumerated successfully.|
|FWP_E_* error code<br>0x80320001—0x80320039|A Windows Filtering Platform (WFP)-specific error. For details, see [WFP error codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes).|
|RPC_* error code<br>0x80010001—0x80010122|Failure to communicate with the remote or local firewall engine.|

## Remarks

If *numEntriesReturned* is less than the *numEntriesRequested*, then the enumeration is exhausted.

You must free the returned array of entries (but not the individual entries themselves) by calling [FwpmFreeMemory0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmfreememory0).

A subsequent call that uses the same *enumHandle* parameter will return the next set of events following those in the last output buffer.

**FwpmProviderContextEnum3** works on a snapshot of the provider contexts taken at the time the enumeration handle was created.

## See also