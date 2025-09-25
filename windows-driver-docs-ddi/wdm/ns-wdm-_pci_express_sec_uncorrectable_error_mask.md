# _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK structure (wdm.h)

## Description

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK structure describes a PCI Express (PCIe) secondary uncorrectable error mask register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK structure.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that the reporting of the expiration of the delayed transaction discard timer is masked.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that the reporting of internal bridge errors is masked.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that the reporting of master aborts on split completion is masked.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that the reporting of PERR# assertions is masked.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that the reporting of master aborts is masked.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that the reporting of target aborts is masked.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved for system use.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that the reporting of SERR# assertions is masked.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that the reporting of target aborts on split completion is masked.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that the reporting of uncorrectable address errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that the reporting of uncorrectable attribute errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that the reporting of uncorrectable data errors is masked.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that the reporting of uncorrectable split completion message data errors is masked.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that the reporting of unexpected split completion errors is masked.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK {
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
} PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK, *PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK;
```

## Remarks

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)