# KeBugCheckEx function

## Description

The **KeBugCheckEx** routine brings down the system in a controlled manner when the caller discovers an unrecoverable inconsistency that would corrupt the system if the caller continued to run.

## Parameters

### `BugCheckCode` [in]

Specifies a value that indicates the reason for the bug check.

### `BugCheckParameter1` [in]

### `BugCheckParameter2` [in]

### `BugCheckParameter3` [in]

### `BugCheckParameter4` [in]

The four *BugCheckParameterX* values supply additional information, such as the address and data where a memory-corruption error occurred, depending on the value of *BugCheckCode*.

## Remarks

A bug check is a system-detected error that causes an immediate, controlled shutdown of the system. Various kernel-mode components perform run-time consistency checking. When such a component discovers an unrecoverable inconsistency, it causes a bug check to be generated.

Whenever possible, all kernel-mode components should log an error and continue to run, rather than calling **KeBugCheckEx**. For example, if a driver is unable to allocate required resources, it should log an error so that the system continues to run; it must not generate a bug check.

A driver or other kernel-mode component should call this routine only in cases of a fatal, unrecoverable error that could corrupt the system itself.

**KeBugCheckEx** can be useful in the early stages of developing a driver, or while it is undergoing testing. In these circumstances, the *BugCheckCode* passed to this routine should be distinct from those codes already in use by Windows or its drivers. For a list of these codes, see [Bug Check Codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

However, even during driver development, this routine is of only limited utility, since it results in a complete system shutdown. A more effective debugging method is to attach a kernel debugger to the system and then use routines that send messages to the debugger or break into the debugger. For further information, see [Get started with WinDbg (kernel mode)](https://learn.microsoft.com/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-).

## See also

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)

[KeBugCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kebugcheck)

[KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback)

[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)