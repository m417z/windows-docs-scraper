# PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE callback function

## Description

The
*ProtocolSendNetBufferListsComplete* function completes a send operation that the protocol driver
initiated with a call to the
[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists) function.

**Note** You must declare the function by using the **PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area that the protocol driver allocated to maintain state information about
a binding. This handle was passed to NDIS in a previous call to
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex).

### `SendCompleteFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to
zero. This function supports the NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL flag which; if set, indicates
that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

### `NetBufferList` [in]

A pointer to a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
protocol driver supplied in a previous call to
[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists).

## Remarks

*ProtocolSendNetBufferListsComplete* is a required function for protocol drivers.
*ProtocolSendNetBufferListsComplete* performs whatever postprocessing is necessary to complete a send
operation. For example, the protocol driver can notify the clients that requested the protocol to send
the network data that the send operation is complete.

NDIS calls
*ProtocolSendNetBufferListsComplete* after the underlying miniport driver calls the
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function. Completion of a send operation usually implies that the
underlying miniport driver has transmitted the specified network data. However, a miniport driver can
indicate that a send operation has completed as soon as it transfers the network data to its NIC.

When NDIS calls
*ProtocolSendNetBufferListsComplete*, the protocol driver regains ownership of all of the resources
associated with the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are
specified by the
*NetBufferLists* parameter.

NDIS always submits protocol-supplied network data to the underlying miniport driver in the
protocol-determined order as passed to
**NdisSendNetBufferLists**. However, the underlying driver can complete the send requests in any
order. That is, protocol drivers can rely on NDIS to submit network data in FIFO order to the underlying
driver. However, protocol drivers cannot rely on the underlying driver to call
**NdisMSendNetBufferListsComplete** in the same order.

NDIS calls
*ProtocolSendNetBufferListsComplete* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *ProtocolSendNetBufferListsComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolSendNetBufferListsComplete* function that is named "MySendNetBufferListsComplete", use the **PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE** type as shown in this code example:

```
PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE MySendNetBufferListsComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MySendNetBufferListsComplete(
    NDIS_HANDLE  ProtocolBindingContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  SendCompleteFlags
    )
  {...}
```

The **PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_SEND_NET_BUFFER_LISTS_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists)