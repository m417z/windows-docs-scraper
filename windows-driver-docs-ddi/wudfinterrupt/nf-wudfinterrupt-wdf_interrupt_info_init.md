# WDF_INTERRUPT_INFO_INIT function (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init) function initializes a [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure.

## Parameters

### `InterruptInfo`

A pointer to a driver-allocated [**WDF_INTERRUPT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure.

## Remarks

The [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init) function zeros the specified [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure and sets the structure's **Size** member.

For more information about handling interrupts in framework-based drivers, see [Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

For a code example that uses [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init), see [IWDFInterrupt::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo).

## See also

[IWDFInterrupt::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo)

[WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info)