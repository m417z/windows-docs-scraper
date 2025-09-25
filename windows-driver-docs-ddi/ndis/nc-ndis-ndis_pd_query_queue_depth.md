# NDIS_PD_QUERY_QUEUE_DEPTH callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*PDQueryQueueDepth* function to return the number of unprocessed [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures that are posted to the **Queue**.

**Note** You must declare the function by using the **NDIS_PD_QUERY_QUEUE_DEPTH** type. For more
information, see the following Examples section.

## Parameters

### `Queue` [in]

A pointer to a transmit or receive queue.

### `Depth` [out]

On a receive queue, this is the number of [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures that are available for placing incoming packets into. For example, if 10 buffers were posted, and 3 of the 10 have already been fetched by the provider for placing incoming packets into, this value should be 7. On a transmit queue, this is the number of **PD_BUFFER** structures that the provider has not yet fetched from the queue for transmitting.

## Return value

This callback function does not return a value.

## Remarks

**Note** For IHV partners: The ability to monitor the queue depth is very important for clients to access congestion build-up and take precautionary action. An increasing queue depth for a transmit queue is a sign of increasing congestion on the outbound link. A decreasing queue depth for an RX queue is a sign of the client not being able to process incoming packets fast enough on the inbound link. Clients may need to monitor the queue depth status with frequently (For example, getting the queue depth for each post and operation, therefore the cost (in CPU cycles) of querying the queue depth must not be noticeable in comparison to the cost of a single [PDPostAndDrainBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_post_and_drain_buffer_list) call.

### Examples

To define a *PDQueryQueueDepth* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *PDQueryQueueDepth* function that is named "MyPDQueryQueueDepth", use the **NDIS_PD_QUERY_QUEUE_DEPTH** type as shown in this code example:

```
NDIS_PD_QUERY_QUEUE_DEPTH MyPDQueryQueueDepth;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDQueryQueueDepth(
    CONST NDIS_PD_QUEUE*  Queue,
    ULONG64*  Depth
    )
  {...}
```

The **NDIS_PD_QUERY_QUEUE_DEPTH** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_QUERY_QUEUE_DEPTH** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).