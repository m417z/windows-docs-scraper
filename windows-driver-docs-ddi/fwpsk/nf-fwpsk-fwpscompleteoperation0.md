# FwpsCompleteOperation0 function

## Description

The
**FwpsCompleteOperation0** function is called by a callout to resume packet processing that was suspended
pending completion of another operation.

**Note** **FwpsCompleteOperation0** is a specific version of **FwpsCompleteOperation**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `completionContext` [in]

A completion context handle that was previously created by a call to the
[FwpsPendOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendoperation0) function.

### `netBufferList` [in, optional]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data for which processing has been suspended pending completion of another operation.

## Remarks

When the callout is ready to resume packet processing after operations on the packet were suspended by
a call to
[FwpsPendOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendoperation0), the callout should
call the
**FwpsCompleteOperation0** function, passing it the
*completionContext* parameter value from
**FwpsPendOperation0** and the net buffer
list data that describes the packet.

To complete a connection that was previously pended at the FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_*Xxx* layer, the callout driver must reinject the packet that was cloned at that layer, and the
callout should also call
**FwpsCompleteOperation0**.

Pended connections are authenticated again after the
**FwpsCompleteOperation0** function executes. TCP connections, if allowed, are created by completing
the handshake operation, but non-TCP connections just create state entries. Any pended packet data
is flushed from memory when the
**FwpsPendOperation0** function completes, so an application will have to retransmit those packets
after
**FwpsCompleteOperation0** executes. The callout could buffer such data and reinject the data on the
application's behalf.

## See also

[FwpsPendOperation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendoperation0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)