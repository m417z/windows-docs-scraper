## Description

The **PCI_EXPRESS_ROOT_ERROR_COMMAND** union describes a PCI Express (PCIe) root error command register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CorrectableErrorReportingEnable`

A single bit that indicates that interrupts are enabled for when a correctable error is reported by any of the devices in the hierarchy that are associated with this root port.

### `DUMMYSTRUCTNAME.NonFatalErrorReportingEnable`

A single bit that indicates that interrupts are enabled for when a non-fatal error is reported by any of the devices in the hierarchy that are associated with this root port.

### `DUMMYSTRUCTNAME.FatalErrorReportingEnable`

A single bit that indicates that interrupts are enabled for when a non-fatal error is reported by any of the devices in the hierarchy that are associated with this root port.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_ROOT_ERROR_COMMAND** structure.

## Remarks

The **PCI_EXPRESS_ROOT_ERROR_COMMAND** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ROOT_ERROR_COMMAND** structure is contained in the [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structure.

## See also

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)