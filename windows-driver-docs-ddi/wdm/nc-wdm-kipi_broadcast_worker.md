## Description

The *IpiGenericCall* routine runs simultaneously on all processors.

## Parameters

### `Argument` [in]

Supplies the value that was passed to the [KeIpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keipigenericcall) routine that called *IpiGenericCall*.

## Return value

*IpiGenericCall* returns a driver-defined value. If *IpiGenericCall* ran on the same processor that called **KeIpiGenericCall**, **KeIpiGenericCall** returns the driver-defined value that *IpiGenericCall* returns. Otherwise, the value is ignored.

## Remarks

*IpiGenericCall* routines run at IRQL = IPI_LEVEL, which is greater than DIRQL for every device. *IpiGenericCall* routines must satisfy the same restrictions as bug check callback routines. For more information about these restrictions, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

### Examples

To define an *IpiGenericCall* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *IpiGenericCall* callback routine that is named `MyIpiGenericCall`, use the KIPI_BROADCAST_WORKER type as shown in this code example:

```cpp
KIPI_BROADCAST_WORKER MyIpiGenericCall;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
ULONG_PTR
  MyIpiGenericCall(
    ULONG_PTR  Argument
    )
  {
      // Function body
  }
```

The KIPI_BROADCAST_WORKER function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the KIPI_BROADCAST_WORKER function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2015/code-quality/annotating-function-behavior).

## See also

[KeIpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keipigenericcall)