# FILTER_SEND_NET_BUFFER_LISTS_COMPLETE callback function

## Description

NDIS calls the
*FilterSendNetBufferListsComplete* function to complete a send request that a filter driver started by
calling the
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) function.

**Note** You must declare the function by using the **FILTER_SEND_NET_BUFFER_LISTS_COMPLETE** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferList`

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the filter
driver passed to
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists).

### `SendCompleteFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_COMPLETE_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_SEND_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *SendFlags* parameter of [SendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) when it sends the request.

**Note** This flag is available in NDIS 6.30 and later.

## Remarks

*FilterSendNetBufferListsComplete* is an optional function. If a filter driver does not filter send
requests, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

The filter driver can call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function,
from the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function,
to specify a
*FilterSendNetBufferListsComplete* function for a filter module.

**Note** A filter driver that does not provide a
*FilterSendNetBufferListsComplete* function cannot call the
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) function.

When NDIS calls
*FilterSendNetBufferListsComplete*, the filter driver regains ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated
data.

If an overlying driver initiated the send request, the filter driver should call the
[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function to complete the send request.

If the filter driver originated the send request,
*FilterSendNetBufferListsComplete* can either release the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated
data or prepare them for reuse in a subsequent call to
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists).

**Note** A filter driver should keep track of send requests that it initiates and make sure that it does not
call
[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) when NDIS calls
*FilterSendNetBufferListsComplete* for such requests.

NDIS calls
*FilterSendNetBufferListsComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterSendNetBufferListsComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterSendNetBufferListsComplete* function that is named "MySendNetBufferListsComplete", use the **FILTER_SEND_NET_BUFFER_LISTS_COMPLETE** type as shown in this code example:

```
FILTER_SEND_NET_BUFFER_LISTS_COMPLETE MySendNetBufferListsComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MySendNetBufferListsComplete(
    NDIS_HANDLE  FilterModuleContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  SendCompleteFlags
    )
  {...}
```

The **FILTER_SEND_NET_BUFFER_LISTS_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_SEND_NET_BUFFER_LISTS_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists)

[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)