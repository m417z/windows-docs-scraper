# _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY structure (wdm.h)

## Description

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY structure describes a PCI Express (PCIe) secondary uncorrectable error severity register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that an expiration of the delayed transaction discard timer is a fatal error.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that a reported internal bridge error is a fatal error.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that a reported master abort on split completion is a fatal error.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that a reported PERR# assertion is a fatal error.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that a reported master abort is a fatal error.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that a reported target abort is a fatal error.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved for system use.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that a reported SERR# assertion is a fatal error.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that a reported target abort on split completion is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that a reported uncorrectable address error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that a reported uncorrectable attribute error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that a reported uncorrectable data error is a fatal error.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that a reported uncorrectable split completion message data error is a fatal error.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that a reported unexpected split completion error is a fatal error.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY {
  struct {
    ULONG TargetAbortOnSplitCompletion  :1;
    ULONG MasterAbortOnSplitCompletion  :1;
    ULONG ReceivedTargetAbort  :1;
    ULONG ReceivedMasterAbort  :1;
    ULONG RsvdZ  :1;
    ULONG UnexpectedSplitCompletionError  :1;
    ULONG UncorrectableSplitCompletion  :1;
    ULONG UncorrectableDataError  :1;
    ULONG UncorrectableAttributeError  :1;
    ULONG UncorrectableAddressError  :1;
    ULONG DelayedTransactionDiscardTimerExpired  :1;
    ULONG PERRAsserted  :1;
    ULONG SERRAsserted  :1;
    ULONG InternalBridgeError  :1;
    ULONG Reserved  :18;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY, *PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY;
```

## Remarks

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)