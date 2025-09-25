## Description

The **KeRegisterBugCheckCallback** routine registers a [**BugCheckCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_callback_routine) routine, which executes when the operating system issues a bug check.

## Parameters

### `CallbackRecord` [out]

Pointer to a callback record that was previously initialized by [**KeInitializeCallbackRecord**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializecallbackrecord), for which the caller provides nonpaged storage.

### `CallbackRoutine` [in]

Pointer to the driver-supplied [**KBUGCHECK_CALLBACK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_callback_routine) callback function.

### `Buffer` [in, optional]

Pointer to a caller-supplied buffer, which must be in resident memory, such as nonpaged pool.

### `Length` [in]

Specifies the size in bytes of the caller-allocated buffer.

### `Component` [in]

Pointer to a null-terminated ANSI string that identifies the caller. This string usually contains the name of the device driver, or possibly of its device. The string must be allocated in non-paged memory because it might be accessed during bug check processing when the virtual memory system is not available.

## Return value

**KeRegisterBugCheckCallback** returns TRUE if the caller-supplied routine is successfully added to the set of registered bug-check callbacks; otherwise, it returns FALSE.

## Remarks

The **KeRegisterBugCheckCallback** routine registers a BugCheckCallback routine, the simplest kind of bug-check callback routine.

To register other kinds of bug-check callbacks, such as *KbCallbackDumpIo* and *KbCallbackAddPages* routines, use the [**KeRegisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback) routine instead.

The *BugCheckCallback* routine is executed when the system issues a bug check. A driver can use the routine to reset the device to a known state. For more information, see *BugCheckCallback*.

Drivers can use the **KeDeregisterBugCheckCallback** routine to remove the callback. Any driver that can be unloaded must remove all of its callbacks in its [**Unload**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine.

The **Component** string is used to identify the driver during crash-dump debugging. To display the crash dump data corresponding to any specified **Component** string, you can use the **!bugdump** debugger extension. It is also possible to debug the bug check callback routine itself. For information about debuggers and debugger extensions, see [**Windows Debugging**](https://learn.microsoft.com/windows-hardware/drivers/debugger/).

### Implementation

To define a *BugCheckCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps Code Analysis for Drivers, Static Driver Verifier (SDV), and other verification tools find errors.

For example, to define a *BugCheckCallback* callback routine that is named MyBugCheckCallback, use the KBUGCHECK_CALLBACK_ROUTINE type as shown in this code example:

```cpp
KBUGCHECK_CALLBACK_ROUTINE MyBugCheckCallback;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyBugCheckCallback(
    PVOID  Buffer,
    ULONG  Length
    )
  {
      // Function body
  }
```

The KBUGCHECK_CALLBACK_ROUTINE function type is defined in *wdm.h*.

To more accurately identify errors when you run the code analysis tools, be sure to add the `Use_decl_annotations_` annotation to your function definition. The `Use_decl_annotations_` annotation ensures that the annotations that are applied to the KBUGCHECK_CALLBACK_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**Writing a Bug Check Callback Routine**](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[**KeDeregisterBugCheckCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckcallback)

[**KeInitializeCallbackRecord**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializecallbackrecord)

[**KeRegisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)