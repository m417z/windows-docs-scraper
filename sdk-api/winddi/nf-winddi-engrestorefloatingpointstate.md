# EngRestoreFloatingPointState function

## Description

The **EngRestoreFloatingPointState** function restores the Windows 2000 (and later) kernel floating-point state after the driver uses any floating-point or MMX hardware instructions.

## Parameters

### `pBuffer` [in]

Pointer to the buffer whose contents were filled by [EngSaveFloatingPointState](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsavefloatingpointstate).

## Return value

**EngRestoreFloatingPointState** returns **TRUE** if successful. Otherwise, it returns **FALSE**.

## Remarks

The driver must save the current kernel floating-point state before using floating-point hardware instructions. On Intel architecture systems, this permits the use of MMX instructions if they are supported by the processor. Drivers that do not properly use **EngSaveFloatingPointState** and **EngRestoreFloatingPointState** when using floating-point or MMX hardware will cause random floating-point or MMX corruption in the calling application.

On every call to the driver, the driver must call **EngSaveFloatingPointState** once to preserve kernel state before using floating-point or MMX operations. It must also call **EngRestoreFloatingPointState** once after all floating-point or MMX operations are complete to reset the kernel state.

GDI automatically saves the floating-point state for any calls to a driver's [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape) routine when the escape is OPENGL_CMD, OPENGL_GETINFO, or MCDFUNCS.

## See also

[DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape)

[EngSaveFloatingPointState](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsavefloatingpointstate)