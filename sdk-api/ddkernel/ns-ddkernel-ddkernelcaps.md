# DDKERNELCAPS structure

## Description

The DDKERNELCAPS structure notifies the client what support, if any, exists in the miniport driver for the kernel-mode video transport.

## Members

### `dwSize`

Specifies the size, in bytes, of this structure. This member must be initialized before the structure is used.

### `dwCaps`

Specifies a set of flags indicating the device's capabilities. This member can be any combination of the following capabilities:

| Flag | Meaning |
| --- | --- |
| DDKERNELCAPS_AUTOFLIP | The driver supports the [DxFlipVideoPort](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipvideoport) and the [DxFlipOverlay](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipoverlay) callbacks, and that these callbacks can be used for autoflipping. |
| DDKERNELCAPS_CAPTURE_INVERTED | The device supports inverting the [DIBs](https://learn.microsoft.com/windows-hardware/drivers/) while capturing the data. |
| DDKERNELCAPS_CAPTURE_NONLOCALVIDMEM | The device supports a [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) capture interface capable of transferring data to nonlocal display memory. |
| DDKERNELCAPS_CAPTURE_SYSMEM | The device supports a VPE capture interface capable of transferring data to system memory. |
| DDKERNELCAPS_FIELDPOLARITY | The device can report the polarity (even/odd) of the current VPE object field. |
| DDKERNELCAPS_FLIPOVERLAY | The driver supports the [DxFlipOverlay](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipoverlay) callback. |
| DDKERNELCAPS_FLIPVIDEOPORT | The driver supports the [DxFlipVideoPort](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipvideoport) callback. |
| DDKERNELCAPS_LOCK | The device supports accessing the frame buffer without causing contention with blitters, and so on, and that the driver supports the [DxLock](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_lock) callback. |
| DDKERNELCAPS_SETSTATE | The driver supports the [DxSetState](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_setstate) callback, allowing a client to switch between bob and weave display modes. |
| DDKERNELCAPS_SKIPFIELDS | The device supports field skipping, either using hardware or by supporting the [DxSkipNextField](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_skipnextfield) callback. |

### `dwIRQCaps`

Can be a combination of the following flags:

| Flag | Meaning |
| --- | --- |
| DDIRQ_DISPLAY_VSYNC | The device can generate IRQs based on the display VSYNC. |
| DDIRQ_VPORT0_LINE | The device can generate IRQs based on a programmable line for hardware video port number 0. |
| DDIRQ_VPORT0_VSYNC | The device can generate VSYNC IRQs for hardware video port number 0. |
| DDIRQ_VPORT1_LINE | The device can generate IRQs based on a programmable line for hardware video port number 1. |
| DDIRQ_VPORT1_VSYNC | The device can generate V-sync IRQs for hardware video port number 1 |
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
| DDIRQ_VPORT9_LINE | he device can generate IRQs based on a programmable line for hardware video port number 9. |
| DDIRQ_VPORT9_VSYNC | he device can generate V-sync IRQs for hardware video port number 9. |

## See also

[DxFlipOverlay](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipoverlay)

[DxFlipVideoPort](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipvideoport)

[DxLock](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_lock)

[DxSetState](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_setstate)

[DxSkipNextField](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_skipnextfield)