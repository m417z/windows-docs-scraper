## Description

The **PCI_EXPRESS_ROOT_ERROR_STATUS** structure describes a PCI Express (PCIe) root error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CorrectableErrorReceived`

A single bit that indicates that a correctable error message has been received.

### `DUMMYSTRUCTNAME.MultipleCorrectableErrorsReceived`

A single bit that indicates that multiple correctable error messages have been received.

### `DUMMYSTRUCTNAME.UncorrectableErrorReceived`

A single bit that indicates that an uncorrectable error message has been received.

### `DUMMYSTRUCTNAME.MultipleUncorrectableErrorsReceived`

A single bit that indicates that multiple uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.FirstUncorrectableFatal`

A single bit that indicates that the first uncorrectable error message that was received was for a fatal error.

### `DUMMYSTRUCTNAME.NonFatalErrorMessagesReceived`

A single bit that indicates that one or more non-fatal uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.FatalErrorMessagesReceived`

A single bit that indicates that one or more non-fatal uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `DUMMYSTRUCTNAME.AdvancedErrorInterruptMessageNumber`

The MSI/MSI-X vector that is used for the interrupt messages that are generated in association with any of the status bits of the advanced error reporting capability.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_ROOT_ERROR_STATUS** structure.

## Remarks

The **PCI_EXPRESS_ROOT_ERROR_STATUS** union is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ROOT_ERROR_STATUS** union is contained in the [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structure.

## See also

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)