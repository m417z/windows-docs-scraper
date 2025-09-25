# NDIS_PD_FREE_QUEUE callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDFreeQueue* function to free a queue.

**Note** You must declare the function by using the **NDIS_PD_FREE_QUEUE** type. For more
information, see the following Examples section.

## Parameters

### `NdisPDQueue` [in]

Any empty queue that needs to be freed from memory. For more information, see the [NDIS_PD_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue) structure.

## Return value

This callback function does not return a value.

## Remarks

The caller is responsible for ensuring that the PD queue is empty before issuing this call. Caller is also responsible for clearing all filters that target this queue before closing the queue.

### Examples

To define a *NdisPDFreeQueue* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisPDFreeQueue* function that is named "MyPDFreeQueue", use the **NDIS_PD_FREE_QUEUE** type as shown in this code example:

```
NDIS_PD_FREE_QUEUE MyPDFreeQueue;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDFreeQueue(
    NDIS_PD_QUEUE*  NdisPDQueue
    )
  {...}
```

The **NDIS_PD_FREE_QUEUE** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_FREE_QUEUE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).