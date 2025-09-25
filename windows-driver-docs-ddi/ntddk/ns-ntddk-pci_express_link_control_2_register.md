## Description

The **PCI_EXPRESS_LINK_CONTROL_2_REGISTER** structure describes a PCI Express (PCIe) link control 2 register of a PCIe capability structure. This is an extension of the PCIe link control register.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.TargetLinkSpeed`

For Downstream Ports, this field sets an upper limit on a PCIe link's operational speed by restricting the values advertised by the Upstream component in its training sequences.
The encoded value specifies a bit location in the Supported Link Speeds Vector (in the Link Capabilities 2 Register) corresponding to the desired operational link speed.

Defined encodings are:

| Value (binary) | Supported Link Speeds Vector field bit position | Link Speed |
| --- | --- | --- |
| **0001b** | 0 | 2.5 GT/s |
| **0010b** | 1 | 5.0 GT/s |
| **0011b** | 2 | 8.0 GT/s |
| **0100b** | 3 | 16.0 GT/s |
| **0101b** | 4 | 32.0 GT/s |
| **All other values** | Reserved | Reserved |

### `DUMMYSTRUCTNAME.Rsvd4_15`

Reserved.

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_LINK_CONTROL_2_REGISTER** structure.

## Remarks

A **PCI_EXPRESS_LINK_CONTROL_2_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)