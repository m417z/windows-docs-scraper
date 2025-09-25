## Description

The *DxEnableIRQ* callback function indicates to the video miniport driver which IRQs should be enabled or disabled.

## Parameters

### `unnamedParam1`

Points to the miniport driver's device extension.

### `unnamedParam2`

Points to the [DDENABLEIRQINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddenableirqinfo) structure that contains the information required to enable interrupts.

### `unnamedParam3`

Reserved for system use.

## Return value

*DxEnableIRQ* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The **dwIRQSources** member of the DDENABLEIRQINFO structure at *EnableIrqInfo* contains the DDIRQ_*Xxx* flags that are set for every IRQ that should be enabled. If an IRQ is not specified in this call, it should be disabled. If the requested combination cannot be supported, this function fails.

Because the video miniport driver must always manage its own IRQ, it must call the specified [IRQCallback](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_irqcallback) when an IRQ occurs. When calling **IRQCallback**, the **dwIRQFlags** member of the [DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata) structure passed to **IRQCallback** contains the DDIRQ_*Xxx* flags that indicate what caused the IRQ.

## See also

[DDENABLEIRQINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddenableirqinfo)

[DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata)

[IRQCallback](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_irqcallback)