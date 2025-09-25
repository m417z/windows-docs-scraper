# PROTOCOL_RECEIVE_NET_BUFFER_LISTS callback function

## Description

The
*ProtocolReceiveNetBufferLists* function processes receive indications from underlying drivers.

**Note** You must declare the function by using the **PROTOCOL_RECEIVE_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area that the protocol driver allocated to maintain state information for a
binding. This handle was passed to NDIS in a previous call to the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `NetBufferLists` [in]

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
underlying driver allocated. Each **NET_BUFFER_LIST** structure is usually associated with one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. The default port number of a miniport
adapter is zero. Protocol drivers that do not use miniport adapter ports should ignore this
parameter.

### `NumberOfNetBufferLists` [in]

The number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are in the linked list of structures at
*NetBufferLists* .

### `ReceiveFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

Specifies that NDIS reclaims ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and any attached
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures immediately after the call to
*ProtocolReceiveNetBufferLists* returns.

#### NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* have the same protocol type (EtherType).

#### NDIS_RECEIVE_FLAGS_SINGLE_VLAN

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VLAN.

#### NDIS_RECEIVE_FLAGS_PERFECT_FILTERED

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* include only data that matches the packet filter and multicast list that are
assigned to the miniport adapter.

#### NDIS_RECEIVE_FLAGS_SINGLE_QUEUE

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VM queue. A miniport driver must set this flag for all receive
indications on a queue if the **NDIS_RECEIVE_QUEUE_PARAMETERS_PER_QUEUE_RECEIVE_INDICATION** flag was set
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

## Remarks

*ProtocolReceiveNetBufferLists* is a required function for protocol drivers. NDIS calls
*ProtocolReceiveNetBufferLists* after a bound miniport driver calls the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function. A call to
*ProtocolReceiveNetBufferLists* can also occur as a result of a loopback.

If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag in the
*ReceiveFlags* parameter is not set, the protocol driver retains ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures until it calls
the
[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists) function.

If NDIS sets the **NDIS_RECEIVE_FLAGS_RESOURCES** flag the protocol driver cannot retain the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and associated resources. The set **NDIS_RECEIVE_FLAGS_RESOURCES** flag indicates
that an underlying driver is running low on receive resources. In this case, the
*ProtocolReceiveNetBufferLists* function should copy the received data into protocol-allocated
storage and return as quickly as possible.

**Note** If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag is set, the protocol driver must retain
the original set of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the linked list. For example, when this flag is set the
driver might process the structures and indicate them up the stack one at a time but before the function
returns it must restore the original linked list.

On a multiprocessor system, this function can execute concurrently on more than one processor. Apply
protection (for example, use spin locks) to critical data structures that are accessed by
*ProtocolReceiveNetBufferLists*.

NDIS calls
*ProtocolReceiveNetBufferLists* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *ProtocolReceiveNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolReceiveNetBufferLists* function that is named "MyReceiveNetBufferLists", use the **PROTOCOL_RECEIVE_NET_BUFFER_LISTS** type as shown in this code example:

```
PROTOCOL_RECEIVE_NET_BUFFER_LISTS MyReceiveNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyReceiveNetBufferLists(
    NDIS_HANDLE  ProtocolBindingContext,
    PNET_BUFFER_LIST  NetBufferLists,
    NDIS_PORT_NUMBER  PortNumber,
    ULONG  NumberOfNetBufferLists,
    ULONG ReceiveFlags
    )
  {...}
```

The **PROTOCOL_RECEIVE_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_RECEIVE_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists)