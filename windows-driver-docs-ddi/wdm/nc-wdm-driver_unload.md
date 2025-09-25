## Description

The *Unload* routine performs any operations that are necessary before the system unloads the driver.

## Parameters

### `DriverObject` [in]

Caller-supplied pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. This is the driver's driver object.

## Remarks

A driver's *Unload* routine executes in a system thread context at IRQL = PASSIVE_LEVEL.

The *Unload* routine is required for WDM drivers and optional for non-WDM drivers. A driver's *Unload* routine, if supplied, should be named *Xxx***Unload**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *Unload* routine's address in **DriverObject->DriverUnload**. (If no routine is supplied, this pointer must be **NULL**.)

For detailed information about implementing a driver's *Unload* routine, see [Writing an Unload Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-an-unload-routine).

### Examples

To define an *Unload* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *Unload* callback routine that is named `MyUnload`, use the DRIVER_UNLOAD type as shown in this code example:

```cpp
DRIVER_UNLOAD MyUnload;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyUnload(
    struct _DRIVER_OBJECT  *DriverObject
    )
  {
      // Function body
  }
```

The DRIVER_UNLOAD function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_UNLOAD function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).