## Description

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY** union describes a PCI Express (PCIe) secondary uncorrectable error severity register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that a reported target abort on split completion is a fatal error.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that a reported master abort on split completion is a fatal error.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that a reported target abort is a fatal error.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that a reported master abort is a fatal error.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that a reported unexpected split completion error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that a reported uncorrectable split completion message data error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that a reported uncorrectable data error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that a reported uncorrectable attribute error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that a reported uncorrectable address error is a fatal error.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that an expiration of the delayed transaction discard timer is a fatal error.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that a reported PERR# assertion is a fatal error.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that a reported SERR# assertion is a fatal error.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that a reported internal bridge error is a fatal error.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS** structure.

## Remarks

The **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY** structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)