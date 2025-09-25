# IWDFInterrupt::GetInfo

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **GetInfo** method retrieves information about a specified interrupt.

## Parameters

### `InterruptInfo`

A pointer to a caller-allocated [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure that the driver has previously initialized by calling [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init).

## Remarks

The **GetInfo** method can obtain interrupt information only if your driver calls it after the framework has called the driver's [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) callback function and before the framework has called the driver's [OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onreleasehardware) callback function.

For information about the order in which a driver's callback functions are called, see [PnP and Power Management Scenarios in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios-in-umdf).

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

### Examples

``` cpp
IWDFInterrupt* pInterrupt;
WDF_INTERRUPT_INFO  Info;

WDF_INTERRUPT_INFO_INIT(&Info);
pInterrupt->GetInfo(&Info);
```

## See also

- [IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)
- [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware)
- [OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onreleasehardware)
- [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info)
- [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init)