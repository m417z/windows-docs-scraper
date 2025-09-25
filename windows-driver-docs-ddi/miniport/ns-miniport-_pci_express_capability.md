## Description

The **PCI_EXPRESS_CAPABILITY** structure describes a PCI Express (PCIe) capability structure.

## Members

### `Header`

A [**PCI_CAPABILITIES_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header) structure that describes the PCI capabilities header of the PCIe capability structure.

### `ExpressCapabilities`

A [**PCI_EXPRESS_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capabilities_register) structure that describes the PCIe capabilities register of the PCIe capability structure.

### `DeviceCapabilities`

A [**PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_capabilities_register) structure that describes the PCIe device capabilities register of the PCIe capability structure.

### `DeviceControl`

A [**PCI_EXPRESS_DEVICE_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_control_register) structure that describes the PCIe device control register of the PCIe capability structure.

### `DeviceStatus`

A [**PCI_EXPRESS_DEVICE_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_status_register) structure that describes the PCIe device status register of the PCIe capability structure.

### `LinkCapabilities`

A [**PCI_EXPRESS_LINK_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_capabilities_register) structure that describes the PCIe link capabilities register of the PCIe capability structure.

### `LinkControl`

A [**PCI_EXPRESS_LINK_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_control_register) structure that describes the PCIe link control register of the PCIe capability structure.

### `LinkStatus`

A [**PCI_EXPRESS_LINK_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_status_register) structure that describes the PCIe link status register of the PCIe capability structure.

### `SlotCapabilities`

A [**PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_capabilities_register) structure that describes the PCIe slot capabilities register of the PCIe capability structure.

### `SlotControl`

A [**PCI_EXPRESS_SLOT_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_control_register) structure that describes the PCIe slot control register of the PCIe capability structure.

### `SlotStatus`

A [**PCI_EXPRESS_SLOT_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_status_register) structure that describes the PCIe slot status register of the PCIe capability structure.

### `RootControl`

A [**PCI_EXPRESS_ROOT_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_control_register) structure that describes the PCIe root control register of the PCIe capability structure.

### `RootCapabilities`

A [**PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_capabilities_register) structure that describes the PCIe root capabilities register of the PCIe capability structure.

### `RootStatus`

A [**PCI_EXPRESS_ROOT_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_status_register) structure that describes the PCIe root status register of the PCIe capability structure.

### `DeviceCapabilities2`

A **PCI_EXPRESS_DEVICE_CAPABILITIES_2_REGISTER** structure that describes the PCIe device capabilities 2 register of the PCIe capability structure.

### `DeviceControl2`

A **PCI_EXPRESS_DEVICE_CONTROL_2_REGISTER** structure that describes the PCIe device control 2 register of the PCIe capability structure.

### `DeviceStatus2`

A **PCI_EXPRESS_DEVICE_STATUS_2_REGISTER** structure that describes the PCIe device status 2 register of the PCIe capability structure.

### `LinkCapabilities2`

Defines the **PCI_EXPRESS_LINK_CAPABILITIES_2_REGISTER** member **LinkCapabilities2**.

### `LinkControl2`

Defines the **PCI_EXPRESS_LINK_CONTROL_2_REGISTER** member **LinkControl2**.

### `LinkStatus2`

Defines the **PCI_EXPRESS_LINK_STATUS_2_REGISTER** member **LinkStatus2**.

## Remarks

For additional information about the PCIe capability structure, see the [PCI Express Specification](https://pcisig.com/specifications/pciexpress).

## See also

[**PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_capabilities_register)

[**PCI_EXPRESS_LINK_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_capabilities_register)

[**PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_capabilities_register)

[**PCI_EXPRESS_ROOT_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_status_register)

[**PCI_EXPRESS_ROOT_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_control_register)

[**PCI_EXPRESS_DEVICE_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_control_register)

[**PCI_EXPRESS_DEVICE_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_device_status_register)

[**PCI_EXPRESS_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capabilities_register)

[**PCI_CAPABILITIES_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header)

[**PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_capabilities_register)

[**PCI_EXPRESS_LINK_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_status_register)

[**PCI_EXPRESS_SLOT_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_control_register)

[**PCI_EXPRESS_LINK_CONTROL_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_link_control_register)

[**PCI_EXPRESS_SLOT_STATUS_REGISTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_slot_status_register)