# BRUSHOBJ_pvAllocRbrush function

## Description

The **BRUSHOBJ_pvAllocRbrush** function allocates memory for the driver's realization of a specified brush.

## Parameters

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure for which the realization is to be allocated.

### `cj`

Specifies the size, in bytes, required for the realization.

## Return value

The return value is a pointer to the allocated memory if the function is successful. Otherwise, it is null, and an error code is logged.

## Remarks

**BRUSHOBJ_pvAllocRbrush** allocates memory for the brush realization. GDI manages the memory and discards it when the brush is no longer needed.

This function should be called only by an implementation of a brush realization following a call to [DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush).

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush)