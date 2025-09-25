# PFREEMEM callback function

## Description

The
*PFREEMEM* function is a memory-freeing function provided by the PCM.
*PFREEMEM* frees memory buffers that were allocated using
[PALLOCMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pallocmem). The
*PFREEMEM* function is supplied as a parameter of the
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function. The combination of
*PALLOCMEM* and
*PFREEMEM* allows the SBM to experiment with different memory-management schemes without requiring recompilation of LPMs.

## Parameters

### `pv` [in]

Pointer to the memory buffer to free.

### `szFileName`

### `nLine`

## Remarks

LPMs do not need to use this function to manage their local buffers. LPMs need to use this function to free buffers that were allocated, but were not sent to the PCM. For example, if a buffer is allocated in anticipation of a PCM's response to a request, but a response is never returned (perhaps the remote policy store is unavailable or unresponsive), that buffer must be freed with this function, or a memory leak will ensue.

## See also

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)

[PALLOCMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pallocmem)