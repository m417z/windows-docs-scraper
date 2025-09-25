# FwpsDereferenceNetBufferList0 function

## Description

The
**FwpsDereferenceNetBufferList0** function decrements the reference count for a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that a callout
driver had acquired earlier using the
[FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0) function.

**Note** **FwpsDereferenceNetBufferList0** is a specific version of **FwpsDereferenceNetBufferList**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for which the
reference count is being decremented.

### `dispatchLevel` [in]

A value that indicates that the current IRQL = DISPATCH_LEVEL. A callout driver should set this
parameter to **TRUE** only if it is known that it is running at IRQL = DISPATCH_LEVEL. Otherwise a callout
driver sets this parameter to **FALSE**.

## Remarks

A callout driver calls the
**FwpsDereferenceNetBufferList0** function to decrement the reference count for a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that it had
acquired earlier using the
[FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0) function. A callout driver must not call the
**FwpsDereferenceNetBufferList0** function for a NET_BUFFER_LIST structure unless it previously called
the
**FwpsReferenceNetBufferList0** for the same structure.

## See also

[FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)