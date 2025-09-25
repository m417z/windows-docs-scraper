# _PCI_PMCSR structure (wdm.h)

## Description

The PCI_PMCSR structure is used to report the contents of the device's power management control status register.

## Members

### `PowerState`

Indicates the power state of the device. This member can have the following values:

| Value | Meaning |
| --- | --- |
| 0x00 | Indicates that the device is in D0. |
| 0x01 | Indicates that the device is in D1. |
| 0x02 | Indicates that the device is in D2. |
| 0x03 | Indicates that the device is in D3. |

For more information about the power state register, see the *PCI Power Management Specification*.

### `Rsvd1`

Reserved.

### `NoSoftReset`

### `Rsvd2`

### `PMEEnable`

Indicates, when 1, that the device is enabled to assert the PME signal. When 0, the device is not enabled to assert the PME signal. For more information about the meaning of the PME Enable bit, see the *PCI Power Management Specification*.

### `DataSelect`

Indicates which data is to be reported through the data register. For more information about the values that this member can hold, see the *PCI Power Management Specification*.

### `DataScale`

Indicates the scaling factor used to interpret the value of the data register. For more information about the values that this member can hold, see the *PCI Power Management Specification*.

### `PMEStatus`

Contains a one-bit value (either 0 or 1) that reports the value of the PMEStatus bit in the power management register. For more information about the values that this member can hold, see the *PCI Power Management Specification*.

## Syntax

```cpp
typedef struct _PCI_PMCSR {
  USHORT PowerState  :2;
  USHORT Rsvd1  :6;
  USHORT PMEEnable  :1;
  USHORT DataSelect  :4;
  USHORT DataScale  :2;
  USHORT PMEStatus  :1;
} PCI_PMCSR, *PPCI_PMCSR;
```

## See also

[PCI_PM_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pm_capability)