# _KERNDATA structure

## Description

The KERNDATA structure is used for describing printer kerning pairs.

## Members

### `dwSize`

Specifies the size, in bytes, of KERNDATA structure, including the **KernPair** array.

### `dwKernPairNum`

Specifies the number of elements in the **KernPair** array.

### `KernPair`

Is an array of [FD_KERNINGPAIR](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fd_kerningpair) structures.

## Remarks

A .ufm file's KERNDATA structures are accessed by a pointer in the file's [UNIFM_HDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr) structure.

## See also

[FD_KERNINGPAIR](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fd_kerningpair)

[UNIFM_HDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr)