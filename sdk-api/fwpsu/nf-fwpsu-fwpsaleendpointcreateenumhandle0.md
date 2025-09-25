## Description

Creates a handle that can be used with other application layer enforcement (ALE) endpoint functions to enumerate endpoint data.

> [!NOTE]
> **FwpsAleEndpointCreateEnumHandle0** is a specific version of **FwpsAleEndpointCreateEnumHandle**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

Handle for an open session with the filter engine. This handle is obtained when a session is opened by calling **FwpmEngineOpen0**.

### `enumTemplate`

A pointer to an [FWPS_ALE_ENDPOINT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_enum_template0) structure that contains parameters to narrow the endpoint enumeration results.

### `enumHandle`

The newly created enumeration handle.

## Return value

The **FwpsAleEndpointCreateEnumHandle0** function returns one of the following NTSTATUS codes.

|Return code|Description|
|-|-|
|STATUS_SUCCESS|The function succeeded.|
|Other status codes|An error occurred.|

## Remarks

After using the handle acquired by calling **FwpsAleEndpointCreateEnumHandle0**, the callout driver must release the system resources associated with the handle by calling [FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows/win32/api/fwpsu/nf-fwpsu-fwpsaleendpointdestroyenumhandle0).

## See also