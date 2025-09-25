# PCMCIA_IS_WRITE_PROTECTED callback function

## Description

The **PCMCIA_IS_WRITE_PROTECTED** interface routine returns the write-protect condition of a PCMCIA memory card.

## Parameters

### `Context` [in, optional]

Pointer to the context for the interface routine.

## Return value

The **PCMCIA_IS_WRITE_PROTECTED** interface routine returns **TRUE** if the memory card is write-protected, otherwise it returns **FALSE**.

## Remarks

A caller must set the *Context* parameter to the context that is specified by the PCMCIA bus driver. The PCMCIA bus driver returns the context for the interface routines in the **Context** member of the same PCMCIA_INTERFACE_STANDARD structure that contains the pointers to the interface routines. If the *Context* parameter is not valid, system behavior is not defined, and the system might halt.

Callers of this routine must be running at IRQL <= DISPATCH_LEVEL. To maintain overall system performance, it is recommended that drivers call this routine at IRQL < DISPATCH_LEVEL.

## See also

[PCMCIA_MODIFY_MEMORY_WINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_modify_memory_window)

[PCMCIA_SET_VPP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_set_vpp)