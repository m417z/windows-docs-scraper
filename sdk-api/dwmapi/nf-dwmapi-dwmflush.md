## Description

Issues a flush call that blocks the caller until the next call to a Present method, when all of the Microsoft DirectX surface updates that are currently outstanding have been made. This compensates for very complex scenes or calling processes with very low priority.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**DwmFlush** waits for any queued DirectX changes that were queued by the calling application to be drawn to the screen before returning. It does not flush the entire session rendering batch.