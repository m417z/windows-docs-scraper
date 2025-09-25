# D3DDDI_FLUSH_FLAGS enumeration

## Description

In calls to the [pfnFlush1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flush1) function, indicates whether the driver should free as much memory as possible. Used by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Constants

### `D3DDDI_TRIM_MEMORY`

The driver should free as much memory as it can. However, it should not free any memory that the driver requires to continue operating. Using this constant value therefore should not introduce new opportunities to run out of memory.

The driver must no longer call [Video memory offer and reclaim](https://learn.microsoft.com/windows-hardware/drivers/display/video-memory-offer-and-reclaim) DDIs on the memory that it frees.

Supported starting with Windows 8.1.

## See also

[pfnFlush1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flush1)