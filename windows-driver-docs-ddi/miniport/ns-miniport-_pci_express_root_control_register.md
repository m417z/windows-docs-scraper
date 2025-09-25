## Description

The **PCI_EXPRESS_ROOT_CONTROL_REGISTER** union describes a PCI Express (PCIe) root control register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CorrectableSerrEnable`

A single bit that indicates that a system error should be generated if a correctable error is reported by any of the devices in the hierarchy that are associated with this root port or by the root port itself.

### `DUMMYSTRUCTNAME.NonFatalSerrEnable`

A single bit that indicates that a system error should be generated if a non-fatal error is reported by any of the devices in the hierarchy that are associated with this root port or by the root port itself.

### `DUMMYSTRUCTNAME.FatalSerrEnable`

A single bit that indicates that a system error should be generated if a non-fatal error is reported by any of the devices in the hierarchy that are associated with this root port or by the root port itself.

### `DUMMYSTRUCTNAME.PMEInterruptEnable`

A single bit that indicates that interrupts are enabled for power management events.

### `DUMMYSTRUCTNAME.CRSSoftwareVisibilityEnable`

A single bit that indicates that the root port is enabled to return configuration request retry status (CRS) completion status to software.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_ROOT_CONTROL_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_ROOT_CONTROL_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ROOT_CONTROL_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)