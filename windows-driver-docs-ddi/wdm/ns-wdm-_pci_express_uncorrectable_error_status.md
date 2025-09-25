# _PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS structure (wdm.h)

## Description

The PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS structure describes a PCI Express (PCIe) uncorrectable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS structure.

### `DUMMYSTRUCTNAME.CompleterAbort`

A single bit that indicates that a completer abort has occurred.

### `DUMMYSTRUCTNAME.CompletionTimeout`

A single bit that indicates that a completion timeout has occurred.

### `DUMMYSTRUCTNAME.DataLinkProtocolError`

A single bit that indicates that a data link protocol error has occurred.

### `DUMMYSTRUCTNAME.ECRCError`

A single bit that indicates that an end-to-end cyclic redundancy check (ECRC) error has occurred.

### `DUMMYSTRUCTNAME.FlowControlProtocolError`

A single bit that indicates that a flow control protocol error has occurred.

### `DUMMYSTRUCTNAME.MalformedTLP`

A single bit that indicates that a malformed transaction layer packet (TLP) has been detected.

### `DUMMYSTRUCTNAME.PoisonedTLP`

A single bit that indicates that a poisoned transaction layer packet (TLP) has been detected.

### `DUMMYSTRUCTNAME.ReceiverOverflow`

A single bit that indicates that the receiver has overflowed.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `DUMMYSTRUCTNAME.SurpriseDownError`

A single bit that indicates that a surprise down error has occurred.

### `DUMMYSTRUCTNAME.Undefined`

A single bit that contains an undefined value. In versions of the *PCIe Specification* prior to version 1.1, this bit indicates that a link training error has occurred.

### `DUMMYSTRUCTNAME.UnexpectedCompletion`

A single bit that indicates that an unexpected completion has occurred.

### `DUMMYSTRUCTNAME.UnsupportedRequestError`

A single bit that indicates that an unsupported request error has occurred.

### `DUMMYSTRUCTNAME.AcsViolation`

### `DUMMYSTRUCTNAME.UncorrectableInternalError`

### `DUMMYSTRUCTNAME.MCBlockedTlp`

### `DUMMYSTRUCTNAME.AtomicOpEgressBlocked`

### `DUMMYSTRUCTNAME.TlpPrefixBlocked`

## Syntax

```cpp
typedef union _PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS {
  struct {
    ULONG Undefined  :1;
    ULONG Reserved1  :3;
    ULONG DataLinkProtocolError  :1;
    ULONG SurpriseDownError  :1;
    ULONG Reserved2  :6;
    ULONG PoisonedTLP  :1;
    ULONG FlowControlProtocolError  :1;
    ULONG CompletionTimeout  :1;
    ULONG CompleterAbort  :1;
    ULONG UnexpectedCompletion  :1;
    ULONG ReceiverOverflow  :1;
    ULONG MalformedTLP  :1;
    ULONG ECRCError  :1;
    ULONG UnsupportedRequestError  :1;
    ULONG Reserved3  :11;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS, *PPCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS;
```

## Remarks

The PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)