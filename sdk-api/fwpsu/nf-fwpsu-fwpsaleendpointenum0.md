## Description

Enumerates application layer enforcement (ALE) endpoints.

> [!NOTE]
> **FwpsAleEndpointEnum0** is a specific version of **FwpsAleEndpointEnum**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

The handle for an open session with the filter engine. This handle is obtained when a session is opened by calling **FwpmEngineOpen0**.

### `enumHandle`

The enumeration handle created by a previous call to [FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows/win32/api/fwpsu/nf-fwpsu-fwpsaleendpointcreateenumhandle0).

### `numEntriesRequested`

The maximum number of endpoint property entries to return. The actual number of entries enumerated is returned in *numEntriesReturned*. The actual number is less than the requested number only if fewer endpoints than the requested are present.

### `entries`

A pointer to an array of [FWPS_ALE_ENDPOINT_PROPERTIES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_properties0) structure pointers. Each structure contains the properties of a single endpoint. The array contains as many elements as the value returned in *numEntriesReturned*.

### `numEntriesReturned`

On return, the number of elements in the array of endpoint property structures pointed to by *entries*.

## Return value

## Remarks

## See also