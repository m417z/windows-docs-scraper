## Description

The **PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER** union describes a PCI Express (PCIe) root capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CRSSoftwareVisibility`

A single bit that indicates that the root port is capable of returning configuration request retry status (CRS) completion status to software.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)