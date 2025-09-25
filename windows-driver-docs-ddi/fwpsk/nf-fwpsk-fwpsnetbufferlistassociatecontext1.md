# FwpsNetBufferListAssociateContext1 function

## Description

The
**FwpsNetBufferListAssociateContext1** function associates the callout driver's context with a network buffer
list and configures notification for network buffer list events.

**Note** **FwpsNetBufferListAssociateContext1** is the specific version of **FwpsNetBufferListAssociateContext** used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0) is available.

## Parameters

### `netBufferList` [in, out]

A network buffer list that indicates one or more packets of interest to the callout driver.

### `layerId` [in]

The identifier of the layer in which the context is being associated. When calling this function
from the NDIS receive path, set this parameter to **FWPS_LAYER_NON_WFP**.

### `context` [in]

Arbitrary context information set by the callout driver. The filter engine will pass this context
to the callout driver's
[FWPS_NET_BUFFER_LIST_NOTIFY_FN1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn1) function.

### `contextTag` [in]

A locally unique identifier obtained by calling the
[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0) function.

### `providerGuid`

The provider GUID.

### `deviceObject` [in, out]

A pointer to the callout driver's device object.

### `notifyFn` [in]

A pointer to the callout driver's
[FWPS_NET_BUFFER_LIST_NOTIFY_FN1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn1) function. The filter engine will send status notifications to this
function.

### `flags` [in]

This parameter is reserved for future use and is set to zero.

## Return value

The
**FwpsNetBufferListAssociateContext1** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The association was successful. |
| **Other status codes** | An error occurred. |

## Remarks

The
**FwpsNetBufferListAssociateContext1** function associates groups of packets with the callout driver.
Packets of interest can be tracked for inspection through multiple layers in the stack.

Before calling this function, the
[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0) function must be called to obtain a context tag.

This function is essentially identical to the previous version,
[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0). The only difference is the
updated [FWPS_NET_BUFFER_LIST_NOTIFY_FN1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn1) function pointed to by the
*notifyFn* parameter.

## See also

[FWPS_NET_BUFFER_LIST_NOTIFY_FN1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn1)

[FwpsNetBufferListAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext0)

[FwpsNetBufferListGetTagForContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistgettagforcontext0)

[FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0)

[FwpsNetBufferListRetrieveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistretrievecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Using Packet Tagging](https://learn.microsoft.com/windows-hardware/drivers/network/using-packet-tagging)