# PGET_LINK_POSITION_REGISTER callback function

## Description

The `GetLinkPositionRegister` routine retrieves a pointer to a DMA engine's link position register.

The function pointer type for a `GetLinkPositionRegister` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Handle` [in]

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `Position` [out]

Retrieves a pointer to the link position register. This parameter points to a caller-allocated PULONG variable into which the routine writes a pointer to the register. The HD Audio bus driver maps the register to a system virtual address that is accessible to the function driver.

## Return value

`GetLinkPositionRegister` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows a possible return status code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | Indicates that the *handle* parameter value is invalid. |

## Remarks

For more information, see [Wall Clock and Link Position Registers](https://learn.microsoft.com/windows-hardware/drivers/audio/wall-clock-and-link-position-registers).

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)