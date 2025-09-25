# FwpsNetBufferListRetrieveContext0 function

## Description

The
**FwpsNetBufferListRetrieveContext0** function retrieves the context associated with a network buffer
list that was tagged in another layer.

**Note** **FwpsNetBufferListRetrieveContext0** is a specific version of **FwpsNetBufferListRetrieveContext**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out]

A network buffer list that indicates one or more packets of interest to the callout driver. If
*removeContext* is set, the network buffer list returned will have the context removed.

### `contextTag` [in]

A locally unique identifier obtained by calling the
[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0) function. This is the context tag used in the initial call to
[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0).

### `removeContext` [in]

If set,
**FwpsNetBufferListRetrieveContext0** will remove the context association in addition to retrieving
the context.

### `flags` [in]

This parameter is reserved for future use and is set to zero.

### `context` [out]

The context assigned to the packet by the callout driver in the initial call to
**FwpsNetBufferListAssociateContext0**.

## Return value

The
**FwpsNetBufferListRetrieveContext0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The association was successful. |
| **Other status codes** | An error occurred. |

## Remarks

The
**FwpsNetBufferListRetrieveContext0** function retrieves a network buffer list that was tagged in
another layer.

You can also use this function to remove the context association by setting the
*removeContext* parameter.

## See also

[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0)

[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0)

[FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)