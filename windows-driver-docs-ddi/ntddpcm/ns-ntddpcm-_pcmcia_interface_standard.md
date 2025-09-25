# _PCMCIA_INTERFACE_STANDARD structure

## Description

The PCMCIA bus driver makes the PCMCIA_INTERFACE_STANDARD interface available to PCMCIA memory card drivers in order to allow them to make direct calls to the bus driver without allocating IRPs.

## Members

### `Size`

Indicates the size of the returned interface.

### `Version`

Indicates the version of the returned interface.

### `InterfaceReference`

Pointer to the [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) implementation.

### `InterfaceDereference`

Pointer to the [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) implementation.

### `Context`

Pointer to an opaque handle that contains interface context information. Drivers that call routines that belong to the **PCMCIA_INTERFACE_STANDARD** interface must pass this value to the interface routines when they call them.

### `ModifyMemoryWindow`

Pointer to the [PCMCIA_MODIFY_MEMORY_WINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_modify_memory_window) interface routine.

### `SetVpp`

Pointer to the [PCMCIA_SET_VPP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_set_vpp) interface routine.

### `IsWriteProtected`

Pointer to the [PCMCIA_IS_WRITE_PROTECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_is_write_protected) interface routine.

## See also

[PCMCIA_IS_WRITE_PROTECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_is_write_protected)

[PCMCIA_MODIFY_MEMORY_WINDOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_modify_memory_window)

[PCMCIA_SET_VPP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_set_vpp)