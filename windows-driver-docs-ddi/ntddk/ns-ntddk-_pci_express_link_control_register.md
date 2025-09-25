# _PCI_EXPRESS_LINK_CONTROL_REGISTER structure (ntddk.h)

## Description

The **PCI_EXPRESS_LINK_CONTROL_REGISTER** structure describes a PCI Express (PCIe) link control register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_LINK_CONTROL_REGISTER** structure.

### `DUMMYSTRUCTNAME.ActiveStatePMControl`

The level of active state power management that is enabled on the PCIe link. Possible values are:

| Value | Description |
| --- | --- |
| **L0sAndL1EntryDisabled** | L0s and L1 are both disabled. |
| **L0sEntryEnabled** | L0s is enabled. |
| **L1EntryEnabled** | L1 is enabled. |
| **L0sAndL1EntryEnabled** | L0s and L1 are both enabled. |

### `DUMMYSTRUCTNAME.CommonClockConfig`

A single bit that indicates that this component and the component at the opposite end of the link are operating with a distributed common reference clock. If this bit is clear, this component and the component at the opposite end of the link are operating with an asynchronous reference clock.

### `DUMMYSTRUCTNAME.EnableClockPowerManagement`

A single bit that indicates that clock power management is enabled.

### `DUMMYSTRUCTNAME.ExtendedSynch`

A single bit that indicates that additional ordered sets are transmitted when exiting the L0s state and when in the recovery state.

### `DUMMYSTRUCTNAME.LinkDisable`

A single bit that indicates that the link is disabled. This member is not applicable for endpoint devices, PCIe-to-PCI or PCI-X bridges, and upstream ports of switches.

### `DUMMYSTRUCTNAME.ReadCompletionBoundary`

The read completion boundary (RCB) value for the root port or the root port upstream from the endpoint. If the bit is clear, the RCB is 64 byte. If the bit is set, the RCB is 128 byte. This member is not applicable for switch ports.

### `DUMMYSTRUCTNAME.RetrainLink`

A single bit that is used to initiate retraining of the link. Reads of this bit always return zero. This member is not applicable for endpoint devices, PCIe-to-PCI or PCI-X bridges, and upstream ports of switches.

### `DUMMYSTRUCTNAME.Rsvd1`

Reserved.

### `DUMMYSTRUCTNAME.Rsvd2`

Reserved.

## Syntax

```cpp
typedef union _PCI_EXPRESS_LINK_CONTROL_REGISTER {
  struct {
    USHORT ActiveStatePMControl  :2;
    USHORT Rsvd1  :1;
    USHORT ReadCompletionBoundary  :1;
    USHORT LinkDisable  :1;
    USHORT RetrainLink  :1;
    USHORT CommonClockConfig  :1;
    USHORT ExtendedSynch  :1;
    USHORT EnableClockPowerManagement  :1;
    USHORT Rsvd2  :7;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_LINK_CONTROL_REGISTER, *PPCI_EXPRESS_LINK_CONTROL_REGISTER;
```

## Remarks

The **PCI_EXPRESS_LINK_CONTROL_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_LINK_CONTROL_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[PCI_EXPRESS_LINK_CONTROL_2_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-pci_express_link_control_2_register)