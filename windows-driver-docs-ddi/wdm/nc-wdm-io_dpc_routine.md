## Description

The *DpcForIsr* routine finishes the servicing of an I/O operation, after an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine returns.

## Parameters

### `Dpc` [in]

Caller-supplied pointer to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which represents the DPC object that is associated with this *DpcForIsr* routine.

### `DeviceObject` [in]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in, out]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the I/O operation.

### `Context` [in, optional]

Caller-supplied pointer to driver-defined context information, specified in a previous call to [IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc).

## Remarks

To register a *DpcForIsr* routine for a specific device object, a driver must call [IoInitializeDpcRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializedpcrequest), which causes the system to allocate and initialize one DPC object. (If you need multiple DPC routines, use [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routines.)

To queue a *DpcForIsr* routine for execution, a driver's [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine must call [IoRequestDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc).

A *DpcForIsr* routine is typically responsible for at least the following tasks:

- Completing the I/O operation described by the received IRP.

- Dequeuing next IRP.

 If the driver uses the system-supplied IRP queue, the *DpcForIsr* routine should call [IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket) or [IoStartNextPacketByKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacketbykey), so the driver's [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine will start processing the next I/O request.

 If the driver uses internal IRP queues, the *DpcForIsr* routine should dequeue the next IRP and begin processing for the next I/O request.

- Setting the I/O status block in the received IRP and calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) for the completed request.

A *DpcForIsr* routine might also retry a failed operation or set up the next transfer for a large I/O request that has been broken into smaller pieces.

For more information about *DpcForIsr* routines, see [DPC Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpc-objects-and-dpcs).

### Examples

To define a *DpcForIsr* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *DpcForIsr* callback routine that is named `MyDpcForIsr`, use the IO_DPC_ROUTINE type as shown in this code example:

```cpp
IO_DPC_ROUTINE MyDpcForIsr;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyDpcForIsr(
    PKDPC  Dpc,
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp,
    PVOID  Context
    )
  {
      // Function body
  }
```

The IO_DPC_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_DPC_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).