# KeRegisterBugCheckReasonCallback function

## Description

The **KeRegisterBugCheckReasonCallback** function registers a callback routine that executes when the operating system issues a bug check.

## Parameters

### `CallbackRecord` [out]

A pointer to a [**KBUGCHECK_REASON_CALLBACK_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_reason_callback_record) structure that was initialized by a call to the KeInitializeCallbackRecord routine described in the [Windows kernel macros](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer).

### `CallbackRoutine` [in]

A pointer to a callback routine of type [**KBUGCHECK_REASON_CALLBACK_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) to register. For information about how to implement this callback routine, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

### `Reason` [in]

An enumeration of type [**KBUGCHECK_CALLBACK_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason) that specifies the type of callback routine that *CallbackRoutine* points to.

### `Component` [in]

A pointer to a null-terminated ANSI string that identifies the caller. For example, you can select a string that describes the device driver, or that contains the device name. You can use the [!bugdump](https://learn.microsoft.com/windows-hardware/drivers/debugger/-bugdump) debugger extension to display the crash dump data that is associated with this string.

## Return value

**KeRegisterBugCheckReasonCallback** returns **TRUE** if the callback routine is successfully registered; otherwise, it returns **FALSE**.

## Remarks

Drivers can use **KeRegisterBugCheckReasonCallback** to register routines that execute during a system bug check.

For descriptions of each type of callback, see [**KBUGCHECK_CALLBACK_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason).

Drivers can use the [**KeDeregisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckreasoncallback) routine to remove the bug check callback registration. Any driver that can be unloaded must remove the registrations of all of its callbacks in its [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine.

For information about how to implement these callback routines, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

To display secondary dump data, you can use the [IDebugDataSpaces3::ReadTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces3-readtagged)** method in a debugger extension. Another option is to debug the bug check callback routine itself. For more information about debuggers and debugger extensions, see [Windows Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[**KBUGCHECK_CALLBACK_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason)

[**KBUGCHECK_REASON_CALLBACK_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeDeregisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckreasoncallback)

[**KeInitializeCallbackRecord**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)

[**KeRegisterBugCheckCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback)