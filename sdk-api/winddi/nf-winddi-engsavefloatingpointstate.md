# EngSaveFloatingPointState function

## Description

The **EngSaveFloatingPointState** function saves the current Windows 2000 (and later) kernel floating-point state.

## Parameters

### `pBuffer`

Pointer to the buffer that receives the floating-point state. This buffer must be zero-initialized, and must be in nonpaged memory.

### `cjBufferSize` [in, out]

Specifies the size, in bytes, of the buffer to which *pBuffer* points.

## Return value

If *pBuffer* is non-**NULL**, **EngSaveFloatingPointState** returns **TRUE** if the state is successfully saved. It returns **FALSE** if the specified buffer is too small or the state cannot be saved.

If *pBuffer* is **NULL** or *cjBufferSize* is zero, **EngSaveFloatingPointState** returns the size of the buffer needed to save the floating-point state. If the return value is zero, the processor does not have hardware floating-point capability. In this case, the driver must not use any floating-point instructions.

## Remarks

The driver must save the current kernel floating-point state before using floating-point hardware instructions. On Intel architecture systems, this permits the use of MMX instructions if they are supported by the processor. Drivers that do not properly use **EngSaveFloatingPointState** and [EngRestoreFloatingPointState](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engrestorefloatingpointstate) when using floating-point or MMX hardware will cause random floating-point or MMX corruption in the calling application.

On every call to the driver, the driver must call **EngSaveFloatingPointState** once to preserve kernel state before using floating-point or MMX operations. It must also call **EngRestoreFloatingPointState** once after all floating-point or MMX operations are complete to reset the kernel state.

GDI automatically saves the floating-point state for any calls to a driver's [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape) routine when the escape is OPENGL_CMD, OPENGL_GETINFO, or MCDFUNCS.

## See also

[DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape)

[EngRestoreFloatingPointState](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engrestorefloatingpointstate)