# WUDF_INTERRUPT_CONFIG_INIT function

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WUDF_INTERRUPT_CONFIG_INIT** function initializes a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure.

## Parameters

### `Configuration` [out]

A pointer to a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure.

### `OnInterruptIsr` [in]

A pointer to the driver's [OnInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_isr) event callback function.

### `OnInterruptWorkItem` [in, optional]

A pointer to the driver's [OnInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_workitem) event callback function, or NULL.

## Remarks

The **WUDF_INTERRUPT_CONFIG_INIT** function zeros the specified [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure and sets its **Size** member to the structure's size. It also stores the specified callback function pointer(s).

**WUDF_INTERRUPT_CONFIG_INIT** initializes the configuration structure's **ShareVector** member to **WdfUseDefault** and the **AutomaticSerialization** member to FALSE.

#### Examples

For a code example that uses **WUDF_INTERRUPT_CONFIG_INIT**, see [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).