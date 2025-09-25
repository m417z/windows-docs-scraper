# MINIPORT_CO_SEND_NET_BUFFER_LISTS callback function

## Description

The
*MiniportCoSendNetBufferLists* function transmits network data that is contained in a specified linked
list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

**Note** You must declare the function by using the **MINIPORT_CO_SEND_NET_BUFFER_LISTS** type. For more
information, see the following Examples section.

## Parameters

### `MiniportVcContext` [in]

A handle to a miniport driver-allocated context area in which the miniport driver maintains its
per-virtual connection (VC) state. The miniport driver supplied this handle to NDIS from its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function.

### `NetBufferLists` [in]

A pointer to the first
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in a linked list
of **NET_BUFFER_LIST** structures. Each **NET_BUFFER_LIST** structure in the list describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each **NET_BUFFER** structure
in the list maps to a chain of memory descriptor lists (MDLs). The MDLs contain the network data that
*MiniportCoSendNetBufferLists* transmits.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with a bitwise OR
operation. To clear all of the flags, set this parameter to zero.
*MiniportCoSendNetBufferLists* supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

The caller can optionally set this flag if the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

NDIS should check for loopback. By default, NDIS does not loop back data to the driver that
submitted the send request. An overlying driver can override this behavior by setting the
**NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK** flag. When this flag is set, NDIS identifies all of the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
structures that contain data that matches the receive criteria for the binding. NDIS indicates
**NET_BUFFER** structures that match the criteria to the overlying driver. This flag does not affect
checking for loopback, or looping back, on other bindings.

## Remarks

The
*MiniportCoSendNetBufferLists* function is required for CoNDIS miniport drivers. When an overlying
driver calls the
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists) function, NDIS calls the
*MiniportCoSendNetBufferLists* function of the bound miniport driver.

The order of the linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that NDIS passes
at
*NetBufferLists* represents the order in which the miniport driver should transmit the network data.
In addition, a miniport driver should send the **NET_BUFFER_LIST** structures from multiple
*MiniportCoSendNetBufferLists* calls in the order that the miniport driver received the structures
in.

CoNDIS miniport drivers must accept all of the send requests that NDIS makes by calling the
*MiniportCoSendNetBufferLists* function. If a miniport driver cannot complete a send request
immediately, the driver must hold the request in a queue until it can complete the request. While a send
request is pending, the miniport driver retains ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and all of
the resources that are associated with the **NET_BUFFER_LIST** structures.

The miniport driver must call the
[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete) function to complete all CoNDIS send requests. To improve
computer performance, the driver can create a linked list that contains the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures from multiple
send requests. The driver can then pass such a linked list in a single call to
**NdisMCoSendNetBufferListsComplete**.

In addition, you should assume that the miniport driver cannot access the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures
and other associated resources as soon as the driver calls
[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete).

The
*MiniportCoSendNetBufferLists* function must synchronize access to its internal queues of network
data with the driver's other
*MiniportXxx* functions that access the same queues. A miniport driver can use spin locks to
synchronize access to the queues.

Protocol drivers are responsible for determining what network data is required, based on the medium
type that the bound miniport driver selected. However, a protocol driver can supply network data that
specifies packets that are shorter than the minimum packet size for the selected medium. In this case,
*MiniportCoSendNetBufferLists* must pad the packets with zeros if the selected medium imposes a
minimum-length requirement on the transmit packet size.

NDIS calls
*MiniportCoSendNetBufferLists* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *MiniportCoSendNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoSendNetBufferLists* function that is named "MyCoSendNetBufferLists", use the **MINIPORT_CO_SEND_NET_BUFFER_LISTS** type as shown in this code example:

```
MINIPORT_CO_SEND_NET_BUFFER_LISTS MyCoSendNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoSendNetBufferLists(
    NDIS_HANDLE  MiniportVcContext,
    PNET_BUFFER_LIST  NetBufferLists,
    ULONG  SendFlags
    )
  {...}
```

The **MINIPORT_CO_SEND_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_SEND_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete)