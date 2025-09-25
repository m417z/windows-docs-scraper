## Description

Destroys an endpoint enumeration handle that was created by calling [FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows/win32/api/fwpsu/nf-fwpsu-fwpsaleendpointcreateenumhandle0).

> [!NOTE]
> **FwpsAleEndpointDestroyEnumHandle0** is a specific version of **FwpsAleEndpointDestroyEnumHandle**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

Handle for an open session with the filter engine. This handle is obtained when a session is opened by calling **FwpmEngineOpen0**.

### `enumHandle`

The enumeration handle created by a previous call to [FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows/win32/api/fwpsu/nf-fwpsu-fwpsaleendpointcreateenumhandle0).

## Return value

## Remarks

## See also