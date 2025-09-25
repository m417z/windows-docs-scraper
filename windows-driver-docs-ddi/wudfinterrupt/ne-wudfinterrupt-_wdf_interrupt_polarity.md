# _WDF_INTERRUPT_POLARITY enumeration (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_polarity) enumeration type is used to specify an interrupt signal's polarity.

## Constants

### `WdfInterruptPolarityUnknown`

The interrupt signal's polarity is unknown.

### `WdfInterruptActiveHigh`

The interrupt signal is active when it is high.

### `WdfInterruptActiveLow`

The interrupt signal is active when it is low.

## Remarks

The [WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_polarity) enumeration type is used to specify a member of the [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure.