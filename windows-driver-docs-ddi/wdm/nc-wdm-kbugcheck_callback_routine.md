## Description

The *BugCheckCallback* routine is executed whenever the system issues a bug check.

The [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback function offers more functionality than this older callback.

## Parameters

### `Buffer` [in]

A pointer to the buffer that was specified when the callback was registered.

### `Length` [in]

Specifies the length, in bytes, of the buffer that is pointed to by the *Buffer* parameter.

## Remarks

Drivers can supply a *BugCheckCallback* that resets the device to a known state if the system issues a bug check.

Use [KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback) to register a *BugCheckCallback* routine. A driver can subsequently remove the callback by using the [KeDeregisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckcallback) routine. If the driver can be unloaded, it must remove any registered callbacks in its [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine.

A *BugCheckCallback* routine is strongly restricted in the actions it can take. For more information, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine). The routine can safely use the **READ_PORT_*XXX***, **READ_REGISTER_*XXX***, **WRITE_PORT_*XXX***, and **WRITE_REGISTER_*XXX*** routines to interact with the device.

Drivers that require more sophisticated interaction with the system as it issues a bug check can instead implement KbCallbackDumpIo or KbCallbackSecondaryDumpData routines.

Note that beginning with the Windows XP SP1 and Windows Server 2003 operating systems, *BugCheckCallback* routines execute after the system crash dump file has already been written. (On earlier versions of Windows, the routines execute before the crash dump file is written.) Thus, any data that is stored in the buffer specified by the *Buffer* parameter will not appear in the crash dump file. Drivers that are required to write data to the crash dump file instead implement a KbCallbackSecondaryDumpData routine. (On earlier versions of Windows, the data written to *Buffer* does appear in the crash dump file.)

### Examples

To define a *BugCheckCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *BugCheckCallback* callback routine that is named `MyBugCheckCallback`, use the KBUGCHECK_CALLBACK_ROUTINE type as shown in this code example:

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

The KBUGCHECK_CALLBACK_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the *Use_decl_annotations* annotation to your function definition. The *Use_decl_annotations* annotation ensures that the annotations that are applied to the KBUGCHECK_CALLBACK_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about *Use_decl_annotations*, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[KeDeregisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckcallback)

[KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback)