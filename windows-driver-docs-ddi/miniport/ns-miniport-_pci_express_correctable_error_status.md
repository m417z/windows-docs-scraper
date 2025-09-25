## Description

The **PCI_EXPRESS_CORRECTABLE_ERROR_STATUS** union describes a PCI Express (PCIe) correctable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.ReceiverError`

A single bit that indicates that a receiver error has occurred.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.BadTLP`

A single bit that indicates that a bad transaction layer packet (TLP) error has occurred.

### `DUMMYSTRUCTNAME.BadDLLP`

A single bit that indicates that a bad data link layer packet (DLLP) error has occurred.

### `DUMMYSTRUCTNAME.ReplayNumRollover`

A single bit that indicates that the counter that counts the number of times the retry buffer has been re-transmitted has rolled over.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.ReplayTimerTimeout`

A single bit that indicates that the replay timer has timed out.

### `DUMMYSTRUCTNAME.AdvisoryNonFatalError`

A single bit that indicates that an advisory non-fatal error has occurred.

### `DUMMYSTRUCTNAME.CorrectedInternalError`

Defines the **ULONG** member **CorrectedInternalError**.

### `DUMMYSTRUCTNAME.HeaderLogOverflow`

Defines the **ULONG** member **HeaderLogOverflow**.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure.

## Remarks

The PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)