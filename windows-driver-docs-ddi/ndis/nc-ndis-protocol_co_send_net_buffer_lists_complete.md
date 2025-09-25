# PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE callback function

## Description

The
*ProtocolCoSendNetBufferListsComplete* function completes a send operation that the protocol driver
initiated with a call to the
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists) function.

**Note** You must declare the function by using the **PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolVcContext` [in]

A handle to a protocol driver-allocated context area in which this driver maintains the
per-virtual connection (VC) run-time state information. A client or stand-alone call manager supplied
this handle either when it called the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function or from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `NetBufferLists` [in]

A pointer to a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
protocol driver supplied in a previous call to the
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists) function.

### `SendCompleteFlags` [in]

NDIS flags that can be combined with a bitwise OR operation. To clear all of the flags, set this
parameter to zero.
*ProtocolCoSendNetBufferListsComplete* supports the NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL flag,
which; if set, indicates that the current IRQL is DISPATCH_LEVEL. For more information about this flag,
see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

## Remarks

The
*ProtocolCoSendNetBufferListsComplete* function is required for CoNDIS protocol drivers.
*ProtocolCoSendNetBufferListsComplete* performs whatever postprocessing is necessary to complete a
send operation. For example, the protocol driver can notify the clients that requested the driver to send
the network data that the send operation is complete.

NDIS calls
*ProtocolCoSendNetBufferListsComplete* after the underlying miniport driver calls the
[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function. A complete send operation does not necessarily imply
that an underlying miniport driver has transmitted the specified network data. For example, a miniport
driver can indicate that a send operation has completed as soon as it transfers the network data to the
network interface card (NIC) hardware.

When NDIS calls
*ProtocolCoSendNetBufferListsComplete*, the protocol driver regains ownership of all of the
resources that are associated with the NET_BUFFER_LIST structures that the
*NetBufferLists* parameter specifies.

NDIS always submits protocol driver-supplied network data to the underlying drivers in the
protocol-determined order that was passed to
**NdisCoSendNetBufferLists**. However, the underlying driver can complete the send requests in any
order. That is, protocol drivers can rely on NDIS to submit network data in "first in, first out" (FIFO)
order to the underlying driver. However, protocol drivers cannot rely on the underlying driver to call
**NdisMCoSendNetBufferListsComplete** in the same order.

NDIS calls
*ProtocolCoSendNetBufferListsComplete* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *ProtocolCoSendNetBufferListsComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoSendNetBufferListsComplete* function that is named "MyCoSendNetBufferListsComplete", use the **PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE** type as shown in this code example:

```
PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE MyCoSendNetBufferListsComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoSendNetBufferListsComplete(
    NDIS_HANDLE  ProtocolVcContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  SendCompleteFlags
    )
  {...}
```

The **PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_SEND_NET_BUFFER_LISTS_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CoNDIS Protocol Driver Send and Receive Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)