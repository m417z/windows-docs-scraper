# FwpsNetBufferListAssociateContext0 function

## Description

The
**FwpsNetBufferListAssociateContext0** function associates the callout driver's context with a network buffer
list and configures notification for network buffer list events.

**Note** **FwpsNetBufferListAssociateContext0** is the specific version of **FwpsNetBufferListAssociateContext** used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1) is available.

## Parameters

### `netBufferList` [in, out]

A network buffer list that indicates one or more packets of interest to the callout driver.

### `layerId` [in]

The identifier of the layer in which the context is being associated. When calling this function
from the NDIS receive path, set this parameter to FWPS_LAYER_NON_WFP.

### `context` [in]

Arbitrary context information set by the callout driver. The filter engine will pass this context
to the callout driver's
[FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0).

### `contextTag` [in]

A locally unique identifier obtained by calling the
[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0) function.

### `providerGuid`

The provider GUID.

### `deviceObject` [in, out]

A pointer to the callout driver's device object.

### `notifyFn` [in]

A pointer to the callout driver's
[FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0) function. The filter engine will send status notifications to this
function.

### `flags` [in]

This parameter is reserved for future use and is set to zero.

## Return value

The
**FwpsNetBufferListAssociateContext0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The association was successful. |
| **Other status codes** | An error occurred. |

## Remarks

The
**FwpsNetBufferListAssociateContext0** function associates groups of packets with the callout driver.
Packets of interest can be tracked for inspection through multiple layers in the stack.

Before calling this function, the
[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0) function must be called to obtain a context tag.

## See also

[FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1)

[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0)

[FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0)

[FwpsNetBufferListRetrieveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistretrievecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Using Packet Tagging](https://learn.microsoft.com/windows-hardware/drivers/network/using-packet-tagging)