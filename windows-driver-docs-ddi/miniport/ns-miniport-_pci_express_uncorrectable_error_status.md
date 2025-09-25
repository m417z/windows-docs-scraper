## Description

The PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS union describes a PCI Express (PCIe) uncorrectable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.Undefined`

A single bit that contains an undefined value. In versions of the *PCIe Specification* prior to version 1.1, this bit indicates that a link training error has occurred.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.DataLinkProtocolError`

A single bit that indicates that a data link protocol error has occurred.

### `DUMMYSTRUCTNAME.SurpriseDownError`

A single bit that indicates that a surprise down error has occurred.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.PoisonedTLP`

A single bit that indicates that a poisoned transaction layer packet (TLP) has been detected.

### `DUMMYSTRUCTNAME.FlowControlProtocolError`

A single bit that indicates that a flow control protocol error has occurred.

### `DUMMYSTRUCTNAME.CompletionTimeout`

A single bit that indicates that a completion timeout has occurred.

### `DUMMYSTRUCTNAME.CompleterAbort`

A single bit that indicates that a completer abort has occurred.

### `DUMMYSTRUCTNAME.UnexpectedCompletion`

A single bit that indicates that an unexpected completion has occurred.

### `DUMMYSTRUCTNAME.ReceiverOverflow`

A single bit that indicates that the receiver has overflowed.

### `DUMMYSTRUCTNAME.MalformedTLP`

A single bit that indicates that a malformed transaction layer packet (TLP) has been detected.

### `DUMMYSTRUCTNAME.ECRCError`

A single bit that indicates that an end-to-end cyclic redundancy check (ECRC) error has occurred.

### `DUMMYSTRUCTNAME.UnsupportedRequestError`

A single bit that indicates that an unsupported request error has occurred.

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

A **ULONG** representation of the contents of the **PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS** structure.

## Remarks

The **PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS** structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)