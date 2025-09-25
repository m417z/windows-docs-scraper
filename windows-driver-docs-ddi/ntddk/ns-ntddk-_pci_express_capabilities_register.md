# _PCI_EXPRESS_CAPABILITIES_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_CAPABILITIES_REGISTER structure describes a PCI Express (PCIe) capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_CAPABILITIES_REGISTER structure.

### `DUMMYSTRUCTNAME.CapabilityVersion`

The version number of the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure that contains the PCI_EXPRESS_CAPABILITIES_REGISTER structure.

### `DUMMYSTRUCTNAME.DeviceType`

The type of PCIe logical device. Possible values are:

#### PciExpressEndpoint

A PCIe endpoint device.

#### PciExpressLegacyEndpoint

A legacy PCIe endpoint device.

#### PciExpressRootPort

A root port of a PCIe root complex.

#### PciExpressUpstreamSwitchPort

An upstream port of a PCIe switch.

#### PciExpressDownstreamSwitchPort

A downstream port of a PCIe switch.

#### PciExpressToPciXBridge

A PCIe-to-PCI or PCI-X bridge.

#### PciXToExpressBridge

A PCI- or PCI-X-to PCIe bridge.

#### PciExpressRootComplexIntegratedEndpoint

A PCIe endpoint device that is integrated into the root complex.

#### PciExpressRootComplexEventCollector

A PCIe root complex event collector.

### `DUMMYSTRUCTNAME.InterruptMessageNumber`

The MSI or MSI-X vector that is used for interrupt messages that are generated in association with the status bits in either the slot status register or the root status register of the PCIe capability structure.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `DUMMYSTRUCTNAME.SlotImplemented`

A single bit that indicates that the PCIe link associated with this port is connected to a physical PCIe slot. This member is valid only if the **DeviceType** member is set to **PciExpressRootPort** or **PciExpressDownstreamSwitchPort**.

## Syntax

```cpp
typedef union _PCI_EXPRESS_CAPABILITIES_REGISTER {
  struct {
    USHORT CapabilityVersion  :4;
    USHORT DeviceType  :4;
    USHORT SlotImplemented  :1;
    USHORT InterruptMessageNumber  :5;
    USHORT Rsvd  :2;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_CAPABILITIES_REGISTER, *PPCI_EXPRESS_CAPABILITIES_REGISTER;
```

## Remarks

The PCI_EXPRESS_CAPABILITIES_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_CAPABILITIES_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)