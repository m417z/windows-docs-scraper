# FwpsAleEndpointCreateEnumHandle0 function

## Description

The
**FwpsAleEndpointCreateEnumHandle0** function creates a handle that can be used with other application layer enforcement (ALE) endpoint
functions to enumerate endpoint data.

**Note** **FwpsAleEndpointCreateEnumHandle0** is a specific version of **FwpsAleEndpointCreateEnumHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

Handle for an open session with the filter engine. This handle is obtained when a session is
opened by calling
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0).

### `enumTemplate` [in, optional]

A pointer to an
[FWPS_ALE_ENDPOINT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_enum_template0) structure that contains parameters to narrow the endpoint
enumeration results.

### `enumHandle` [out]

The newly created enumeration handle.

## Return value

The
**FwpsAleEndpointCreateEnumHandle0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function succeeded. |
| **Other status codes** | An error occurred. |

## Remarks

After using the handle acquired by calling
**FwpsAleEndpointCreateEnumHandle0**, the callout driver must release the system resources associated
with the handle by calling
[FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointdestroyenumhandle0).

## See also

[FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointdestroyenumhandle0)

[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointenum0)