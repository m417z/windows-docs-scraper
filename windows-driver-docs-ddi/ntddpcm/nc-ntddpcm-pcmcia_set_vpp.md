# PCMCIA_SET_VPP callback function

## Description

The **PCMCIA_SET_VPP** interface routine sets the power level of the Vpp PCMCIA pin (secondary power source).

## Parameters

### `Context` [in, optional]

Pointer to the context for the interface routine.

### `VppLevel` [in]

Specifies the voltage level to set on the Vpp pin. *VppLevel* must be one of the following values:

#### PCMCIA_VPP_0V

Specifies that the voltage on the Vpp pin be set to zero volts and that the Vpp pin be disabled.

#### PCMCIA_VPP_12V

Specifies that the voltage on the Vpp pin be set to twelve volts.

#### PCMCIA_VPP_IS_VCC

Specifies that the voltage on the Vpp pin be set to equal the voltage on the Vcc (primary card power) pin.

## Return value

The **PCMCIA_SET_VPP** interface routine returns **TRUE** after the requested voltage level is set.

## Remarks

The **PCMCIA_SET_VPP** interface routine returns control to the caller after the requested voltage is established in a stable state for the card.

A caller must set the *Context* parameter to the context that is specified by the PCMCIA bus driver. The PCMCIA bus driver returns the context for the interface routines in the **Context** member of the same PCMCIA_INTERFACE_STANDARD structure that contains the pointers to the interface routines. If the *Context* parameter is not valid, system behavior is not defined, and the system might halt.

Callers of this routine can run at IRQL <= DISPATCH_LEVEL. To maintain overall system performance, it is recommended that drivers call this routine at IRQL < DISPATCH_LEVEL.

## See also

[PCMCIA_IS_WRITE_PROTECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_is_write_protected)

[PCMCIA_MODIFY_MEMORY_WINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_modify_memory_window)