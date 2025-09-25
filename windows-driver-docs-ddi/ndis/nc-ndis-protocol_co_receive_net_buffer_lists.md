# PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS callback function

## Description

The
*ProtocolCoReceiveNetBufferLists* function processes receive indications from underlying
drivers.

**Note** You must declare the function by using the **PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area that the protocol driver allocated to maintain state information for a
binding. This handle was passed to NDIS in a previous call to
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex).

### `ProtocolVcContext` [in]

A handle to a protocol driver-allocated context area in which this driver maintains the
per-virtual connection (VC) run-time state information. A client or stand-alone call manager supplied
this handle either when it called the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function or from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `NetBufferLists` [in]

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
underlying driver allocated. Each **NET_BUFFER_LIST** structure is usually associated with one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

### `NumberOfNetBufferLists` [in]

The number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are in the linked list of structures that
*NetBufferLists* specifies.

### `ReceiveFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with a bitwise OR
operation. To clear all of the flags, set this parameter to zero.
*ProtocolCoReceiveNetBufferLists* supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

The current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

NDIS reclaims ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and any attached NET_BUFFER structures
immediately after the call to
*ProtocolCoReceiveNetBufferLists* returns.

## Remarks

The
*ProtocolCoReceiveNetBufferLists* function is required for CoNDIS protocol drivers. NDIS calls
*ProtocolCoReceiveNetBufferLists* after a bound miniport driver calls the
[NdisMCoIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcoindicatereceivenetbufferlists) function. A call to
*ProtocolCoReceiveNetBufferLists* can also occur as a result of a loopback.

If the **NDIS_RECEIVE_FLAGS_RESOURCES** flag in the
*CoReceiveFlags* parameter is not set, the protocol driver retains ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures until it calls
the
[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists) function. If NDIS sets the **NDIS_RECEIVE_FLAGS_RESOURCES** flag, the protocol
driver cannot retain the **NET_BUFFER_LIST** structure and associated resources. **NDIS_RECEIVE_FLAGS_RESOURCES**
indicates that an underlying driver has low receive resources. In this case, the
*ProtocolCoReceiveNetBufferLists* function should copy the received data into protocol-allocated
storage and return as quickly as possible.

On a multiprocessor system,
*ProtocolCoReceiveNetBufferLists* can run concurrently on more than one processor. In this situation,
apply protection (for example, use spin locks) to critical data structures that
*ProtocolCoReceiveNetBufferLists* accesses.

NDIS calls
*ProtocolCoReceiveNetBufferLists* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *ProtocolCoReceiveNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoReceiveNetBufferLists* function that is named "MyCoReceiveNetBufferLists", use the **PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS** type as shown in this code example:

```
PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS MyCoReceiveNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoReceiveNetBufferLists(
    NDIS_HANDLE  ProtocolBindingContext,
    NDIS_HANDLE  ProtocolVcContext,
    INPNET_BUFFER_LIST  NetBufferLists,
    ULONG  NumberOfNetBufferLists,
    ULONG  ReceiveFlags
    )
  {...}
```

The **PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_RECEIVE_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CoNDIS Protocol Driver Send and Receive Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisMCoIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcoindicatereceivenetbufferlists)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete)