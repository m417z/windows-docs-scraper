## Description

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK** union describes a PCI Express (PCIe) secondary uncorrectable error mask register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that the reporting of target aborts on split completion is masked.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that the reporting of master aborts on split completion is masked.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that the reporting of target aborts is masked.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that the reporting of master aborts is masked.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that the reporting of unexpected split completion errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that the reporting of uncorrectable split completion message data errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that the reporting of uncorrectable data errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that the reporting of uncorrectable attribute errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that the reporting of uncorrectable address errors is masked.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that the reporting of the expiration of the delayed transaction discard timer is masked.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that the reporting of PERR# assertions is masked.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that the reporting of SERR# assertions is masked.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that the reporting of internal bridge errors is masked.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK** structure.

## Remarks

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK** structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)