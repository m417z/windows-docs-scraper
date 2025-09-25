## Description

The **PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK** union describes a PCI Express (PCIe) uncorrectable error mask register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.Undefined`

A single bit that contains an undefined value. In versions of the *PCIe Specification* prior to version 1.1, this bit indicates that the reporting of link training errors is masked.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.DataLinkProtocolError`

A single bit that indicates that the reporting of data link protocol errors is masked.

### `DUMMYSTRUCTNAME.SurpriseDownError`

A single bit that indicates that the reporting of surprise down errors is masked.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.PoisonedTLP`

A single bit that indicates that the reporting of poisoned transaction layer packets (TLPs) is masked.

### `DUMMYSTRUCTNAME.FlowControlProtocolError`

A single bit that indicates that the reporting of flow control protocol errors is masked.

### `DUMMYSTRUCTNAME.CompletionTimeout`

A single bit that indicates that the reporting of completion timeouts is masked.

### `DUMMYSTRUCTNAME.CompleterAbort`

A single bit that indicates that the reporting of completer aborts is masked.

### `DUMMYSTRUCTNAME.UnexpectedCompletion`

A single bit that indicates that the reporting of unexpected completions is masked.

### `DUMMYSTRUCTNAME.ReceiverOverflow`

A single bit that indicates that the reporting of receiver overflows is masked.

### `DUMMYSTRUCTNAME.MalformedTLP`

A single bit that indicates that the reporting of malformed transaction layer packets (TLPs) is masked.

### `DUMMYSTRUCTNAME.ECRCError`

A single bit that indicates that the reporting of end-to-end cyclic redundancy check (ECRC) errors is masked.

### `DUMMYSTRUCTNAME.UnsupportedRequestError`

A single bit that indicates that the reporting of unsupported request errors is masked.

### `DUMMYSTRUCTNAME.AcsViolation`

Defines the **ULONG** member **AcsViolation**.

### `DUMMYSTRUCTNAME.UncorrectableInternalError`

Defines the **ULONG** member **UncorrectableInternalError**.

### `DUMMYSTRUCTNAME.MCBlockedTlp`

Defines the **ULONG** member **MCBlockedTlp**.

### `DUMMYSTRUCTNAME.AtomicOpEgressBlocked`

Defines the **ULONG** member **AtomicOpEgressBlocked**.

### `DUMMYSTRUCTNAME.TlpPrefixBlocked`

Defines the **ULONG** member **TlpPrefixBlocked**.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK** structure.

## Remarks

The **PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK** structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)