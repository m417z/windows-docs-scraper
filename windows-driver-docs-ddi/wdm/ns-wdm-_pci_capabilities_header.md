# _PCI_CAPABILITIES_HEADER structure (wdm.h)

## Description

The PCI_CAPABILITIES_HEADER structure defines a header that is present in every PCI capability structure.

## Members

### `CapabilityID`

Contains an 8-bit integer that indicates the capability ID. The capability ID identifies the type of capability structure that follows this header. The **CapabilityID** member must have one of the following values:

| Capability ID | Meaning |
| --- | --- |
| PCI_CAPABILITY_ID_POWER_MANAGEMENT | Indicates that the capability structure that follows the header defines a PCI power management interface. For more information about this kind of capability, see the *PCI Power Management Interface Specificatio*n. |
| PCI_CAPABILITY_ID_AGP | Indicates that the capability structure that follows the header defines the Accelerated Graphics Port (AGP) supported by the device. For more information about this kind of capability, see the *Accelerated Graphics Port Interface Specification.* |
| PCI_CAPABILITY_ID_VPD | Indicates that the capability structure that follows the header defines Vital Product Data (VPD) features of the device. |
| PCI_CAPABILITY_ID_SLOT_ID | Indicates that the capability structure that follows the header defines external expansion capabilities of a bridge device. For more information about this kind of capability, see the *PCI to PCI Bridge Architecture Specificatio*n. |
| PCI_CAPABILITY_ID_MSI | Indicates that the capability structure that follows the header defines a *PCI device* that can do message signaled interrupt (MSI) delivery. For more information about the MSI capability, see the *PCI Local Bus Specification*. |
| PCI_CAPABILITY_ID_CPCI_HOTSWAP | Indicates that the capability structure that follows the header defines a standard interface to control and sense status. Devices that supports hot swap insertion and extraction in a CompactPCI system require this kind of interface. For more information about control and sense status in CompactPCI systems, see the *CompactPCI Hot Swap Specification*. |
| PCI_CAPABILITY_ID_PCIX | Indicates that the capability structure that follows the header defines the devices PCI-X features. For more information about PCI-X, see the *PCI-X Addendum to the PCI Local Bus Specification*. |
| PCI_CAPABILITY_ID_HYPERTRANSPORT | Indicates that the capability structure that follows the header defines control and status for devices that implement hyper transport (HT) technology links. For more information about HT technology, refer to the *HyperTransport I/O Link Specification*. |
| PCI_CAPABILITY_ID_VENDOR_SPECIFIC | Indicates that the capability structure that follows the header defines vendor specific information. For more information about how to use the capability mechanism to communicate vendor-specific information, see the *PCI Local Bus Specification*. |
| PCI_CAPABILITY_ID_DEBUG_PORT | Indicates that the capability structure that follows the header describes a debug port |
| PCI_CAPABILITY_ID_CPCI_RES_CTRL | Indicates that the capability structure that follows the header describes CompactPCI central resource control. For more information about this kind of control see the *PICMG 2.13 Specification*. |
| PCI_CAPABILITY_ID_SHPC | Indicates that the capability structure that follows the header defines the features of a device that conforms to the standard hot-plug controller model. |
| PCI_CAPABILITY_ID_P2P_SSID | Indicates that the capability structure that follows the header defines the subsystem ID capability. |
| PCI_CAPABILITY_ID_AGP_TARGET | Indicates that the capability structure that follows the header defines the Accelerated Graphics Port (AGP) 8x capability. |
| PCI_CAPABILITY_ID_SECURE | Indicates that the capability structure that follows the header describes a secure device |
| PCI_CAPABILITY_ID_PCI_EXPRESS | Indicates that the capability structure that follows the header defines a device that supports PCI express. |
| PCI_CAPABILITY_ID_MSIX | Indicates that the capability structure that follows the header defines an optional extension to the basic MSI functionality. |

### `Next`

Contains an offset into the PCI configuration space that indicates the location of the next item in the capability list. If there are no additional items in the list, this member will contain zero.

## Syntax

```cpp
typedef struct _PCI_CAPABILITIES_HEADER {
  UCHAR CapabilityID;
  UCHAR Next;
} PCI_CAPABILITIES_HEADER, *PPCI_CAPABILITIES_HEADER;
```

## Remarks

All PCI Capability structures have the header described by PCI_CAPABILITIES_HEADER.

## See also

[PCI_PMCSR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr)

[PCI_PMC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmc)

[PCI_PMCSR_BSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_pmcsr_bse)