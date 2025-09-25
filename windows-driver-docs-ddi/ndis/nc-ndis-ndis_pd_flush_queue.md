# NDIS_PD_FLUSH_QUEUE callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*PDFlushQueue* function to flush a specified queue, ensuring that any items that are not yet in a complete state in the queue will be completed imminently.

**Note** You must declare the function by using the **NDIS_PD_FLUSH_QUEUE** type. For more
information, see the following Examples section.

## Parameters

### `Queue` [in, out]

The queue to flush. For more information, see the [NDIS_PD_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue) structure.

## Return value

This callback function does not return a value.

## Remarks

The caller is responsible for waiting for and draining all previously posted requests before closing the queue. The caller must not post any further [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures to the queue after this call. The primary use case for this routine is flushing the receive queues--if there's no incoming traffic, posted buffers will sit in the receive queue indefinitely, and these need to be drained by being flushed before the queue can be closed. The same issue does not exist for transmit queues in practice because transmit requests will not pend indefinitely. However, providers must honor the flush call for transmit queues (this may be a no-operation if the provider knows that the pending transmit request will complete very soon, which is the typical case except for L2 flow control).

### Examples

To define a *PDFlushQueue* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *PDFlushQueue* function that is named "MyPDFlushQueue", use the **NDIS_PD_FLUSH_QUEUE** type as shown in this code example:

```
NDIS_PD_FLUSH_QUEUE MyPDFlushQueue;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDFlushQueue(
    NDIS_PD_QUEUE*  NdisPDQueue
    )
  {...}
```

The **NDIS_PD_FLUSH_QUEUE** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_FLUSH_QUEUE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).