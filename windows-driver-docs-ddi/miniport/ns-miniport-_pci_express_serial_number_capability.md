# _PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY structure (miniport.h)

## Description

The PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY structure describes a serial number for a PCI Express (PCIe) device.

## Members

### `Header`

A [PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_enhanced_capability_header) structure that describes the header for this structure.

### `LowSerialNumber`

The lower 32 bits of the serial number.

### `HighSerialNumber`

The upper 32 bits of the serial number.

## Syntax

```cpp
typedef struct _PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY {
  PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER Header;
  ULONG                                  LowSerialNumber;
  ULONG                                  HighSerialNumber;
} PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY, *PPCI_EXPRESS_SERIAL_NUMBER_CAPABILITY;
```

## Remarks

The PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY structure is available in Windows Server 2008 and later versions of Windows.

The PCIe device serial number capability is an optional extended capability that can be implemented by any PCIe device. The device serial number is a 64-bit value that is unique for a given PCIe device.

## See also

[PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_enhanced_capability_header)