# FwpsNetBufferListRemoveContext0 function

## Description

The
**FwpsNetBufferListRemoveContext0** function removes the context associated with a network buffer
list.

**Note** **FwpsNetBufferListRemoveContext0** is a specific version of **FwpsNetBufferListRemoveContext**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out, optional]

A network buffer list that indicates one or more packets of interest to the callout driver. This
parameter is optional and can be **NULL**. If it is **NULL**, the function will remove the context from all associated network
buffer lists.

### `contextTag` [in]

The context tag that was passed in the *contextTag* parameter to
[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0).

### `flags` [in]

This parameter is reserved for future use and must be zero.

## Return value

The
**FwpsNetBufferListRemoveContext0** function returns one of the following **NTSTATUS** codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The context was successfully removed. |
| **Other status codes** | An error occurred. |

## Remarks

The
**FwpsNetBufferListRemoveContext0** function asynchronously removes the tagged context associated with a network buffer list.

To associate a context with a network buffer list, call
[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0) or [FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1).

Usually a callout driver will not need to use this function, because the tagged context
is removed automatically when the packets move through the stack. This function is provided so that
a callout driver can stop processing in situations where contexts aren't removed automatically. For example, in the case of an NDIS filter driver, the packets never enter the TCP/IP stack, and the contexts will need to be removed manually by calling **FwpsNetBufferListRemoveContext0** with the *netBufferList* parameter set to **NULL**.

## See also

[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0)

[FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1)

[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0)

[FwpsNetBufferListRetrieveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistretrievecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Using Packet Tagging](https://learn.microsoft.com/windows-hardware/drivers/network/using-packet-tagging)