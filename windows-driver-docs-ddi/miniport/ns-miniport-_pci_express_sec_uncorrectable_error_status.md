## Description

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS** union describes a PCI Express (PCIe) secondary uncorrectable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that a target abort on split completion has occurred.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that a master abort on split completion has occurred.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that a target abort has been received.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that a master abort has been received.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that an unexpected split completion error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that an uncorrectable split completion message data error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that an uncorrectable data error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that an uncorrectable attribute error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that an uncorrectable address error has occurred.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that the delayed transaction discard timer has expired.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that a PERR# assertion was detected.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that a SERR# assertion was detected.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that an internal bridge error has occurred.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS** structure.

## Remarks

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS** structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)