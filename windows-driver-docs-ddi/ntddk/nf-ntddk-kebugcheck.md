# KeBugCheck function

## Description

The **KeBugCheck** routine brings down the system in a controlled manner when the caller discovers an unrecoverable inconsistency that would corrupt the system if the caller continued to run.

## Parameters

### `BugCheckCode` [in]

Specifies a value that indicates the reason for the bug check.

## Remarks

A bug check is a system-detected error that causes an immediate, controlled shutdown of the system. Various kernel-mode components perform run-time consistency checking. When such a component discovers an unrecoverable inconsistency, it causes a bug check to be generated.

Whenever possible, all kernel-mode components should log an error and continue to run, rather than calling **KeBugCheck**. For example, if a driver is unable to allocate required resources, it should log an error so that the system continues to run; it must not generate a bug check.

A driver or other kernel-mode component should call this routine only in cases of a fatal, unrecoverable error that could corrupt the system itself.

**KeBugCheck** can be useful in the early stages of developing a driver, or while it is undergoing testing. In these circumstances, the *BugCheckCode* passed to this routine should be distinct from those codes already in use by Windows or its drivers. For a list of these codes, see [Bug Check Codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

However, even during driver development, this routine is of only limited utility, since it results in a complete system shutdown. A more effective debugging method is to attach a kernel debugger to the system and then use routines that send messages to the debugger or break into the debugger. For further information, see [Get started with WinDbg (kernel-mode)](https://learn.microsoft.com/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-).

When a bug check is unavoidable, most system components call [KeBugCheckEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kebugcheckex), which provides more information about the cause of such an inconsistency than **KeBugCheck**.

## See also

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)

[KeBugCheckEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kebugcheckex)

[KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback)

[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)