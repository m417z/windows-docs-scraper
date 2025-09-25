# _PCI_EXPRESS_LINK_STATUS_REGISTER structure (ntddk.h)

## Description

The **PCI_EXPRESS_LINK_STATUS_REGISTER** structure describes a PCI Express (PCIe) link status register of a PCIe capability structure.

## Syntax

```cpp
typedef union _PCI_EXPRESS_LINK_STATUS_REGISTER {

    struct {

        USHORT LinkSpeed:4;
        USHORT LinkWidth:6;
        USHORT Undefined:1;
        USHORT LinkTraining:1;
        USHORT SlotClockConfig:1;
        USHORT DataLinkLayerActive:1;
        USHORT Rsvd:2;
    } DUMMYSTRUCTNAME;

    USHORT AsUSHORT;

} PCI_EXPRESS_LINK_STATUS_REGISTER, *PPCI_EXPRESS_LINK_STATUS_REGISTER;
```

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_LINK_STATUS_REGISTER** structure.

### `DUMMYSTRUCTNAME.DataLinkLayerActive`

A single bit that indicates that the data link control and management state machine is in the data link active state.

### `DUMMYSTRUCTNAME.LinkSpeed`

The negotiated link speed of the PCIe link. The encoded value specifies a Bit Location in the SupportedLinkSpeedsVector (Link Capabilities 2 Register) that corresponds to the negotiated link speed. Supported values are:

| Value | Description |
| --- | --- |
| **1** | 2.5 GT/s (SupportedLinkSpeedsVector field bit 0) |
| **2** | 5.0 GT/s (SupportedLinkSpeedsVector field bit 1) |
| **3** | 8.0 GT/s (SupportedLinkSpeedsVector field bit 2) |
| **4** | 16.0 GT/s (SupportedLinkSpeedsVector field bit 3) |
| **5** | 32.0 GT/s (SupportedLinkSpeedsVector field bit 4) |
| All other values | Reserved. |

### `DUMMYSTRUCTNAME.LinkTraining`

A single bit that indicates that the link is in the configuration or recovery state, or that a 1 was written to the retrain link bit of the PCIe link control register and the training has not yet begun. This member is not applicable to endpoint devices and upstream ports of switches.

### `DUMMYSTRUCTNAME.LinkWidth`

The negotiated link width (number of lanes) of the PCIe link. Possible values are:

| Value | Description |
| --- | --- |
| **1** | x1 (1 lane) |
| **2** | x2 (2 lanes) |
| **4** | x4 (4 lanes) |
| **8** | x8 (8 lanes) |
| **12** | x12 (12 lanes) |
| **16** | x16 (16 lanes) |
| **32** | x32 (32 lanes) |
| All other values | Reserved. |

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `DUMMYSTRUCTNAME.SlotClockConfig`

A single bit that indicates that the component uses the same physical reference clock that the hardware platform provides on the PCIe slot connector. If this bit is clear, the component uses an independent clock irrespective of the presence of a reference clock on the PCIe slot connector.

### `DUMMYSTRUCTNAME.Undefined`

Reserved. Device drivers and other system software should ignore any value read from this bit.

## Syntax

```cpp
typedef union _PCI_EXPRESS_LINK_STATUS_REGISTER {
  struct {
    USHORT LinkSpeed  :4;
    USHORT LinkWidth  :6;
    USHORT Undefined  :1;
    USHORT LinkTraining  :1;
    USHORT SlotClockConfig  :1;
    USHORT DataLinkLayerActive  :1;
    USHORT Rsvd  :2;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_LINK_STATUS_REGISTER, *PPCI_EXPRESS_LINK_STATUS_REGISTER;
```

## Remarks

The **PCI_EXPRESS_LINK_STATUS_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_LINK_STATUS_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[PCI_EXPRESS_LINK_STATUS_2_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-pci_express_link_status_2_register)