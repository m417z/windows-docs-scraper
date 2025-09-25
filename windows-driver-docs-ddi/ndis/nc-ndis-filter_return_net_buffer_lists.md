# FILTER_RETURN_NET_BUFFER_LISTS callback function

## Description

NDIS calls the
*FilterReturnNetBufferLists* function to return a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated data
to a filter driver.

**Note** You must declare the function by using the **FILTER_RETURN_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferLists` [in]

A linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the filter driver indicated by calling the
[NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists) function. The list can include **NET_BUFFER_LIST** structures from
multiple calls to
**NdisFIndicateReceiveNetBufferLists**.

### `ReturnFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to
zero.This function supports the following flags:

#### NDIS_RETURN_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RETURN_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_RECEIVE_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *ReceiveFlags* parameter of [FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) when it sends the request.

## Remarks

*FilterReturnNetBufferLists* is an optional function. If a filter driver does not filter receive indications, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

The filter driver can call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function,
from the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function, to
specify a
*FilterReturnNetBufferLists* function for a filter module.

**Note** A filter driver that does not provide a
*FilterReturnNetBufferLists* function cannot call the
[NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists) function to initiate a receive indication.

**Note** A filter driver that does provide a
*FilterReturnNetBufferLists* function must provide a
[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status) function.

When NDIS calls
*FilterReturnNetBufferLists*, the filter driver regains ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated
data.

If an underlying driver initiated the receive indication, the filter driver should call the
[NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) function to complete the receive indication.

If the filter driver originated the receive indication,
*FilterReturnNetBufferLists* can either release the NET_BUFFER_LIST structures and associated data or
prepare them for reuse in a subsequent call to
**NdisFIndicateReceiveNetBufferLists**.

A filter driver should keep track of receive indications that it initiates and make sure that it does
not call
**NdisFReturnNetBufferLists** when NDIS calls
*FilterReturnNetBufferLists*.

NDIS calls
*FilterReturnNetBufferLists* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterReturnNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterReturnNetBufferLists* function that is named "MyReturnNetBufferLists", use the **FILTER_RETURN_NET_BUFFER_LISTS** type as shown in this code example:

```
FILTER_RETURN_NET_BUFFER_LISTS MyReturnNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyReturnNetBufferLists(
    NDIS_HANDLE  FilterModuleContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  ReturnFlags
    )
  {...}
```

The **FILTER_RETURN_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_RETURN_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)