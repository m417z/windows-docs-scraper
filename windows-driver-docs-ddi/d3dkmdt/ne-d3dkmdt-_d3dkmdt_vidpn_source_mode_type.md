# _D3DKMDT_VIDPN_SOURCE_MODE_TYPE enumeration

## Description

The D3DKMDT_VIDPN_SOURCE_MODE_TYPE enumeration is used to indicate whether a video present network (VidPN) source mode is a graphics mode, a text mode, or a stereo mode.

## Constants

### `D3DKMDT_RMT_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_SOURCE_MODE_TYPE has not yet been assigned a meaningful value.

### `D3DKMDT_RMT_GRAPHICS`

Indicates that the VidPN source mode is a graphics mode.

### `D3DKMDT_RMT_TEXT`

Indicates that the VidPN source mode is a text mode.

### `D3DKMDT_RMT_GRAPHICS_STEREO`

Available beginning with Windows 8.

Indicates that the VidPN source mode is stereo, and the allocation can only be scanned by the display miniport driver as both left and right channels.

### `D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN`

Available beginning with Windows 8.

Indicates that the VidPN source mode is stereo, and the allocation can only be scanned by the display miniport driver as both left and right channels, or as only the left channel, or as only the right channel.

If mono content needs to be displayed in a stereo mode, the operating system can better manage resources if **D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN** is set instead of **D3DKMDT_RMT_GRAPHICS_STEREO**.

## Remarks

The **Type** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure is a D3DKMDT_VIDPN_SOURCE_MODE_TYPE value.