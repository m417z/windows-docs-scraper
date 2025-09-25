# FwpsFreeNetBufferList0 function

## Description

The
**FwpsFreeNetBufferList0** function frees a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that was previously
allocated by a call to the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function.

**Note** **FwpsFreeNetBufferList0** is a specific version of **FwpsFreeNetBufferList**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is being
freed.

## Remarks

A callout driver calls the
**FwpsFreeNetBufferList0** function to free a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that was
previously allocated by a call to the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function.

## See also

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)