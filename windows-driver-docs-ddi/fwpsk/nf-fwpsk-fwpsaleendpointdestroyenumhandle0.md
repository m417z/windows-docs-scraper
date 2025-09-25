# FwpsAleEndpointDestroyEnumHandle0 function

## Description

The
**FwpsAleEndpointDestroyEnumHandle0** function destroys an endpoint enumeration handle that was created
by calling
[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0).

**Note** **FwpsAleEndpointDestroyEnumHandle0** is a specific version of **FwpsAleEndpointDestroyEnumHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

The handle for an open session with the filter engine. This handle is obtained when a session is
opened by calling
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0).

### `enumHandle` [in, out]

The enumeration handle created by a previous call to
[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0).

## Return value

The
**FwpsAleEndpointDestroyEnumHandle0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function succeeded. |
| **Other status codes** | An error occurred. |

## Remarks

When endpoint enumeration is complete, the enumeration handle must be destroyed by calling
**FwpsAleEndpointDestroyEnumHandle0**.

## See also

[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0)