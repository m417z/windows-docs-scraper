# _PCI_PM_CAPABILITY structure (wdm.h)

## Description

The PCI_PM_CAPABILITY structure reports the power management capabilities of the device.

## Members

### `Header`

Contains a structure of type [PCI_CAPABILITIES_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header) that identifies the capability and provides a link to the next capability description.

### `PMC`

#### `PMC.Capabilities`

Contains a structure of type [PCI_PMC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmc) that specifies the power management capabilities of the device. This information was retrieved from the power management capabilities register (offset 2 in the power management register block). For more information about the contents of the power management capabilities register, see the *PCI Power Management Specification*.

### `PMC.AsUSHORT`

Contains the same data as the **Capabilities** member.

### `PMCSR`

### `PMCSR.ControlStatus`

Contains a structure of type [PCI_PMCSR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr) that reports the contents of the power management control status register. This register is used to monitor power management event signals and manage the device's power state. For more information about the contents of the power management control status register, see the *PCI Power Management Specification*.

### `PMCSR.AsUSHORT`

Contains the same data as the **Capabilities** member.

### `PMCSR_BSE`

### `PMCSR_BSE.BridgeSupport`

Contains a structure of type [PCI_PMCSR_BSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr_bse) that reports the contents of the power management control status register for PCI bridge support extensions.

### `PMCSR_BSE.AsUCHAR`

Contains the same data as the **BridgeSupport** member.

### `Data`

Holds the contents of an optional data register that the device uses to report state-dependent operating data, such as heat dissipation or how much power the device has consumed.

## Syntax

```cpp
typedef struct _PCI_PM_CAPABILITY {
  PCI_CAPABILITIES_HEADER Header;
  union {
    PCI_PMC Capabilities;
    USHORT  AsUSHORT;
  } PMC;
  union {
    PCI_PMCSR ControlStatus;
    USHORT    AsUSHORT;
  } PMCSR;
  union {
    PCI_PMCSR_BSE BridgeSupport;
    UCHAR         AsUCHAR;
  } PMCSR_BSE;
  UCHAR                   Data;
} PCI_PM_CAPABILITY, *PPCI_PM_CAPABILITY;
```

## See also

[PCI_PMCSR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr)

[PCI_CAPABILITIES_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header)

[PCI_PMC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmc)

[PCI_PMCSR_BSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr_bse)