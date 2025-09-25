# _WDF_INTERRUPT_PRIORITY enumeration (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority) enumeration type identifies relative priorities for device interrupts.

## Constants

### `WdfIrqPriorityUndefined`

The relative priority of a device's interrupt is undefined.

### `WdfIrqPriorityLow`

The device's interrupt has a relatively low priority, typically because the interrupt does not have to be serviced immediately.

### `WdfIrqPriorityNormal`

The device's interrupt priority is neither relatively low nor relatively high.

### `WdfIrqPriorityHigh`

The device's interrupt has a relatively high priority, typically because the interrupt must be serviced immediately.

## Remarks

The [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority) enumeration type is used as input to the [IWDFInterrupt::SetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setpolicy) method.

## See also

[IWDFInterrupt::SetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setpolicy)