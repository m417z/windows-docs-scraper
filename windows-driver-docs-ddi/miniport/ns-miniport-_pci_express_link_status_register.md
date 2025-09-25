## Description

The **PCI_EXPRESS_LINK_STATUS_REGISTER** union describes a PCI Express (PCIe) link status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.LinkSpeed`

The negotiated link speed of the PCIe link. Possible values are:

| Value | Description |
|--|--|
| **1** | 2.5 gigabits per second. |
| **2** | 5.0 gigabits per second. |
| All other values | Reserved. |

### `DUMMYSTRUCTNAME.LinkWidth`

The negotiated link width (number of lanes) of the PCIe link. Possible values are:

| Value | Description |
|--|--|
| **1** | x1 (1 lane) |
| **2** | x2 (2 lanes) |
| **4** | x4 (4 lanes) |
| **8** | x8 (8 lanes) |
| **12** | x12 (12 lanes) |
| **16** | x16 (16 lanes) |
| **32** | x32 (32 lanes) |
| All other values | Reserved. |

### `DUMMYSTRUCTNAME.Undefined`

Reserved. Device drivers and other system software should ignore any value read from this bit.

### `DUMMYSTRUCTNAME.LinkTraining`

A single bit that indicates that the link is in the configuration or recovery state, or that a 1 was written to the retrain link bit of the PCIe link control register and the training has not yet begun. This member is not applicable to endpoint devices and upstream ports of switches.

### `DUMMYSTRUCTNAME.SlotClockConfig`

A single bit that indicates that the component uses the same physical reference clock that the hardware platform provides on the PCIe slot connector. If this bit is clear, the component uses an independent clock irrespective of the presence of a reference clock on the PCIe slot connector.

### `DUMMYSTRUCTNAME.DataLinkLayerActive`

A single bit that indicates that the data link control and management state machine is in the data link active state.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_LINK_STATUS_REGISTER structure.

## Remarks

The PCI_EXPRESS_LINK_STATUS_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_LINK_STATUS_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)