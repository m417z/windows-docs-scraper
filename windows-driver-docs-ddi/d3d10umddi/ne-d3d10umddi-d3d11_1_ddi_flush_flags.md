# D3D11_1_DDI_FLUSH_FLAGS enumeration

## Description

In calls to the [Flush(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_flush) function, indicates whether the driver should continue to submit command buffers. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Constants

### `D3D11_1DDI_FLUSH_UNLESS_NO_COMMANDS`

The driver should not submit command buffers if there have been no new commands since the last time the driver submitted a command buffer.

### `D3DWDDM1_3DDI_TRIM_MEMORY`

The driver should free as much memory as it can. However, it should not free any memory that the driver requires to continue operating. Using this constant value therefore should not introduce new opportunities to run out of memory.

The driver must no longer call [Video memory offer and reclaim](https://learn.microsoft.com/windows-hardware/drivers/display/video-memory-offer-and-reclaim) DDIs on the memory that it frees.

Supported starting with Windows 8.1 for WDDM 1.3 and later user-mode display drivers.

## See also

[Flush(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_flush)