# VRAM_SURFACE_INFO structure

## Description

The VRAM_SURFACE_INFO structure describes a region of system or display memory into which an AVStream minidriver captures audio or video data.

## Members

### `hSurface`

A pointer to a kernel-mode handle that identifies the VRAM surface.

### `VramPhysicalAddress`

This member contains the physical address of the surface in display memory. The minidriver fills in this member in the handler for [KSPROPERTY_MAP_CAPTURE_HANDLE_TO_VRAM_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-map-capture-handle-to-vram-address).

### `cbCaptured`

This member specifies the number of bytes copied into the VRAM surface. The minidriver sets this value.

### `dwWidth`

This member specifies the width of the video data in pixels. The minidriver sets this value.

### `dwHeight`

This member specifies the height of the video data, in pixels. The minidriver sets this value.

### `dwLinearSize`

This member specifies the linear size, in bytes, of a nonrectangular surface. The minidriver sets this value.

### `lPitch`

This member specifies the pitch of the surface; that is, the distance, in bytes, to the start of the next line. This is also known as the *stride* of the surface. The minidriver sets this value.

### `ullReserved`

The minidriver can use this member to store information about the surface as it handles a [KSPROPERTY_MAP_CAPTURE_HANDLE_TO_VRAM_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-map-capture-handle-to-vram-address) request. Use caution, however; this structure does not persist across [AVStrMiniPinProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspin) calls.

## Remarks

When the minidriver receives VRAM_SURFACE_INFO through a [KSPROPERTY_MAP_CAPTURE_HANDLE_TO_VRAM_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-map-capture-handle-to-vram-address) property call, the members following **VramPhysicalAddress** in the member list (except for **ullReserved**) are zeroed out. The capture driver can store capture-related private data in these members.

AVStream then stores this information in the stream header and returns it to the minidriver in the [AVStrMiniPinProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspin) callback function.

The data in these members persists for the lifetime of the stream header. When all clones are deleted or the leading edge is advanced, this data is no longer accessible.

## See also

[AVStrMiniPinProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspin)

[KSPROPERTY_MAP_CAPTURE_HANDLE_TO_VRAM_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-map-capture-handle-to-vram-address)