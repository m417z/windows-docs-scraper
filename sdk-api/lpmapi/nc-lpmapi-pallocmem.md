# PALLOCMEM callback function

## Description

The
*PALLOCMEM* function is a memory allocation function provided by the PCM, used for allocating memory when returning policy information to the PCM. The
*PALLOCMEM* function is supplied as a parameter of the
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function, and allows the SBM to experiment with different memory-management schemes without requiring recompilation of LPMs.

## Parameters

### `Size` [in]

Size of the memory buffer required by the LPM.

### `szFileName`

### `nLine`

## Return value

Returns a pointer to the requested memory allocation.

## Remarks

LPMs do not need to use this function to manage their local buffers.

## See also

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)