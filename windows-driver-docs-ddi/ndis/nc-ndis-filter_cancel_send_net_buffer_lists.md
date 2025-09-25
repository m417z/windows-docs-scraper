# FILTER_CANCEL_SEND_NET_BUFFER_LISTS callback function

## Description

NDIS calls a filter driver's
*FilterCancelSendNetBufferLists* function to cancel the transmission of all
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are marked
with a specified cancellation identifier.

**Note** You must declare the function by using the **FILTER_CANCEL_SEND_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to a context area that the filter driver allocated in its
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function. The filter driver
uses this context area to maintain state information for a filter module.

### `CancelId` [in]

A cancellation identifier. This identifier specifies the NET_BUFFER_LIST structures that are being
canceled.

## Remarks

The
*FilterCancelSendNetBufferLists* function is optional. If a filter driver does not filter send
requests, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

Filter drivers that queue
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures before sending
should export a
*FilterCancelSendNetBufferLists* function. The
*FilterCancelSendNetBufferLists* function cancels the pending transmission of the specified
NET_BUFFER_LIST structures.

When an overlying NDIS driver calls the
[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) or
[NdisFCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists) function, NDIS calls the
*FilterCancelSendNetBufferLists* function of the filter modules on the binding.

A filter driver's
*FilterCancelSendNetBufferLists* function performs the following operations:

1. Traverses its list of queued NET_BUFFER_LIST structures for the specified filter module and calls
   the
   [NDIS_GET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id) macro to obtain the cancellation identifier for each queued
   NET_BUFFER_LIST structure. The filter driver compares the cancellation ID that
   NDIS_GET_NET_BUFFER_LIST_CANCEL_ID returns with the cancellation ID that NDIS passed to
   *FilterCancelSendNetBufferLists*.
2. Removes from the send queue (unlinks) all
   [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures whose
   cancellation identifiers match the specified cancellation identifier.
3. Calls the
   [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function for all unlinked NET_BUFFER_LIST structures to return
   the structures. The filter driver sets the status field of the NET_BUFFER_LIST structures to
   NDIS_STATUS_SEND_ABORTED.
4. Calls the
   **NdisFCancelSendNetBufferLists** function to pass the cancel send request to underlying drivers.

NDIS calls
*FilterCancelSendNetBufferLists* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterCancelSendNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterCancelSendNetBufferLists* function that is named "MyCancelSendNetBufferLists", use the **FILTER_CANCEL_SEND_NET_BUFFER_LISTS** type as shown in this code example:

```
FILTER_CANCEL_SEND_NET_BUFFER_LISTS MyCancelSendNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCancelSendNetBufferLists(
    NDIS_HANDLE  FilterModuleContext,
    PVOID  CancelId
    )
  {...}
```

The **FILTER_CANCEL_SEND_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_CANCEL_SEND_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_GET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[NdisFCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete)