## Description

**DRIVER_INITIALIZE** is the type definition of the driver initialization entry point, which is conventionally named **DriverEntry**. This is the first routine called after a driver is loaded.

## Parameters

### `DriverObject` [in]

A pointer to the driver's [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure.

### `RegistryPath` [in]

A pointer to a counted Unicode string specifying the path to the driver's registry key.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in Ntstatus.h.

## Remarks

The *DriverObject* parameter supplies the **DriverEntry** routine with a pointer to the driver's driver object, which is allocated by the I/O manager. The **DriverEntry** routine must fill in the driver object with entry points for the driver's standard routines.

The *DriverObject* pointer gives the driver access to *DriverObject-*>**HardwareDatabase**, which points to a counted Unicode string that specifies a path to the registry's **\Registry\Machine\Hardware** tree.

The registry path string pointed to by *RegistryPath* is of the form **\Registry\Machine\System\CurrentControlSet\Services\\*DriverName***. A driver can use this path to store driver-specific information; see [Registry Keys for Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-registry-trees-and-keys). The **DriverEntry** routine should save a copy of the Unicode string, not the pointer, since the I/O manager frees the *RegistryPath* buffer after **DriverEntry** returns.

For more information about implementing a **DriverEntry** routine, see [Writing a DriverEntry Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-driverentry-routine).

While it is possible to name this routine something other than **DriverEntry**, doing so is not recommended. The DDK-supplied build tools automatically inform the linker that the driver's entry point is called **DriverEntry**, so giving the routine another name requires you to modify the build tools. For more information about build tools, see [Building a Driver](https://learn.microsoft.com/windows-hardware/drivers/develop/building-a-driver).

### Examples

To define a **DriverEntry** callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors.

To define a **DriverEntry** callback routine, use the DRIVER_INITIALIZE type as shown in this code example:

```cpp
DRIVER_INITIALIZE DriverEntry;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  DriverEntry(
    struct _DRIVER_OBJECT  *DriverObject,
    PUNICODE_STRING  RegistryPath
    )
  {
      // Function body
  }
```

The DRIVER_INITIALIZE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_INITIALIZE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)