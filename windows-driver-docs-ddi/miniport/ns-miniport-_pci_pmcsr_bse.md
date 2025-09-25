# _PCI_PMCSR_BSE structure (miniport.h)

## Description

The PCI_PMCSR_BSE structure is used to report the contents of the power management control status register for PCI bridge support extensions.

## Members

### `Rsvd1`

Reserved.

### `D3HotSupportsStopClock`

Indicates how the power state of a secondary bus is affected when the primary bus transitions to a D3 power state. For a detailed explanation of the values in this member and how they affect the relationship between the primary and secondary buses, see the *PCI Power Management Specification*.

### `BusPowerClockControlEnabled`

Indicates, when 1, that the bus's power clock control mechanism is enabled. A value of 0 indicates that the bus power clock control mechanism is disabled. For a detailed explanation of the meaning of this member, see the *PCI Power Management Specification*.

## Syntax

```cpp
typedef struct _PCI_PMCSR_BSE {
  UCHAR Rsvd1;
  UCHAR D3HotSupportsStopClock;
  UCHAR BusPowerClockControlEnabled;
} PCI_PMCSR_BSE, *PPCI_PMCSR_BSE;
```

## See also

[PCI_PM_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pm_capability)