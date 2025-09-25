# IWDFInterrupt::ReleaseInterruptLock

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **ReleaseInterruptLock** method ends a code sequence that executes while holding an interrupt object's lock.

## Remarks

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[IWDFInterrupt::AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-acquireinterruptlock)