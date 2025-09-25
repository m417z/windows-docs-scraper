# _PCI_EXPRESS_ROOT_ERROR_STATUS structure (wdm.h)

## Description

The PCI_EXPRESS_ROOT_ERROR_STATUS structure describes a PCI Express (PCIe) root error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_ROOT_ERROR_STATUS structure.

### `DUMMYSTRUCTNAME.AdvancedErrorInterruptMessageNumber`

The MSI/MSI-X vector that is used for the interrupt messages that are generated in association with any of the status bits of the advanced error reporting capability.

### `DUMMYSTRUCTNAME.CorrectableErrorReceived`

A single bit that indicates that a correctable error message has been received.

### `DUMMYSTRUCTNAME.FatalErrorMessagesReceived`

A single bit that indicates that one or more non-fatal uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.FirstUncorrectableFatal`

A single bit that indicates that the first uncorrectable error message that was received was for a fatal error.

### `DUMMYSTRUCTNAME.MultipleCorrectableErrorsReceived`

A single bit that indicates that multiple correctable error messages have been received.

### `DUMMYSTRUCTNAME.MultipleUncorrectableErrorsReceived`

A single bit that indicates that multiple uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.NonFatalErrorMessagesReceived`

A single bit that indicates that one or more non-fatal uncorrectable error messages have been received.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `DUMMYSTRUCTNAME.UncorrectableErrorReceived`

A single bit that indicates that an uncorrectable error message has been received.

## Syntax

```cpp
typedef union _PCI_EXPRESS_ROOT_ERROR_STATUS {
  struct {
    ULONG CorrectableErrorReceived  :1;
    ULONG MultipleCorrectableErrorsReceived  :1;
    ULONG UncorrectableErrorReceived  :1;
    ULONG MultipleUncorrectableErrorsReceived  :1;
    ULONG FirstUncorrectableFatal  :1;
    ULONG NonFatalErrorMessagesReceived  :1;
    ULONG FatalErrorMessagesReceived  :1;
    ULONG Reserved  :20;
    ULONG AdvancedErrorInterruptMessageNumber  :5;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_ROOT_ERROR_STATUS, *PPCI_EXPRESS_ROOT_ERROR_STATUS;
```

## Remarks

The PCI_EXPRESS_ROOT_ERROR_STATUS structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_ROOT_ERROR_STATUS structure is contained in the [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structure.

## See also

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)