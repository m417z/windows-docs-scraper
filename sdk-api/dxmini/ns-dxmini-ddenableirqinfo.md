# DDENABLEIRQINFO structure

## Description

The DDENABLEIRQINFO structure contains the information required to enable interrupts.

## Members

### `dwIRQSources`

Indicates the interrupts that should be enabled. This member can be one or more of the following values:

| Flag | Meaning |
| --- | --- |
| DDIRQ_DISPLAY_VSYNC | The device can generate IRQs based on the display V-sync. |
| DDIRQ_VPORT0_LINE | The device can generate IRQs based on a programmable line for hardware video port number 0. |
| DDIRQ_VPORT0_VSYNC | The device can generate V-sync IRQs for hardware video port number 0. |
| DDIRQ_VPORT1_LINE | The device can generate IRQs based on a programmable line for hardware video port number 1. |
| DDIRQ_VPORT1_VSYNC | The device can generate V-sync IRQs for hardware video port number 1. |
| DDIRQ_VPORT2_LINE | The device can generate IRQs based on a programmable line for hardware video port number 2. |
| DDIRQ_VPORT2_VSYNC | The device can generate V-sync IRQs for hardware video port number 2. |
| DDIRQ_VPORT3_LINE | The device can generate IRQs based on a programmable line for hardware video port number 3. |
| DDIRQ_VPORT3_VSYNC | The device can generate V-sync IRQs for hardware video port number 3. |
| DDIRQ_VPORT4_LINE | The device can generate IRQs based on a programmable line for hardware video port number 4. |
| DDIRQ_VPORT4_VSYNC | The device can generate V-sync IRQs for hardware video port number 4. |
| DDIRQ_VPORT5_LINE | The device can generate IRQs based on a programmable line for hardware video port number 5. |
| DDIRQ_VPORT5_VSYNC | The device can generate V-sync IRQs for hardware video port number 5. |
| DDIRQ_VPORT6_LINE | The device can generate IRQs based on a programmable line for hardware video port number 6. |
| DDIRQ_VPORT6_VSYNC | The device can generate V-sync IRQs for hardware video port number 6. |
| DDIRQ_VPORT7_LINE | The device can generate IRQs based on a programmable line for hardware video port number 7. |
| DDIRQ_VPORT7_VSYNC | The device can generate V-sync IRQs for hardware video port number 7. |
| DDIRQ_VPORT8_LINE | The device can generate IRQs based on a programmable line for hardware video port number 8. |
| DDIRQ_VPORT8_VSYNC | The device can generate V-sync IRQs for hardware video port number 8. |
| DDIRQ_VPORT9_LINE | The device can generate IRQs based on a programmable line for hardware video port number 9. |
| DDIRQ_VPORT9_VSYNC | The device can generate V-sync IRQs for hardware video port number 9. |

### `dwLine`

Indicates which line should generate the IRQ. If the hardware does not have the ability to generate an IRQ based on a programmable line, the value in this member is meaningless.

### `IRQCallback`

Points to an [IRQCallback](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_irqcallback) that the video miniport driver calls when the miniport driver is managing IRQs, and an IRQ occurs.

### `lpIRQData`

Points to the data to be sent to **IRQCallback** when **IRQCallback** is called.

## Remarks

The **dwIRQSources** member of this structure does not use the DDIRQ_BUSMASTER flag. However, the DDIRQ_BUSMASTER flag can be set in the **dwIrqFlags** member of the [DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata) structure. The driver passes this DX_IRQDATA to the **IRQCallback** function when an IRQ occurs.

## See also

[DX_IRQDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-dx_irqdata)

[DxEnableIRQ](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_enableirq)

[IRQCallback](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_irqcallback)