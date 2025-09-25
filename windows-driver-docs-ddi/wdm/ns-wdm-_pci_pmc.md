# _PCI_PMC structure (wdm.h)

## Description

The PCI_PMC structure is used to report the contents of the power management capabilities register.

## Members

### `Version`

Contains a 3-bit integer that indicates the version of the *PCI Power Management Interface Specification* that the device complies with. For a list of values that can be assigned to this member, see the *PCI Local Bus Specification*.

### `PMEClock`

Indicates, when 1, that the device relies on the presence of the PCI clock for operation of the PME signal. When this member is a "0", no PCI clock is required to generate the PME signal.

### `Rsvd1`

Reserved.

### `DeviceSpecificInitialization`

Indicates when 1 that the device requires a special initialization. For more information about this value, see the *PCI Local Bus Specification*.

### `Rsvd2`

Reserved.

### `Support`

### `Support.Rsvd2`

Reserved.

### `Support.D1`

Reserved.

### `Support.D2`

Reserved.

### `Support.PMED0`

Indicates that the device can assert the PME signal from D0.

### `Support.PMED1`

Indicates that the device can assert the PME signal from D1.

### `Support.PMED2`

Indicates that the device can assert the PME signal from D2.

### `Support.PMED3Hot`

Indicates that the device can assert the PME signal from D3.

### `Support.PMED3Cold`

Indicates that the device can assert the PME signal from D3.

### `_PM_SUPPORT`

## Syntax

```cpp
typedef struct _PCI_PMC {
  UCHAR              Version  :3;
  UCHAR              PMEClock  :1;
  UCHAR              Rsvd1  :1;
  UCHAR              DeviceSpecificInitialization  :1;
  UCHAR              Rsvd2  :2;
  struct _PM_SUPPORT {
    UCHAR Rsvd2  :1;
    UCHAR D1  :1;
    UCHAR D2  :1;
    UCHAR PMED0  :1;
    UCHAR PMED1  :1;
    UCHAR PMED2  :1;
    UCHAR PMED3Hot  :1;
    UCHAR PMED3Cold  :1;
  } Support;
} PCI_PMC, *PPCI_PMC;
```

## Remarks

The power management capabilities register, whose contents are reported in the PCI_PMC structure, provides information about the power management capabilities of the device.

## See also

[PCI_PM_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pm_capability)