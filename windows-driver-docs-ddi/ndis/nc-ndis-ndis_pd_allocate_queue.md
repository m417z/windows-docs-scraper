# NDIS_PD_ALLOCATE_QUEUE callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDAllocateQueue* function to allocate a queue.

**Note** You must declare the function by using the **NDIS_PD_ALLOCATE_QUEUE** type. For more
information, see the following Examples section.

## Parameters

### `ProviderHandle` [in]

A provider handle that identifies the PD-capable miniport driver's provider object.

### `QueueParameters` [in]

All the parameters that are associated with the Queue. For more information see the [NDIS_PD_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue_parameters) structure.

### `NdisPDQueue`

A pointer to the Queue that is to be allocated. For more information, see the [NDIS_PD_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue) structure.

## Return value

This function returns STATUS_SUCCESS when it completes successful, otherwise it returns the appropriate error code.

## Remarks

### Examples

To define a *NdisPDAllocateQueue* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisPDAllocateQueue* function that is named "MyPDAllocateQueue", use the **NDIS_PD_ALLOCATE_QUEUE** type as shown in this code example:

```
NDIS_PD_ALLOCATE_QUEUE MyPDAllocateQueue;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NTSTATUS
 MyPDAllocateQueue(
    NDIS_PD_PROVIDER_HANDLE  ProviderHandle,
    CONST NDIS_PD_QUEUE_PARAMETERS*  QueueParameters,
    NDIS_PD_QUEUE**  NdisPDQueue
    )
  {...}
```

The **NDIS_PD_ALLOCATE_QUEUE** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_ALLOCATE_QUEUE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).