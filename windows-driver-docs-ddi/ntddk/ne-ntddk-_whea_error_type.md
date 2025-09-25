# _WHEA_ERROR_TYPE enumeration

## Description

The WHEA_ERROR_TYPE enumeration defines the different types of hardware components that can report a hardware error.

## Constants

### `WheaErrTypeProcessor`

A processor reported the hardware error.

### `WheaErrTypeMemory`

The memory hierarchy reported the hardware error.

### `WheaErrTypePCIExpress`

A PCI Express root port reported the hardware error.

### `WheaErrTypeNMI`

A nonmaskable interrupt (NMI) was signaled.

### `WheaErrTypePCIXBus`

A PCI or PCI-X bus reported the hardware error.

### `WheaErrTypePCIXDevice`

A PCI or PCI-X device reported the hardware error.

### `WheaErrTypeGeneric`

A hardware component that does not conform to any of the other WHEA_ERROR_TYPE enumeration values reported the hardware error.

### `WheaErrTypePmem`

## Remarks

The [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure contains a member of type WHEA_ERROR_TYPE that specifies the type of hardware component that reported the hardware error.

## See also

[WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))