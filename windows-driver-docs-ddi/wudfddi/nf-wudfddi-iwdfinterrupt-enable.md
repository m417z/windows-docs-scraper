# IWDFInterrupt::Enable

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Enable** method enables a specified device interrupt by calling the driver's [OnInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_enable) callback function.

## Remarks

Most UMDF drivers do not need to call **IWDFInterrupt::Enable**, because the framework calls the driver's [OnInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_enable) callback function each time the device enters its working (D0) state.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

#### Examples

The following code example enables the device interrupt that is associated with a specified interrupt object.

```
pIWdfInterrupt->Enable();
```

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[IWDFInterrupt::Disable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-disable)