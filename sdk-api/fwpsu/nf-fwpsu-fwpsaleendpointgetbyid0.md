## Description

Retrieves information about an application layer enforcement (ALE) endpoint.

> [!NOTE]
> **FwpsAleEndpointGetById0** is a specific version of **FwpsAleEndpointGetById**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

A handle for an open session with the filter engine. This handle is obtained when a session is opened by calling **FwpmEngineOpen0**.

### `endpointId`

The unique endpoint identifier.

### `properties`

A pointer to an [FWPS_ALE_ENDPOINT_PROPERTIES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_properties0) structure that contains the properties of the endpoint.

## Return value

## Remarks

## See also