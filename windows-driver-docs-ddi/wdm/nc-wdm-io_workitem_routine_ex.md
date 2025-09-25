## Description

A *WorkItemEx* routine performs the processing for a work item that was queued by the [IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex) or [IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85)) routine.

## Parameters

### `IoObject` [in]

Pointer to the caller's driver object or to one of the caller's device objects. This is the pointer that was passed as the *DeviceObject* parameter to [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem) when the work item was allocated, or as the *IoObject* parameter to [IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem) or [IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85)) when the work item was initialized.

### `Context` [in, optional]

Specifies driver-specific context information. This is the value that was passed as the *Context* parameter to [IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex) or [IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85)) when the work item was queued.

### `IoWorkItem` [in]

Pointer to the [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the work item. This is the pointer that was passed as the *IoWorkItem* parameter to [IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex) or [IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85)).

## Remarks

Drivers can implement *WorkItemEx* routines only on Windows Vista and later versions of Windows.

The driver queues a *WorkItemEx* routine by calling [IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex) or [IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85)), and a system worker thread subsequently executes the routine. For more information, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

A *WorkItemEx* routine must run for a limited amount of time; otherwise, the system can deadlock. For more information, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

A *WorkItemEx* routine runs at IRQL = PASSIVE_LEVEL and in a system thread context.

### Examples

To define a *WorkItemEx* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *WorkItemEx* callback routine that is named `MyWorkItemEx`, use the IO_WORKITEM_ROUTINE_EX type as shown in this code example:

```cpp
IO_WORKITEM_ROUTINE_EX MyWorkItemEx;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyWorkItemEx(
    PVOID  IoObject,
    PVOID  Context,
    PIO_WORKITEM  IoWorkItem
    )
  {
      // Function body
  }
```

The IO_WORKITEM_ROUTINE_EX function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_WORKITEM_ROUTINE_EX function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem)

[IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex)

[IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85))