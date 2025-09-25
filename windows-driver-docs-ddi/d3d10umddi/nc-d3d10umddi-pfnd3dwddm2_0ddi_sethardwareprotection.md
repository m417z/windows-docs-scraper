# PFND3DWDDM2_0DDI_SETHARDWAREPROTECTION callback function

## Description

**SetHardwareProtection** allows the Desktop Window Manager (DWM) full-screen swap chain buffers to transfer between protected and non-protected states without having to be recreated.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hResource`

A handle to the resource object that was created through a call to the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)DDI.

### `Protected`

Indicates that the buffer should be protected.

## Remarks

Destroying and re-creating the DWM swap chain buffers is a heavyweight operation that can be avoided on some hardware. This DDI will only be called if the driver reports the **D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECTED_MEMORY_TRANSITION** capability. If this is not set, the underlying DWM swap chain allocations will be destroyed and recreated.

**SetHardwareProtection** is called on the non-visible swap chain buffers allowing it to transition between protected and unprotected modes without causing a visual artifact. When the DWM flips to the newly changed buffer, the DWM will call **SetHardwareProtection** on the next buffer in the swap chain buffer, and so on until the new protection state has been set on each of the swap chain buffers.

**Note** The DWM is guaranteed to re-render the entire swap chain buffer after the hardware protection state has changed.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)