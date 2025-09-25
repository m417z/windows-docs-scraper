# PCMCIA_MODIFY_MEMORY_WINDOW callback function

## Description

The **PCMCIA_MODIFY_MEMORY_WINDOW** interface routine sets the attributes of a memory window for a PCMCIA memory card. The memory window is mapped by the PCMCIA bus driver.

## Parameters

### `Context` [in, optional]

Pointer to the context for the interface routine.

### `HostBase` [in]

Specifies the physical memory window to map. *HostBase* is the base address for the memory card in the system's physical address space.

### `CardBase` [in]

Specifies the byte offset in the PC Card's or CardBus card's memory where the memory mapping begins.

### `Enable` [in]

Specifies permission to access the memory window. If *Enable* is **TRUE**, memory access is permitted, otherwise memory access is not permitted.

### `WindowSize` [in, optional]

Specifies the size, in bytes, of the memory window that is mapped. The value of *WindowSize* cannot exceed the memory window granted to the driver in its assigned resources. If the value of Enable is **TRUE** and the value of WindowSize is zero, the size of the memory window granted to the driver in its assigned resources is used. If *Enable* is **FALSE**, *WindowSize* is not used.

### `AccessSpeed` [in, optional]

Specifies the access speed of the PC Card or CardBus card. The value of *AccessSpeed* is encoded as specified by the *PC Card Standard, Release 6.1*. If Enable is **FALSE**, *AccessSpeed* is not used.

### `BusWidth` [in, optional]

Specifies the width of bus access to the PCMCIA memory card. *BusWidth* must be one of the following values:

- **PCMCIA_MEMORY_8BIT_ACCESS**: If *Enable* is **FALSE**, *BusWidth* is not used.
- **PCMCIA_MEMORY_16BIT_ACCESS**

### `IsAttributeMemory` [in, optional]

Must be **FALSE** for common memory and **TRUE** for attribute memory.

## Return value

The **PCMCIA_MODIFY_MEMORY_WINDOW** interface routine returns **TRUE** if the memory window is successfully enabled or disabled, as specified by the *Enable* parameter.

## Remarks

A caller must set the *Context* parameter to the context that is specified by the PCMCIA bus driver. The PCMCIA bus driver returns the context for the interface routines in the **Context** member of the same PCMCIA_INTERFACE_STANDARD structure that contains the pointers to the interface routines. If the *Context* parameter is not valid, system behavior is not defined, and the system might halt.

Callers of this routine must be running at IRQL <= DISPATCH_LEVEL. To maintain overall system performance, it is recommended that drivers call this routine at IRQL < DISPATCH_LEVEL.

## See also

- [PCMCIA_IS_WRITE_PROTECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_is_write_protected)
- [PCMCIA_SET_VPP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/nc-ntddpcm-pcmcia_set_vpp)