# _DXGK_DISPLAY_OWNERSHIP_FLAGS structure

## Description

Structure filled in by OS upon successful completion of the DxgkCbAcquirePostDisplayOwnership2 callback to provide information about the display state a driver is inheriting.

## Members

### `FrameBufferState`

Value indicating the state of the frame buffer. See definition of DXGK_FRAMEBUFFER_STATE enum for details.

### `Value`

The value used to operate over the combined bitfields.