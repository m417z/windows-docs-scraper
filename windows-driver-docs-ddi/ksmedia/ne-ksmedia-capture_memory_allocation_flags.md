# CAPTURE_MEMORY_ALLOCATION_FLAGS enumeration

## Description

The CAPTURE_MEMORY_ALLOCATION_FLAGS enumeration defines types of memory surfaces to which AVStream minidrivers can capture audio and video data. The [KSPROPERTY_PREFERRED_CAPTURE_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-preferred-capture-surface) and [KSPROPERTY_CURRENT_CAPTURE_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-current-capture-surface) requests use this type to specify property values.

## Constants

### `KS_CAPTURE_ALLOC_INVALID`

Invalid memory surface.

### `KS_CAPTURE_ALLOC_SYSTEM`

Not currently supported.

### `KS_CAPTURE_ALLOC_VRAM`

Identifies a surface in display memory.

### `KS_CAPTURE_ALLOC_SYSTEM_AGP`

Identifies a surface in system memory that is tagged as AGP accessible.

### `KS_CAPTURE_ALLOC_VRAM_MAPPED`

Not currently supported.

### `KS_CAPTURE_ALLOC_SECURE_BUFFER`

## See also

[KSPROPERTY_CURRENT_CAPTURE_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-current-capture-surface)

[KSPROPERTY_PREFERRED_CAPTURE_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-preferred-capture-surface)