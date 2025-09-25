# _PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK structure (wdm.h)

## Description

The PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK structure describes a PCI Express (PCIe) uncorrectable error mask register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK structure.

### `DUMMYSTRUCTNAME.CompleterAbort`

A single bit that indicates that the reporting of completer aborts is masked.

### `DUMMYSTRUCTNAME.CompletionTimeout`

A single bit that indicates that the reporting of completion timeouts is masked.

### `DUMMYSTRUCTNAME.DataLinkProtocolError`

A single bit that indicates that the reporting of data link protocol errors is masked.

### `DUMMYSTRUCTNAME.ECRCError`

A single bit that indicates that the reporting of end-to-end cyclic redundancy check (ECRC) errors is masked.

### `DUMMYSTRUCTNAME.FlowControlProtocolError`

A single bit that indicates that the reporting of flow control protocol errors is masked.

### `DUMMYSTRUCTNAME.MalformedTLP`

A single bit that indicates that the reporting of malformed transaction layer packets (TLPs) is masked.

### `DUMMYSTRUCTNAME.PoisonedTLP`

A single bit that indicates that the reporting of poisoned transaction layer packets (TLPs) is masked.

### `DUMMYSTRUCTNAME.ReceiverOverflow`

A single bit that indicates that the reporting of receiver overflows is masked.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `DUMMYSTRUCTNAME.SurpriseDownError`

A single bit that indicates that the reporting of surprise down errors is masked.

### `DUMMYSTRUCTNAME.Undefined`

A single bit that contains an undefined value. In versions of the *PCIe Specification* prior to version 1.1, this bit indicates that the reporting of link training errors is masked.

### `DUMMYSTRUCTNAME.UnexpectedCompletion`

A single bit that indicates that the reporting of unexpected completions is masked.

### `DUMMYSTRUCTNAME.UnsupportedRequestError`

A single bit that indicates that the reporting of unsupported request errors is masked.

### `DUMMYSTRUCTNAME.AcsViolation`

### `DUMMYSTRUCTNAME.UncorrectableInternalError`

### `DUMMYSTRUCTNAME.MCBlockedTlp`

### `DUMMYSTRUCTNAME.AtomicOpEgressBlocked`

### `DUMMYSTRUCTNAME.TlpPrefixBlocked`

## Syntax

```cpp
typedef union _PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK {
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
} PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK, *PPCI_EXPRESS_UNCORRECTABLE_ERROR_MASK;
```

## Remarks

The PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)