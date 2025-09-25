## Description

This routine starts a DMA data-transfer or a data transfer operation.

## Parameters

### `DeviceObject` [in]

Caller-supplied pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's *AddDevice* routine.

### `Irp` [in, out]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure. *Irp* is equal to the value of the **CurrentIrp** member of *DeviceObject* when the callback routine was registered.

### `MapRegisterBase` [in]

In the case of *AdapterControl*, this is a caller-supplied opaque value that represents the map registers that the system has assigned for this transfer operation. The driver passes this value to [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers), [FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers), and [MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer).

In the case of *ControllerControl*, this is not used.

### `Context` [in]

Caller-supplied pointer to driver-defined context information, specified in a previous call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

## Return value

The routine must return one of the values defined by the [IO_ALLOCATION_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_allocation_action) enumeration. Drivers of bus-master devices return either **DeallocateObject** or **DeallocateObjectKeepRegisters**; drivers that use system DMA return **KeepObject**.

## Remarks

To register an *AdapterControl* routine for a specific device object, a driver must call [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) to obtain an adapter object, then call [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel) to request use of the adapter and to supply the *AdapterControl* routine's address. When the adapter is free, the system calls the *AdapterControl* routine.

If *AdapterControl* has been registered by a [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine, then the *Irp* parameter is guaranteed to point to the IRP currently being processed by the *StartIo* routine. Otherwise, drivers must set the **CurrentIrp** member of the device object structure before calling **AllocateAdapterChannel**.

For detailed information about implementing an *AdapterControl* routine, see [Writing AdapterControl Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-adaptercontrol-routines).

A driver's *ControllerControl* routine executes in an arbitrary thread context at IRQL = DISPATCH_LEVEL.

To register a *ControllerControl* routine for a specific device object, a driver must call [IoCreateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatecontroller) to obtain a controller object, then call [IoAllocateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioallocatecontroller) to request use of the controller and to supply the *ControllerControl* routine's address. When the controller is free, the system calls the *ControllerControl* routine.

For detailed information about implementing a *ControllerControl* routine, see [Writing ControllerControl Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines). Also see [Controller Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-controller-objects).

The DRIVER_CONTROL function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_CONTROL function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

### Examples

To define a callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *AdapterControl* callback routine that is named `MyAdapterControl`, use the DRIVER_CONTROL type as shown in this code example:

```cpp
DRIVER_CONTROL MyAdapterControl;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
IO_ALLOCATION_ACTION
 MyAdapterControl(
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp,
    PVOID  MapRegisterBase,
    PVOID  Context
    )
  {
      // Function body
  }
```

## See also

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)