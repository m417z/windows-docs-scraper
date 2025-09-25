# DX_IRQDATA structure

## Description

The DX_IRQDATA structure contains the IRQ information supplied by the driver.

## Members

### `dwIrqFlags`

Specifies the type of IRQ that has occurred. One or more of the following:

| Flag | Meaning |
| --- | --- |
| DDIRQ_BUSMASTER | The IRQ was generated because a transfer request was completed. |
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

## See also

[IRQCallback](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_irqcallback)