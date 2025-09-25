# _D3DDDI_RESOURCEFLAGS2 structure

## Description

Identifies the type of resource to create in a call to the driver's [CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2) function.

## Members

### `VideoEncoder`

If set, indicates that the resource can be used as a capture buffer and/or a video encoder input resource.

If this member is set, the driver must set either the **FORMATOP_CAPTURE** or **FORMATOP_VIDEO_ENCODER** flag values, or both, in the **Operations** member of the [FORMATOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_formatop) structure.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `UserMemory`

If set, indicates that the memory for this surface was allocated by the application, not by the Direct3D runtime.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `CrossAdapter`

If set, indicates that the resource is a shared cross-adapter resource.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

Supported starting with Windows 8.1.

### `IsDisplayable`

### `Reserved`

Reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.1.

Reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies the type of resource to create.

## See also

[CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2)

[FORMATOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_formatop)