# MINIPORT_SEND_NET_BUFFER_LISTS callback function

## Description

NDIS calls the
*MiniportSendNetBufferLists* function to transmit network data that is contained in a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

**Note** You must declare the function by using the **MINIPORT_SEND_NET_BUFFER_LISTS** type. For
more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information about an adapter.

### `NetBufferList` [in]

A pointer to the first
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in a linked list
of NET_BUFFER_LIST structures. Each NET_BUFFER_LIST structure in the list describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each NET_BUFFER structure
in the list maps to a chain of MDLs. The MDLs contain the network data.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. To assign a miniport adapter port number,
call the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

Specifies that NDIS should check for loopback. By default, NDIS does not loop back data to the
driver that submitted the send request. An overlying driver can override this behavior by setting this
flag. When this flag is set, NDIS identifies all the NET_BUFFER structures that contain data that
matches the receive criteria for the binding. NDIS indicates NET_BUFFER structures that match the
criteria to the overlying driver. This flag has no affect on checking for loopback, or looping back,
on other bindings.

## Remarks

*MiniportSendNetBufferLists* is a required function for miniport drivers. When an overlying driver
calls the
[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists) function,
NDIS calls the
*MiniportSendNetBufferLists* function of the bound miniport driver.

When transmitting the network data that NDIS passes in the *NetBufferLists* parameter, the miniport driver must use the following guidelines:

1. The order of the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures in each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure must be preserved.
2. The order of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures should be preserved if they are to be transmitted on the same connection.
3. If the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures are to be transmitted on different connections, they can be split into multiple transmit queues if the following features are in use. In this case, the order of the **NET_BUFFER_LIST** structures for each connection should be preserved.

   * Receive side scaling (RSS) (The RSS hash value in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure can be used as an index into the RSS indirection table.)
   * Virtual Machine Queue (VMQ) (The queue identifier of the outgoing queue is set in the **NetBufferListFilteringInfo** OOB information. For more information, see [VMQ Transmit Path](https://learn.microsoft.com/windows-hardware/drivers/network/vmq-transmit-path).)
   * IEEE 802.1 Data Center Bridging (DCB) (You can key off the Traffic Class (TC).)
   * IEEE 802.1p (You can key off 802.1p tags without DCB.)

Miniport drivers accept all send requests that NDIS makes by calling the
*MiniportSendNetBufferLists* function. If a miniport driver cannot complete a send request
immediately, the driver must hold the request in a queue until it can complete the request. While a send
request is pending, the miniport driver retains ownership of the NET_BUFFER_LIST structures and all the
protocol-allocated resources associated with the NET_BUFFER_LIST structures.

The miniport driver must call the
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function to complete the send requests for all NET_BUFFER_LIST
structures. To improve system performance, the driver can create a linked list that contains the
NET_BUFFER_LIST structures from multiple send requests. The driver can then pass such a linked list in a
single call to
**NdisMSendNetBufferListsComplete**.NET_BUFFER_LIST structures and other associated resources should
be treated as inaccessible by the miniport driver as soon as the driver calls
**NdisMSendNetBufferListsComplete**.

The
*MiniportSendNetBufferLists* function must synchronize access to its internal queues of network data
with the driver's other
*MiniportXxx* functions that access the same queues. A miniport driver can use spin locks to
synchronize access to the queues.

Protocol drivers are responsible for determining what network data is required, based on the medium
type that the bound miniport driver selected. However, a protocol driver can supply network data that
specifies packets that are shorter than the minimum packet size for the selected medium. In this case,
*MiniportSendNetBufferLists* must pad the packets with zeros if the selected medium imposes a
minimum-length requirement on the transmit packet size.

If the miniport driver set the NDIS_MAC_OPTION_NO_LOOPBACK flag when NDIS queried the
[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options) OID, the miniport
driver must not attempt to loop back any network data. NDIS provides software loopback support for such a
driver.

NDIS calls
*MiniportSendNetBufferLists* at IRQL<= DISPATCH_LEVEL.

### Examples

To define a *MiniportSendNetBufferLists* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportSendNetBufferLists* function that is named "MySendNetBufferLists", use the **MINIPORT_SEND_NET_BUFFER_LISTS** type as shown in this code example:

```
MINIPORT_SEND_NET_BUFFER_LISTS MySendNetBufferLists;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MySendNetBufferLists(
    NDIS_HANDLE  MiniportAdapterContext,
    PNET_BUFFER_LIST  NetBufferList,
    NDIS_PORT_NUMBER  PortNumber,
    ULONG  SendFlags
    )
  {...}
```

The **MINIPORT_SEND_NET_BUFFER_LISTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_SEND_NET_BUFFER_LISTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists)

[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options)