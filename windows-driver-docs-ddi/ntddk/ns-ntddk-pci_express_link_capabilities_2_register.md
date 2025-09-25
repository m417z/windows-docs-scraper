## Description

The **PCI_EXPRESS_LINK_CAPABILITIES_2_REGISTER** structure describes a PCI Express (PCIe) link capabilities 2 register of a PCIe capability structure. This is an extension of the PCIe link capabilities register.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Rsvd0`

Reserved.

### `DUMMYSTRUCTNAME.SupportedLinkSpeedsVector`

Indicates the supported link speeds of the PCIe link. For each bit position, a value of 1b indicates that the corresponding link speed is supported; otherwise, that speed is not supported. Note that this field is preferred as the source of truth over the [MaximumLinkSpeed](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_capabilities_register#members) field.

Bit definitions within this field with the corresponding link speed are:

| Bit Position | Supported Link Speed |
| --- | --- |
| **0** | 2.5 GT/s |
| **1** | 5.0 GT/s |
| **2** | 8.0 GT/s |
| **3** | 16.0 GT/s |
| **4** | 32.0 GT/s |
| **All other bit positions** | Reserved |

### `DUMMYSTRUCTNAME.Rsvd8_31`

Reserved.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_LINK_CAPABILITIES_2_REGISTER** structure.

## Remarks

A **PCI_EXPRESS_LINK_CAPABILITIES_2_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[PCI_EXPRESS_LINK_CAPABILITIES_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_capabilities_register)