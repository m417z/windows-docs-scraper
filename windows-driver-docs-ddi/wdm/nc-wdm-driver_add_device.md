## Description

The *AddDevice* routine is responsible for creating functional device objects (FDO) or filter device objects (filter DO) for devices enumerated by the Plug and Play (PnP) manager.

## Parameters

### `DriverObject` [in]

Caller-supplied pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. This is the driver's driver object.

### `PhysicalDeviceObject` [in]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure representing a physical device object (PDO) created by a lower-level driver.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in Ntstatus.h.

## Remarks

All kernel-mode drivers that support PnP must provide an *AddDevice* routine.

A driver's *AddDevice* routine should be named *Xxx*AddDevice, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *AddDevice* routine's address in **DriverObject->DriverExtension->AddDevice**.

An *AddDevice* routine's primary responsibilities are calling [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) to create a device object, then calling [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack) to attach the device object to the device stack. For detailed information about implementing a driver's *AddDevice* routine, see [Writing an AddDevice Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-an-adddevice-routine).

An *AddDevice* routine runs in a system thread context at IRQL = PASSIVE_LEVEL.

### Examples

To define an *AddDevice* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *AddDevice* callback routine that is named `MyAddDevice<`, use the DRIVER_ADD_DEVICE type as shown in this code example:

```cpp
DRIVER_ADD_DEVICE MyAddDevice;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyAddDevice(
    struct _DRIVER_OBJECT  *DriverObject,
    struct _DEVICE_OBJECT  *PhysicalDeviceObject
    )
  {
      // Function body
  }
```

The DRIVER_ADD_DEVICE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_ADD_DEVICE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).