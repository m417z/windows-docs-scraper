# IWDFInterrupt::TryToAcquireInterruptLock

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **TryToAcquireInterruptLock** method acquires the interrupt lock if no other thread has already acquired it.

## Return value

The method returns TRUE if the interrupt lock was successfully acquired. Otherwise, the method returns FALSE.

## Remarks

Unlike [IWDFInterrupt::AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-acquireinterruptlock), **IWDFInterrupt::TryToAcquireInterruptLock** does not wait for the interrupt lock to become available if another thread is holding it.

When running in an arbitrary thread, such as an I/O queue callback method, drivers must call **IWDFInterrupt::TryToAcquireInterruptLock** instead of [IWDFInterrupt::AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-acquireinterruptlock). For example, the driver calls **IWDFInterrupt::TryToAcquireInterruptLock** from [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread). Doing so avoids the possibility of deadlock, as described in the Remarks section of [IWDFInterrupt::AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-acquireinterruptlock).

The driver must not attempt to acquire the lock recursively. If connected to the debugger, the framework introduces a breakpoint in this scenario.

For more information about manual interrupt locking, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[IWDFInterrupt::AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-acquireinterruptlock)

[WdfInterruptTryToAcquireLock](https://learn.microsoft.com/previous-versions/hh439284(v=vs.85))