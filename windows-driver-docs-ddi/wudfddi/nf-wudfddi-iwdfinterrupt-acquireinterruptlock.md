# IWDFInterrupt::AcquireInterruptLock

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AcquireInterruptLock** method begins a code sequence that executes while holding an interrupt object's lock.

## Remarks

When a driver calls **AcquireInterruptLock**, the system acquires the framework's interrupt lock.

When the driver calls [ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-releaseinterruptlock), the system releases the interrupt lock.

You can use **AcquireInterruptLock** and [ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-releaseinterruptlock) if your driver must execute a few lines of code without being preempted and with interrupt servicing disabled.

Your driver cannot call **AcquireInterruptLock** before the framework has called the driver's [OnInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_enable) callback function or after the framework has called the driver's [OnInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_disable) callback function.

After your driver calls **AcquireInterruptLock**, it must not call the method again for the same interrupt object before calling [ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-releaseinterruptlock).

When running in an arbitrary thread, such as an I/O queue callback method, drivers must call [IWDFInterrupt::TryToAcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-trytoacquireinterruptlock) instead of **IWDFInterrupt::AcquireInterruptLock**. For example, the driver calls **IWDFInterrupt::TryToAcquireInterruptLock** from [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread).

Doing so avoids the possibility of deadlock, as described in the following scenario.

1. In order to determine if its device interrupted, a UMDF sends I/O to its bus from within its ISR, with the interrupt lock held.
2. The bus driver completes a second request in the same thread in which it received the above request.
3. The completion routine of the second request sends a request to the UMDF driver.
4. The UMDF driver's I/O dispatch routine calls **IWDFInterrupt::AcquireInterruptLock**, which then deadlocks attempting to acquire the interrupt lock.

The driver must not attempt to acquire the lock recursively. If connected to the debugger, the framework introduces a breakpoint in this scenario.

For more information about manual interrupt locking, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[IWDFInterrupt::ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-releaseinterruptlock)

[WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85))