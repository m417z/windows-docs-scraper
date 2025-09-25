# FILTER_SEND_NET_BUFFER_LISTS callback function

## Description

NDIS calls the
*FilterSendNetBufferLists* function to allow a filter driver to filter a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

**Note** You must declare the function by using the **FILTER_SEND_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferList`

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that specify
lists of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each **NET_BUFFER** in the
list maps a chain of MDLs that contain the transmit data.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. Miniport adapter port numbers are assigned
by calling the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR operation.
To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

Specifies that NDIS should check for loopback. By default, NDIS does not loop back data to the
driver that submitted the send request. An overlying driver can override this behavior by setting
this flag. When this flag is set, NDIS identifies all the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that contain data
that matches the receive criteria for the binding. NDIS indicates **NET_BUFFER** structures that match
the criteria to the overlying driver. This flag has no affect on checking for loopback, or looping
back, on other bindings.

#### NDIS_SEND_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_SEND_COMPLETE_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *SendCompleteFlags* parameter of [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) when it completes the send request.

**Note** This flag is available in NDIS 6.30 and later.

#### NDIS_SEND_FLAGS_SWITCH_DESTINATION_GROUP

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures are to be forwarded to the same extensible switch destination port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** This flag is available in NDIS 6.30 and later.

## Remarks

*FilterSendNetBufferLists* is an optional function. If a filter driver does not filter send requests,
it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

If a filter driver specifies a
*FilterSendNetBufferLists* function and it queues send requests, it must also specify a
[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists) function.

The filter driver can call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function,
from the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function, to
specify a
*FilterSendNetBufferLists* function for a filter module.

If the filter driver specifies a
*FilterSendNetBufferLists* function, NDIS calls this function to filter the data that is contained in
a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures over the network. NDIS
specifies a list of **NET_BUFFER** structures in each
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

If the filter driver did not specify
*FilterSendNetBufferLists*, NDIS calls the next filter driver that is lower in the driver stack that
did specify a
*FilterSendNetBufferLists* function. If there are no such underlying filter drivers, NDIS calls an
underlying driver's
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function.

The filter driver can filter the data and send the filtered data to underlying drivers. For each
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure submitted to
*FilterSendNetBufferLists*, a filter driver can do the following:

* Pass the buffer on to the next underlying driver by calling the
  [NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) function. The filter driver can modify the buffer contents before calling
  **NdisFSendNetBufferLists**. In this case NDIS calls the
  [FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function after the underlying drivers complete the send
  request.
* Reject the buffer by calling the
  [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function.
* Queue the buffer in a local data structure for later processing.
* Copy the buffer and originate a send request with the copy. The send operation is similar to a
  filter-driver initiated send request. In this case, the driver must return the original buffer to the
  overlying driver by calling the
  [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function.

After the send operation is complete, a filter driver reverses the modifications, if any, to the
buffer descriptors that it made in the
*FilterSendNetBufferLists* function. The driver calls the
[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function to return the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to
the overlying drivers and to return the final status of the send request.

If a filter module is in the
*Paused* state, the filter driver must not originate any send requests for that filter module. If
NDIS calls
*FilterSendNetBufferLists*, the driver must not call
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) to pass on the data until the driver is restarted. The driver should call
[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) immediately to complete the send operation. It should set the
complete status in each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to NDIS_STATUS_PAUSED.

NDIS calls
*FilterSendNetBufferLists* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterSendNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterSendNetBufferLists* function that is named "MySendNetBufferLists", use the **FILTER_SEND_NET_BUFFER_LISTS** type as shown in this code example:

```
FILTER_SEND_NET_BUFFER_LISTS MySendNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MySendNetBufferLists(
    NDIS_HANDLE  FilterModuleContext,
    PNET_BUFFER_LIST  NetBufferLists,
    NDIS_PORT_NUMBER  PortNumber,
    ULONG  SendFlags
    )
  {...}
```

The **FILTER_SEND_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_SEND_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists)

[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)