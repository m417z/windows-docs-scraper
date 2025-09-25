## Description

The PCI_EXPRESS_CORRECTABLE_ERROR_MASK union describes a PCI Express (PCIe) correctable error mask register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.ReceiverError`

A single bit that indicates that the reporting of receiver errors is masked.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.BadTLP`

A single bit that indicates that the reporting of bad transaction layer packets (TLPs) is masked.

### `DUMMYSTRUCTNAME.BadDLLP`

A single bit that indicates that the reporting of bad data link layer packets (DLLPs) is masked.

### `DUMMYSTRUCTNAME.ReplayNumRollover`

A single bit that indicates that the reporting of rollovers of the counter that counts the number of times the retry buffer has been re-transmitted is masked.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.ReplayTimerTimeout`

A single bit that indicates that the reporting of timeouts of the replay timer is masked.

### `DUMMYSTRUCTNAME.AdvisoryNonFatalError`

A single bit that indicates that the reporting of advisory non-fatal errors is masked.

### `DUMMYSTRUCTNAME.CorrectedInternalError`

Defines the **ULONG** member **CorrectedInternalError**.

### `DUMMYSTRUCTNAME.HeaderLogOverflow`

Defines the **ULONG** member **HeaderLogOverflow**.

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_CORRECTABLE_ERROR_MASK union.

## Remarks

The PCI_EXPRESS_CORRECTABLE_ERROR_MASK structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_CORRECTABLE_ERROR_MASK structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)