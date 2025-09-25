# MINIPORT_RETURN_NET_BUFFER_LISTS callback function

## Description

NDIS calls the
*MiniportReturnNetBufferLists* function to return ownership of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures, associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures, and any attached MDLs to a
miniport driver.

**Note** You must declare the function by using the **MINIPORT_RETURN_NET_BUFFER_LISTS** type.
For more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information about an adapter.

### `NetBufferLists` [in]

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that NDIS is
returning to the miniport driver. The linked list can contain NET_BUFFER_LIST structures from multiple
previous calls to the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function.

### `ReturnFlags` [in]

NDIS flags that can be combined with an OR operation. This function supports the NDIS_RETURN_FLAGS_DISPATCH_LEVEL flag which, if set, indicates that the
current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

## Remarks

*MiniportReturnNetBufferLists* is a required function for miniport drivers that indicate received
network data with the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function. When an overlying driver calls the
[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists) function, NDIS calls the
*MiniportReturnNetBufferLists* function of the miniport driver that indicated the specified
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

*MiniportReturnNetBufferLists* can prepare a returned NET_BUFFER_LIST structure for use in a
subsequent receive indication. Although
*MiniportReturnNetBufferLists* can return the NET_BUFFER_LIST structures to a pool (for example, it
could call the
[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) function), it
can be more efficient to reuse the structures without returning them to the pool.

NDIS calls
*MiniportReturnNetBufferLists* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *MiniportReturnNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportReturnNetBufferLists* function that is named "MyReturnNetBufferLists", use the **MINIPORT_RETURN_NET_BUFFER_LISTS** type as shown in this code example:

```
MINIPORT_RETURN_NET_BUFFER_LISTS MyReturnNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyReturnNetBufferLists(
    NDIS_HANDLE  MiniportAdapterContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  ReturnFlags
    )
  {...}
```

The **MINIPORT_RETURN_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_RETURN_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NdisReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreturnnetbufferlists)