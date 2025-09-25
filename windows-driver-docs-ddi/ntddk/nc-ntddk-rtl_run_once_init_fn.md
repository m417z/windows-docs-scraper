## Description

The *RunOnceInitialization* routine performs a one-time initialization operation.

## Parameters

### `RunOnce` [in, out]

A pointer to the [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) one-time initialization structure that the driver previously passed as a parameter to the [RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce) routine that called this *RunOnceInitialization* routine.

### `Parameter` [in, out]

The *Parameter* value that the driver passed to the **RtlRunOnceExecuteOnce** routine that called this *RunOnceInitialization* routine.

### `Context` [out]

A pointer to a PVOID variable to which the routine writes the initialization data.

## Return value

The *RunOnceInitialization* routine returns a nonzero value to indicate success, and returns zero to indicate failure.

## Syntax

```cpp
ULONG /* LOGICAL */
NTAPI
RTL_RUN_ONCE_INIT_FN (
    _Inout_ PRTL_RUN_ONCE RunOnce,
    _Inout_opt_ PVOID Parameter,
    _Inout_opt_ PVOID *Context
  );

typedef RTL_RUN_ONCE_INIT_FN *PRTL_RUN_ONCE_INIT_FN;
```

## Remarks

A driver-implemented *RunOnceInitialization* routine performs driver-specific initialization and then writes the initialization data to the memory location that the *Context* parameter points to. Drivers use the **RtlRunOnceExecuteOnce** routine to make a one-time call to a *RunOnceInitialization* routine. The operating system guarantees that the *RunOnceInitialization* routine is not called twice for the same value of the *RunOnce* parameter.

A small number of low-order bits in the location pointed to by the *Context* parameter are reserved for use by the operating system. Your driver's *RunOnceInitialization* routine should set these reserved bits to zero in the output value that it writes to **Context*. The RTL_RUN_ONCE_CTX_RESERVED_BITS constant defined in Ntddk.h specifies the number of low-order bits that are reserved. Currently, RTL_RUN_ONCE_CTX_RESERVED_BITS is defined to be two, which means that the driver must set the two least significant bits of the PVOID value pointed to by *Context* to zero.

### Examples

To define a *RunOnceInitialization* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *RunOnceInitialization* callback routine that is named `MyRunOnceInitialization`, use the RTL_RUN_ONCE_INIT_FN type as shown in this code example:

```cpp
RTL_RUN_ONCE_INIT_FN MyRunOnceInitialization;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
ULONG
  MyRunOnceInitialization(
    PRTL_RUN_ONCE  RunOnce,
    PVOID  Parameter,
    PVOID  *Context
    )
  {
      // Function body
  }
```

The RTL_RUN_ONCE_INIT_FN function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the RTL_RUN_ONCE_INIT_FN function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2015/code-quality/annotating-function-behavior).

## See also

[RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize)

[RtlRunOnceComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncecomplete)

[RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce)

[RtlRunOnceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceinitialize)