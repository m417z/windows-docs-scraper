# _PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY structure (wdm.h)

## Description

The PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY structure describes a PCI Express (PCIe) uncorrectable error severity register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY structure.

### `DUMMYSTRUCTNAME.CompleterAbort`

A single bit that indicates that a reported completer abort is a fatal error.

### `DUMMYSTRUCTNAME.CompletionTimeout`

A single bit that indicates that a reported completion timeout is a fatal error.

### `DUMMYSTRUCTNAME.DataLinkProtocolError`

A single bit that indicates that a reported data link protocol error is a fatal error.

### `DUMMYSTRUCTNAME.ECRCError`

A single bit that indicates that a reported end-to-end cyclic redundancy check (ECRC) error is a fatal error.

### `DUMMYSTRUCTNAME.FlowControlProtocolError`

A single bit that indicates that a reported flow control protocol error is a fatal error.

### `DUMMYSTRUCTNAME.MalformedTLP`

A single bit that indicates that a reported malformed transaction layer packet (TLP) is a fatal error.

### `DUMMYSTRUCTNAME.PoisonedTLP`

A single bit that indicates that a reported poisoned transaction layer packet (TLP) is a fatal error.

### `DUMMYSTRUCTNAME.ReceiverOverflow`

A single bit that indicates that a reported receiver overflow is a fatal error.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `DUMMYSTRUCTNAME.SurpriseDownError`

A single bit that indicates that a reported surprise down error is a fatal error.

### `DUMMYSTRUCTNAME.Undefined`

A single bit that contains an undefined value. In versions of the *PCIe Specification* prior to version 1.1, this bit indicates that a reported link training error is a fatal error.

### `DUMMYSTRUCTNAME.UnexpectedCompletion`

A single bit that indicates that a reported unexpected completion is a fatal error.

### `DUMMYSTRUCTNAME.UnsupportedRequestError`

A single bit that indicates that a reported unsupported request error is a fatal error.

### `DUMMYSTRUCTNAME.AcsViolation`

### `DUMMYSTRUCTNAME.UncorrectableInternalError`

### `DUMMYSTRUCTNAME.MCBlockedTlp`

### `DUMMYSTRUCTNAME.AtomicOpEgressBlocked`

### `DUMMYSTRUCTNAME.TlpPrefixBlocked`

## Syntax

```cpp
typedef union _PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY {
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
} PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY, *PPCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY;
```

## Remarks

The PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)