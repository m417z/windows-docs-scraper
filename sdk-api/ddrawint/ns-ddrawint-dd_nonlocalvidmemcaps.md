# DD_NONLOCALVIDMEMCAPS structure

## Description

The DD_NONLOCALVIDMEMCAPS structure contains the capabilities for nonlocal display memory.

## Members

### `dwSize`

Specifies the size in bytes of this DD_NONLOCALVIDMEMCAPS structure.

### `dwNLVBCaps`

Contains the driver-specific capabilities for nonlocal-to-local display memory blits. See the Remarks section for more information.

### `dwNLVBCaps2`

Contains more of the driver-specific capabilities for nonlocal-to-local display memory blits. See the Remarks section for more information.

### `dwNLVBCKeyCaps`

Contains driver color key capabilities for nonlocal-to-local display memory blits. See the Remarks section for more information.

### `dwNLVBFXCaps`

Contains driver FX capabilities for nonlocal-to-local display memory blits. See the Remarks section for more information.

### `dwNLVBRops`

Specifies an array of DD_ROP_SPACE DWORDs containing the raster operations supported for nonlocal-to-local blits. The constant DD_ROP_SPACE is defined in *ddraw.h*. See the Remarks section for more information.

## Remarks

On Microsoft Windows 2000 and later versions, the data structure is called DD_NONLOCALVIDMEMCAPS and on Windows 98/Me the data structure is called DDNONLOCALVIDMEMCAPS.

Normally, the **dwNLVBCaps**, **dwNLVBCaps2**, **dwNFLBCKeyCaps**, **dwNLVBFXCaps**, and **dwNLVBRops** members contain a subset of the flags used in the [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps) structure that is relevant to nonlocal-to-local blitting. However, to allow flexibility for device driver writers, any of the flags in DDCORECAPS can be used.

## See also

[DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps)