# _DXGK_HISTORY_BUFFER_HEADER structure

## Description

Specifies how data is stored in a [DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer) history buffer.

## Members

### `RenderCbSequence`

The value of the [D3DDDICB_RENDERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_renderflags).**Value** member that is to be used in a call to the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

The display miniport driver should compute this value and enter it into **DXGK_HISTORY_BUFFER_HEADER** before calling [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb).

### `NumTimestamps`

The number of time stamps that will be in the history buffer when the DMA buffer completes its execution.

The driver should include all time stamps that are logged, even if the buffer must be formatted before being logged to the Event Tracing for Windows (ETW) facility.

### `PrivateDataSize`

The size, in bytes, of optional private data that the driver stores. The driver can use this data for any purpose.

If zero, the driver doesn't need to store private data in the history buffer.

**Note** This value should be a multiple of 8 bytes to ensure that time stamp data is aligned to a 64-bit boundary.

If the history buffer doesn't need to be formatted when the DMA buffer completes its execution, then when the DirectX graphics kernel subsystem writes logs to ETW, it uses **PrivateDataSize** as a direct offset from the header to reference the time stamps.

### `Reserved`

Reserved for system use and must be set to zero.

## Remarks

Only the time stamp portion of the history buffer, along with the number of time stamps, will be logged to ETW. Header data and private driver data will not be logged to ETW as part of the time stamp buffer. However, parts of the header will be logged separately.

## See also

[D3DDDICB_RENDERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_renderflags)

[DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)