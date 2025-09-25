# FwpsDiscardClonedStreamData0 function

## Description

The
**FwpsDiscardClonedStreamData0** function frees the memory buffer that is allocated by the
[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0) function.

**Note** **FwpsDiscardClonedStreamData0** is a specific version of **FwpsDiscardClonedStreamData**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferListChain` [in, out]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure chain that is
being freed. This will be the same as the
*netBufferListChain* parameter of the
[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0) function.

### `allocateCloneFlags`

There are currently no flags defined for this function. Callout drivers should set this parameter
to zero.

### `dispatchLevel` [in]

A value that indicates the current IRQL = DISPATCH_LEVEL. A callout driver should set this
parameter to **TRUE** only if it is running at IRQL = DISPATCH_LEVEL. Otherwise, a callout driver should set
this parameter to **FALSE**.

## Remarks

This function can be called when a cloned
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain is to be discarded
instead of being reinjected back into the data stream.

## See also

[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)