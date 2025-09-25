# MINIPORT_CANCEL_SEND callback function

## Description

NDIS calls a miniport driver's
*MiniportCancelSend* function to cancel the transmission of all
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are marked
with a specified cancellation identifier.

**Note** You must declare the function by using the **MINIPORT_CANCEL_SEND** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information about an adapter.

### `CancelId` [in]

A cancellation identifier. This identifier specifies the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are being
canceled.

## Remarks

Miniport drivers and intermediate drivers that queue send
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures export a
*MiniportCancelSend* function. The
*MiniportCancelSend* function cancels the pending transmission of the specified NET_BUFFER_LIST
structures.

When an overlying NDIS driver calls the
[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) function, NDIS calls the
*MiniportCancelSend* function of the appropriate lower-level driver on the binding. NDIS makes this
call only if the lower-level driver exports a
*MiniportCancelSend* function.

A miniport driver's
*MiniportCancelSend* function performs the following operations:

1. Traverses its list of queued NET_BUFFER_LIST structures for the specified adapter and calls the
   [NDIS_GET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id) macro to obtain the cancellation identifier for each queued
   NET_BUFFER_LIST structure. The miniport driver compares the cancellation identifier that
   NDIS_GET_NET_BUFFER_LIST_CANCEL_ID returns with the cancellation identifier that NDIS passed to
   *MiniportCancelSend*.
2. Removes from the send queue (un-links) all NET_BUFFER_LIST structures whose cancellation identifiers
   match the specified cancellation identifier.
3. Calls the
   [NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function for all unlinked NET_BUFFER_LIST structures to return
   the structures .The miniport driver sets the status field of the NET_BUFFER_LIST structures to
   NDIS_STATUS_SEND_ABORTED.

An intermediate driver's
*MiniportCancelSend* function performs the following operations:

1. Performs the operations in the preceding list for a miniport driver's
   *MiniportCancelSend* function.
2. Calls the
   [NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) function, specifying the binding that maps to the adapter that NDIS
   specified in the call to
   *MiniportCancelSend*.

NDIS calls
*MiniportCancelSend* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *MiniportCancelSend* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCancelSend* function that is named "MyCancelSend", use the **MINIPORT_CANCEL_SEND** type as shown in this code example:

```
MINIPORT_CANCEL_SEND MyCancelSend;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCancelSend(
    NDIS_HANDLE  MiniportAdapterContext,
    PVOID  CancelId
    )
  {...}
```

The **MINIPORT_CANCEL_SEND** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CANCEL_SEND** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_GET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)