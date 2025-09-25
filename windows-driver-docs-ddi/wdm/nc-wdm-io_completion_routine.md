## Description

The *IoCompletion* routine completes the processing of I/O operations.

## Parameters

### `DeviceObject` [in]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the I/O operation.

### `Context` [in, optional]

Caller-supplied pointer to driver-specific context information, previously supplied when calling [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) or [IoSetCompletionRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex). Context information must be stored in nonpaged memory, since an *IoCompletion* routine can be called at DISPATCH_LEVEL. For more information, see the following Remarks section.

## Return value

If the *IoCompletion* routine determines that additional processing is required for the IRP, it must return STATUS_MORE_PROCESSING_REQUIRED. For more information, see the following Remarks section. Otherwise, it should return STATUS_SUCCESS. (The I/O manager only checks for the presence or absence of STATUS_MORE_PROCESSING_REQUIRED.)

## Remarks

A driver's *IoCompletion* routine executes in an arbitrary thread or DPC context, and at an IRQL that is less than or equal to DISPATCH_LEVEL. Because code written to execute at DISPATCH_LEVEL will also execute at lower levels, *IoCompletion* routines should be designed for execution at DISPATCH_LEVEL. However, because these routines are not guaranteed to run at DISPATCH_LEVEL, they must not call system routines that actually require execution at DISPATCH_LEVEL. (For more information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).)

To register an *IoCompletion* routine for a specific IRP, a driver must call [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) or [IoSetCompletionRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex), which stores the *IoCompletion* routine's address in the next-lower driver's I/O stack location. (Thus, a lowest-level driver cannot register an *IoCompletion* routine.) A driver typically calls **IoSetCompletionRoutine** or **IoSetCompletionRoutineEx** from one of its dispatch routines, each time an IRP is received. Most drivers, including all PnP drivers, can use **IoSetCompletionRoutine** to register their *IoCompletion* routine. Non-PnP drivers that may be unloaded before their *IoCompletion* routine executes should use **IoSetCompletionRoutineEx** instead.

When any driver completes an IRP, it calls [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest), which in turn calls the *IoCompletion* routine of each higher-level driver, from the next-highest to the highest, until all higher *IoCompletion* routines have been called or until one routine returns STATUS_MORE_PROCESSING_REQUIRED.

When you create the IRP, allocate a stack location for the current driver as well as any lower drivers. If you do not allocate sufficient stack locations, the *DeviceObject* pointer might be set to **NULL** when the completion routine is called. You can avoid allocating extra stack location for the current driver if you use the *Context* field to pass information to *IoCompletion* rather than relying on the *DeviceObject* parameter.

If an *IoCompletion* routine returns STATUS_MORE_PROCESSING_REQUIRED, the lower driver's call to **IoCompleteRequest** immediately returns. In this case, a higher-level driver will have to call **IoCompleteRequest** to complete the IRP.

For more information about implementing *IoCompletion* routines, see [Completing IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/completing-irps).

### Examples

To define an *IoCompletion* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *IoCompletion* callback routine that is named `MyIoCompletion`, use the IO_COMPLETION_ROUTINE type as shown in this code example:

```cpp
IO_COMPLETION_ROUTINE MyIoCompletion;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyIoCompletion(
    PDEVICE_OBJECT  DeviceObject,
    PIRP  Irp,
    PVOID  Context
    )
  {
      // Function body
  }
```

The IO_COMPLETION_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_COMPLETION_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).