# _DXGK_FRAMEBUFFER_STATE enumeration

## Description

The frame buffer state is provided to the driver in order that the driver can infer details of the display configuration based on knowledge of how firmware and the driver will set a particular resolution even though only basic information is made directly available by the OS to the driver.

## Constants

### `FrameBufferStateUnknown`

Value indicating that the OS has insufficient information to report the frame buffer state.

### `FrameBufferStateInitializedByFirmware`

Value indicating that the frame buffer was initialized using either UEFI or VBIOS.

### `FrameBufferStateInitializedByDriver`

Value indicating that the hardware specific driver last initialized the frame buffer when the previous driver was stopped. Note, the driver which initialized the frame buffer may not be the same version as is currently running if the driver has been updated.

## Remarks

FrameBufferStateUnknown will be reported if the frame buffer state is undefined, or if the frame buffer has been initialized but may have been changed by the Basic Display Driver. The other two states should only be reported if that state is reliable.