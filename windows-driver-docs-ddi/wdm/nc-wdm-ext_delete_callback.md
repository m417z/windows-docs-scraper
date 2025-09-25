## Description

An *ExTimerDeleteCallback* callback routine runs when the operating system deletes an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) timer object.

## Parameters

### `Context` [in, optional]

The context value from the *DeleteContext* member of the [**EXT_DELETE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters) structure that your driver previously passed as an input parameter to the [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routine.

## Remarks

As an option, your driver can supply a pointer to an *ExTimerDeleteCallback* routine in the *DeleteCallback* member of the [EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters) structure that your driver passes as an input parameter to the [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routine. The *ExTimerDeleteCallback* routine can free any storage or other system resources that the driver might have previously allocated to use with the timer object that is being deleted.

If the driver supplies an *ExTimerDeleteCallback* routine, and the *Wait* parameter in the **ExDeleteRoutine** call is **TRUE**, the *ExTimerDeleteCallback* routine runs before **ExDeleteTimer** returns. Otherwise, the *ExTimerDeleteCallback* routine might run before or after the **ExDeleteTimer** call returns. The *ExTimerDeleteCallback* routine is called only after the timer object has been disabled to prevent further timer operations and any pending timer operation on the timer object is canceled or completed. The timer object (an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) structure) that the driver passes as an input parameter to the **ExDeleteTimer** routine might no longer be valid by the time the *ExTimerDeleteCallback* routine runs.

For more information, see [ExXxxTimer Routines and EX_TIMER Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects).

### Examples

To define an *ExTimerDeleteCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function type helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *ExTimerDeleteCallback* callback routine that is named `MyExTimerDeleteCallback`, use the EXT_DELETE_CALLBACK function type, as shown in this code example:

```cpp
EXT_DELETE_CALLBACK  MyExTimerDeleteCallback;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyExTimerDeleteCallback(
    PVOID  Context
    )
  {...}
```

The EXT_DELETE_CALLBACK function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the EXT_DELETE_CALLBACK function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For more information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**EXT_DELETE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters)

[EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects)

[ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer)