# _WHEA_PCI_SLOT_NUMBER structure

## Description

The WHEA_PCI_SLOT_NUMBER structure describes a logical PCI slot.

## Members

### `u`

A union that contains the following members:

### `u.bits`

A structure that describes the logical PCI slot.

### `u.bits.DeviceNumber`

The device number that is assigned to the logical PCI slot.

### `u.bits.FunctionNumber`

The specific function on the device that is located in the logical PCI slot.

### `u.bits.Reserved`

Reserved for system use.

### `u.AsULONG`

A ULONG representation of the contents of the WHEA_PCI_SLOT_NUMBER structure.

## Remarks

A WHEA_PCI_SLOT_NUMBER structure is contained within the [WHEA_AER_BRIDGE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_bridge_descriptor), [WHEA_AER_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_endpoint_descriptor), and [WHEA_AER_ROOTPORT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_rootport_descriptor) structures.

## See also

[WHEA_AER_BRIDGE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_bridge_descriptor)

[WHEA_AER_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_endpoint_descriptor)

[WHEA_AER_ROOTPORT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_aer_rootport_descriptor)