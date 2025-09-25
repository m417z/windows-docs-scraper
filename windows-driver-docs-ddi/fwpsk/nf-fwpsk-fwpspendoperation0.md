# FwpsPendOperation0 function

## Description

The
**FwpsPendOperation0** function is called by a callout to suspend packet processing pending completion of
another operation.

**Note** **FwpsPendOperation0** is a specific version of **FwpsPendOperation**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `completionHandle` [in]

A completion handle that is required to pend the current filtering operation. This parameter is
obtained from the
**completionHandle** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure passed into the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function.

### `completionContext` [out]

The handle to the completion context of this pend operation. When the callout is ready to resume
packet processing, it calls the
[FwpsCompleteOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteoperation0) function
with the value of this parameter as the input
*completionContext* parameter.

## Return value

The
**FwpsPendOperation0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Packet processing was successfully pended. |
| **STATUS_FWP_CANNOT_PEND** | A call was made to **FwpsPendOperation0** in a reauthorization classify operation. For more information, see Remarks. |
| **STATUS_FWP_NULL_POINTER** | One or more of the parameters is invalid. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to allow this operation. |
| **Other status codes** | An error occurred. |

## Remarks

The callout should retain the
*completionContext* parameter value until it resumes packet processing. When the operation that
prompted the call to this function has completed, the callout should call the
[FwpsCompleteOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteoperation0) function,
passing it the
*completionContext* parameter value.

A callout can call this function only to pend a packet that originates from the
FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_
*Xxx*, FWPM_LAYER_ALE_AUTH_LISTEN_
*Xxx*, or FWPM_LAYER_ALE_AUTH_CONNECT_
*Xxx* [filtering layers](https://learn.microsoft.com/windows-hardware/drivers/network/using-layer-2-filtering). A callout can
pend the current processing operation on a packet when the callout must perform processing on one of
these layers that may take a long interval to complete or that should occur at IRQL = PASSIVE_LEVEL if
the current IRQL > PASSIVE_LEVEL.

To complete a connection that was previously pended at the FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_
*Xxx* layer, the callout driver must reinject the packet that was cloned at that layer as well as
call the
**FwpsCompleteOperation0** function.

To be able to pend packet processing, the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function should set the
**actionType** member of the
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure to
FWP_ACTION_BLOCK and the
**Flags** member to FWPS_CLASSIFY_OUT_FLAG_ABSORB.

Pended connections are reauthenticated after the
**FwpsCompleteOperation0** function executes. TCP connections, if allowed, are created by completing
the handshake operation, but non-TCP connections only create state entries. Any pended packet data
is flushed from memory when the
**FwpsPendOperation0** function completes, so applications must retransmit those packets after
**FwpsCompleteOperation0** runs. Callouts could buffer such data and reinject the data on their
behalf.

Only an initial Application Layer Enforcement (ALE) flow authorization can be postponed by calling
**FwpsPendOperation0** and
**FwpsCompleteOperation0**. If an ALE flow is reauthorized, the FWP_CONDITION_FLAG_IS_REAUTHORIZE flag
is set. A call to
**FwpsPendOperation0** from the FWPM_LAYER_ALE_AUTH_CONNECT_
*Xxx* or FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_
*Xxx* [filtering layers](https://learn.microsoft.com/windows-hardware/drivers/network/using-layer-2-filtering) will fail if the
FWP_CONDITION_FLAG_IS_REAUTHORIZE flag is set, and the STATUS_FWP_CANNOT_PEND status code will be
returned. For more information, see ALE Reauthorization in the Windows SDK.

## See also

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FwpsCompleteOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteoperation0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)