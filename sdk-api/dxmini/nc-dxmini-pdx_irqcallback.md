# PDX_IRQCALLBACK callback function

## Description

The **IRQCallback** function performs operations related to the IRQ that occurred.

## Parameters

### `pIrqData`

Points to the [DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata) structure that is filled in with the video miniport driver's IRQ information.

## Remarks

The [video miniport driver](https://learn.microsoft.com/windows-hardware/drivers/display/video-miniport-drivers-in-the-windows-2000-display-driver-model) calls the *IRQCallback* function when an IRQ occurs.

## See also

[DDENABLEIRQINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddenableirqinfo)

[DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata)

[DxEnableIRQ](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_enableirq)