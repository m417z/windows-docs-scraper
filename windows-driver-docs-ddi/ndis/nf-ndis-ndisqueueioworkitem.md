# NdisQueueIoWorkItem function

## Description

NDIS drivers call the
**NdisQueueIoWorkItem** function to queue a work item.

## Parameters

### `NdisIoWorkItemHandle` [in]

A handle to a private [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was returned by a previous call to the
[NdisAllocateIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateioworkitem) function.

### `Routine` [in]

The entry point to the function that NDIS calls to process the work item. NDIS calls this routine
in the context of a system thread.

**Note** You must declare the function by using the **NDIS_IO_WORKITEM_FUNCTION** type (not **NDIS_IO_WORKITEM_ROUTINE**). For more
information, see the following Examples section.

The routine includes the following input parameters:

#### WorkItemContext

A pointer to the context area that the driver passed to the
*WorkItemContext* parameter of
**NdisQueueIoWorkItem**.

#### NdisIoWorkItemHandle

A handle to a private **NDIS_IO_WORKITEM** structure that was returned by a previous call to the
[NdisAllocateIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateioworkitem) function.

### `WorkItemContext` [in]

A pointer to a caller-supplied context area that NDIS passes through to the callback routine.
*WorkItemContext* can be any caller-specified data that the driver requires to manage the work
item.

## Remarks

**NdisQueueIoWorkItem** calls
[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem) to queue a work item. NDIS
work items use the
**CriticalWorkQueue** queue type.

The caller-supplied callback routine (NDIS_IO_WORKITEM_ROUTINE) runs in a system thread context at
IRQL = PASSIVE_LEVEL.

This caller-supplied routine can call the
[NdisFreeIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeioworkitem) function to reclaim
the storage allocated for the work item.

### Examples

To define a *Routine* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *Routine* function that is named "MyWorkitemRoutine", use the **NDIS_IO_WORKITEM_FUNCTION** type as shown in this code example:

```
NDIS_IO_WORKITEM_FUNCTION MyWorkitemRoutine;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyWorkitemRoutine(
    PVOID   WorkItemContext,
    NDIS_HANDLE  NdisIoWorkItemHandle
    )
  {...}
```

The **NDIS_IO_WORKITEM_FUNCTION** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_IO_WORKITEM_FUNCTION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NDIS I/O Work Items](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-i-o-work-items)

[NdisAllocateIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateioworkitem)

[NdisFreeIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeioworkitem)