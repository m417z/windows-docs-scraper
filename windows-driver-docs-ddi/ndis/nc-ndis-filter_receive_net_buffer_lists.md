# FILTER_RECEIVE_NET_BUFFER_LISTS callback function

## Description

NDIS calls the
*FilterReceiveNetBufferLists* function to request a filter driver to process a receive
indication.

**Note** You must declare the function by using the **FILTER_RECEIVE_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferLists` [in]

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that were
allocated by underlying drivers. Each **NET_BUFFER_LIST** structure contains one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. Miniport adapter port numbers are assigned
by calling the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter.

### `NumberOfNetBufferLists` [in]

The number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are in the linked list of structures at
*NetBufferLists* .

### `ReceiveFlags` [in]

Flags that define attributes for the receive indication. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

Specifies that NDIS reclaims ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and any attached
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures immediately after the call to
*FilterReceiveNetBufferLists* returns.

#### NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* have the same protocol type (EtherType).

#### NDIS_RECEIVE_FLAGS_SINGLE_VLAN

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VLAN.

#### NDIS_RECEIVE_FLAGS_PERFECT_FILTERED

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* include only data that matches the packet filter and multicast address list that are
assigned to the miniport adapter.

#### NDIS_RECEIVE_FLAGS_SINGLE_QUEUE

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VM queue. A miniport driver must set this flag for all receive
indications on a queue if the NDIS_RECEIVE_QUEUE_PARAMETERS_PER_QUEUE_RECEIVE_INDICATION flag was set
in the
**Flags** member of the
[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters) structure when that queue was allocated.

#### NDIS_RECEIVE_FLAGS_SHARED_MEMORY_INFO_VALID

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* contain shared memory information that is valid. When this flag is set on a
received **NET_BUFFER_LIST**, NDIS treats the shared memory information as valid. When this flag is not
set, NDIS and drivers ignore the shared memory information. For example, intermediate drivers that
modify packet data can use this flag to determine if data should be copied. Miniport drivers can use
the flag to determine how to free the memory that is associated with a VM queue when a queue is
deleted.

#### NDIS_RECEIVE_FLAGS_MORE_NBLS

Reserved.

#### NDIS_RECEIVE_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_RETURN_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *ReturnFlags* parameter of [FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) when the receive request completes. The extension must set this flag in the *ReturnFlags* parameter if it calls [NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) to return packets that it did not originate or clone.

#### NDIS_RECEIVE_FLAGS_SWITCH_DESTINATION_GROUP

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures are to be forwarded to the same extensible switch destination port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same destination ports, the extension should set the **NDIS_RECEIVE_FLAGS_SWITCH_DESTINATION_GROUP** flag in the *ReturnFlags* parameter of [FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) when the receive request completes. The extension must set this flag in the *ReturnFlags* parameter if it calls [NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) to return packets that it did not originate or clone.

## Remarks

*FilterReceiveNetBufferLists* is an optional function. If a filter driver does not filter receive
indications, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

**Note** A filter driver that does provide a
*FilterReceiveNetBufferLists* function must provide a
[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status) function.

The filter driver can call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function,
from the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function,
to specify a
*FilterReceiveNetBufferLists* function for a filter module.

NDIS calls
*FilterReceiveNetBufferLists* to process receive indications that are initiated by underlying
drivers. NDIS can also call this function as a result of loopback.

If the filter driver did not specify a
*FilterReceiveNetBufferLists* function, NDIS calls the next higher filter driver in the stack that did specify a
*FilterReceiveNetBufferLists* function. If there is no such filter driver, NDIS calls an overlying
driver's
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function.

If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag in the
*ReceiveFlags* parameter is not set, the filter driver retains ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
structures until it calls the
[NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) function.

If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag in the
*ReceiveFlags* parameter is set, the filter driver cannot keep the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and
associated underlying-driver-allocated resources. This flag can indicate that the underlying driver is
running low on receive resources. The
*FilterReceiveNetBufferLists* function should return as quickly as possible. Before returning, the
*FilterReceiveNetBufferLists* function can copy the received data into filter-driver-allocated
storage or pass the buffer on by calling the
[NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists) function.

**Note** If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag is set, the filter driver must retain the
original set of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the linked list. For example, when this flag is set the
driver might process the structures and indicate them up the stack one at a time but before the function
returns it must restore the original linked list.

Filter drivers can filter received data before indicating the data to overlying drivers. For each
buffer that is submitted to its
*FilterReceiveNetBufferLists* function, a filter driver can do the following:

* Pass the buffer on to the next overlying driver by calling the
  [NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists) function.

  The driver can modify the contents of the buffer before calling
  **NdisFIndicateReceiveNetBufferLists**.

  The driver can change the **NDIS_RECEIVE_FLAGS_RESOURCES** flag setting that NDIS passed to
  *FilterReceiveNetBufferLists* or simply pass it on to
  **NdisFIndicateReceiveNetBufferLists**.
* Discard the buffer. If NDIS cleared the **NDIS_RECEIVE_FLAGS_RESOURCES** flag, call the
  **NdisFReturnNetBufferLists** function to discard the buffer. If NDIS set the
  **NDIS_RECEIVE_FLAGS_RESOURCES** flag, take no action and return from
  *FilterReceiveNetBufferLists* to discard the buffer.
* Queue the buffer in a local data structure for later processing. If NDIS set the
  **NDIS_RECEIVE_FLAGS_RESOURCES** flag of
  *FilterReceiveNetBufferLists*, the filter driver must create a copy before returning from
  *FilterReceiveNetBufferLists*.
* Copy the buffer and originate a receive indication with the copy. The receive indication is similar
  to a filter-driver-initiated receive indication. In this case, the driver must return the original
  buffer to the underlying driver.

If the filter driver called
**NdisFIndicateReceiveNetBufferLists** and did not set the **NDIS_RECEIVE_FLAGS_RESOURCES** flag, NDIS
calls the
[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function for the filter module. In its
*FilterReturnNetBufferLists* function, the filter driver will undo the operations that it performed
on the buffer on the receive indication path.

If a filter module is in the
*Paused* state, the filter driver must not originate any receive indications for that filter module.
The filter driver must not pass buffers that it created to
**NdisFIndicateReceiveNetBufferLists**. However, the driver can pass on a receive indication from an
underlying driver.

NDIS calls
*FilterReceiveNetBufferLists* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterReceiveNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterReceiveNetBufferLists* function that is named "MyReceiveNetBufferLists", use the **FILTER_RECEIVE_NET_BUFFER_LISTS** type as shown in this code example:

```
FILTER_RECEIVE_NET_BUFFER_LISTS MyReceiveNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyReceiveNetBufferLists(
    NDIS_HANDLE  FilterModuleContext,
    PNET_BUFFER_LIST  NetBufferLists,
    NDIS_PORT_NUMBER  PortNumber,
    ULONG  NumberOfNetBufferLists,
    ULONG  ReceiveFlags
    )
  {...}
```

The **FILTER_RECEIVE_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_RECEIVE_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists)