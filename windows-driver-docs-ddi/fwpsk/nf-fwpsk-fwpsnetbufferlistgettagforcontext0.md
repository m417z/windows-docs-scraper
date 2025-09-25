# FwpsNetBufferListGetTagForContext0 function

## Description

The **FwpsNetBufferListGetTagForContext0** function gets a locally unique context tag that can be used to
associate packets with the callout driver.

**Note** **FwpsNetBufferListGetTagForContext0** is a specific version of **FwpsNetBufferListGetTagForContext**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Return value

The
**FwpsNetBufferListGetTagForContext0** function returns a locally unique identifier.

## Remarks

The
**FwpsNetBufferListGetTagForContext0** function must be called before calling
[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0).

## See also

[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0)

[FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0)

[FwpsNetBufferListRetrieveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistretrievecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Using Packet Tagging](https://learn.microsoft.com/windows-hardware/drivers/network/using-packet-tagging)