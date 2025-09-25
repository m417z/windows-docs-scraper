# _NDIS_PCI_DEVICE_CUSTOM_PROPERTIES structure

## Description

The NDIS_PCI_DEVICE_CUSTOM_PROPERTIES structure defines the type and speed of the PCI bus that a NIC
is running on.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PCI_DEVICE_CUSTOM_PROPERTIES structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_OBJECT_TYPE_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_1, and the
**Size** member to
sizeof(NDIS_PCI_DEVICE_CUSTOM_PROPERTIES).

### `DeviceType`

The PCI device type. For example, conventional, PCI-X, PCI-E, and so on. See the definitions for
DevProp_PciDevice_DeviceType_xxx in pciprop.h.

### `CurrentSpeedAndMode`

The speed and mode of conventional PCI or PCI-X devices. For conventional PCI devices, see the
definitions for DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_xxx. For PCI-X devices, see the
definitions for DevProp_PciDevice_CurrentSpeedAndMode_Pci_X_xxx. This property is valid only for
conventional PCI and PCI-X devices.

### `CurrentPayloadSize`

The current payload size in the transaction layer for a PCI Express device. See definitions for
DevProp_PciExpressDevice_PayloadOrRequestSize_xxx. This property is valid only for PCI Express
devices.

### `MaxPayloadSize`

The maximum payload size in the transaction layer that is supported by a PCI Express device. See
definitions for DevProp_PciExpressDevice_PayloadOrRequestSize_xxx. This property is valid only for PCI
Express devices.

### `MaxReadRequestSize`

The maximum read request size for a PCI Express device. See definitions for
DevProp_PciExpressDevice_PayloadOrRequestSize_xxx. This property is valid only for PCI Express
devices..

### `CurrentLinkSpeed`

The current link speed for the device. This property is applicable to a PCI Express device. See
the definitions for DevProp_PciExpressDevice_LinkSpeed_xxx. This property is valid only for PCI Express
devices.

### `CurrentLinkWidth`

The current link width of the device. This property is applicable to a PCI express device. See the
definitions for DevProp_PciExpressDevice_LinkWidth_xxx. This property is valid only for PCI Express
devices.

### `MaxLinkSpeed`

The maximum link speed of an express link for a PCI Express device. See the definitions for
DevProp_PciExpressDevice_LinkSpeed_xxx. This property is valid only for PCI Express devices..

### `MaxLinkWidth`

The maximum link width that is implemented by an express link for a PCI Express device. See the
definitions for DevProp_PciExpressDevice_LinkWidth_xxx. This property is valid only for PCI Express
devices.

### `PciExpressVersion`

The specification version to which an PCI Express device was built. See the definitions for
DevProp_PciExpressDevice_Spec_Version_xxx. This property is valid only for PCI Express devices.

### `InterruptType`

The hardware support for interrupts on the PCI Express device. See the definitions for
DevProp_PciDevice_InterruptType_xxx. This property is valid only for PCI Express devices.

### `MaxInterruptMessages`

The number of message interrupts that a PCI Express device supports in hardware. See the
definition for DevProp_PciDevice_InterruptMessageMaximum. This property is valid only for PCI Express
devices that support message interrupts.

## Remarks

Some high performance miniport adapters can adjust the hardware configuration and resource allocation
based on the type and speed of the PCI bus that the NIC is running on. To provide miniport drivers with
this information during initialization, NDIS queries the custom PCI properties of PCI adapters and
provides the results in
**PciDeviceCustomProperties** member of the
[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure. The type and speed of the PCI bus is also available
through the
[OID_GEN_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-pci-device-custom-properties) OID request and the
[GUID_NDIS_GEN_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pci_device_custom_properties) WMI GUID.

## See also

[GUID_NDIS_GEN_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pci_device_custom_properties)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_GEN_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-pci-device-custom-properties)