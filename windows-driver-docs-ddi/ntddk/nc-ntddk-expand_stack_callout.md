## Description

The *ExpandedStackCall* routine executes with a guaranteed stack size.

## Parameters

### `Parameter` [in, optional]

The value passed to the [KeExpandKernelStackAndCallout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keexpandkernelstackandcallout) routine that executed *ExpandedStackCall*.

## Return value

None

## Remarks

The *ExpandedStackCall* routine must handle all exceptions. Any unhandled exception causes the system to bug check with [Bug Check 0x1E: KMODE_EXCEPTION_NOT_HANDLED](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x1e--kmode-exception-not-handled).

If the *ExpandedStackCall* changes the current IRQL, it must restore the original value before returning.

### Examples

To define an *ExpandedStackCall* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *ExpandedStackCall* callback routine that is named `MyExpandedStackCall`, use the EXPAND_STACK_CALLOUT type as shown in this code example:

```cpp
EXPAND_STACK_CALLOUT MyExpandedStackCall;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyExpandedStackCall(
    PVOID  Parameter
    )
  {
      // Function body
  }
```

The EXPAND_STACK_CALLOUT function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the EXPAND_STACK_CALLOUT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[KeExpandKernelStackAndCallout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keexpandkernelstackandcallout)