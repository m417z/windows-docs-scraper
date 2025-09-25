# FwpsAleEndpointGetById0 function

## Description

The
**FwpsAleEndpointGetById0** function retrieves information about an application layer enforcement (ALE)
endpoint.

**Note** **FwpsAleEndpointGetById0** is a specific version of **FwpsAleEndpointGetById**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

A handle for an open session with the filter engine. This handle is obtained when a session is
opened by calling
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0).

### `endpointId` [in]

The unique endpoint identifier.

### `properties` [out]

A pointer to an
[FWPS_ALE_ENDPOINT_PROPERTIES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_properties0) structure that contains the properties of the endpoint.

## Return value

The
**FwpsAleEndpointGetById0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function succeeded. |
| **Other status codes** | An error occurred. |

## See also

[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointenum0)

[FwpsAleEndpointGetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointgetsecurityinfo0)

[FwpsAleEndpointSetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointsetsecurityinfo0)