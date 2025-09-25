# _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure (wdm.h)

## Description

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure describes a PCI Express (PCIe) secondary uncorrectable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure.

### `DUMMYSTRUCTNAME.DelayedTransactionDiscardTimerExpired`

A single bit that indicates that the delayed transaction discard timer has expired.

### `DUMMYSTRUCTNAME.InternalBridgeError`

A single bit that indicates that an internal bridge error has occurred.

### `DUMMYSTRUCTNAME.MasterAbortOnSplitCompletion`

A single bit that indicates that a master abort on split completion has occurred.

### `DUMMYSTRUCTNAME.PERRAsserted`

A single bit that indicates that a PERR# assertion was detected.

### `DUMMYSTRUCTNAME.ReceivedMasterAbort`

A single bit that indicates that a master abort has been received.

### `DUMMYSTRUCTNAME.ReceivedTargetAbort`

A single bit that indicates that a target abort has been received.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `DUMMYSTRUCTNAME.RsvdZ`

Reserved for system use.

### `DUMMYSTRUCTNAME.SERRAsserted`

A single bit that indicates that a SERR# assertion was detected.

### `DUMMYSTRUCTNAME.TargetAbortOnSplitCompletion`

A single bit that indicates that a target abort on split completion has occurred.

### `DUMMYSTRUCTNAME.UncorrectableAddressError`

A single bit that indicates that an uncorrectable address error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableAttributeError`

A single bit that indicates that an uncorrectable attribute error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableDataError`

A single bit that indicates that an uncorrectable data error has occurred.

### `DUMMYSTRUCTNAME.UncorrectableSplitCompletion`

A single bit that indicates that an uncorrectable split completion message data error has occurred.

### `DUMMYSTRUCTNAME.UnexpectedSplitCompletionError`

A single bit that indicates that an unexpected split completion error has occurred.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS {
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
} PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS, *PPCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS;
```

## Remarks

The PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)