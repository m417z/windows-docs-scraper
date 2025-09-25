# _PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure (wdm.h)

## Description

The PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure describes a PCI Express (PCIe) correctable error status register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.AdvisoryNonFatalError`

A single bit that indicates that an advisory non-fatal error has occurred.

### `DUMMYSTRUCTNAME.BadDLLP`

A single bit that indicates that a bad data link layer packet (DLLP) error has occurred.

### `DUMMYSTRUCTNAME.BadTLP`

A single bit that indicates that a bad transaction layer packet (TLP) error has occurred.

### `DUMMYSTRUCTNAME.ReceiverError`

A single bit that indicates that a receiver error has occurred.

### `DUMMYSTRUCTNAME.ReplayNumRollover`

A single bit that indicates that the counter that counts the number of times the retry buffer has been re-transmitted has rolled over.

### `DUMMYSTRUCTNAME.ReplayTimerTimeout`

A single bit that indicates that the replay timer has timed out.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved.

### `DUMMYSTRUCTNAME.CorrectedInternalError`

### `DUMMYSTRUCTNAME.HeaderLogOverflow`

### `DUMMYSTRUCTNAME.Reserved3`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure.

## Syntax

```cpp
typedef union _PCI_EXPRESS_CORRECTABLE_ERROR_STATUS {
  struct {
    ULONG ReceiverError  :1;
    ULONG Reserved1  :5;
    ULONG BadTLP  :1;
    ULONG BadDLLP  :1;
    ULONG ReplayNumRollover  :1;
    ULONG Reserved2  :3;
    ULONG ReplayTimerTimeout  :1;
    ULONG AdvisoryNonFatalError  :1;
    ULONG Reserved3  :18;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_CORRECTABLE_ERROR_STATUS, *PPCI_CORRECTABLE_ERROR_STATUS;
```

## Remarks

The PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_CORRECTABLE_ERROR_STATUS structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)