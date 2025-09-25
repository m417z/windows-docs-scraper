# DEVICE_REGISTRY_PROPERTY enumeration

## Description

The **DEVICE_REGISTRY_PROPERTY** enumeration identifies device properties that are stored in the registry.

## Constants

### `DevicePropertyDeviceDescription`

String describing the device, such as "Microsoft PS/2 Port Mouse", typically defined by the manufacturer. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyHardwareID`

[Hardware IDs](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) provided by the device that identify the device. Property type is a REG_MULTI_SZ value.

### `DevicePropertyCompatibleIDs`

[Compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) reported by the device. Property type is a REG_MULTI_SZ value.

### `DevicePropertyBootConfiguration`

Hardware resources assigned to the device by the firmware, in raw form. Property type is a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure.

### `DevicePropertyBootConfigurationTranslated`

The hardware resources assigned to the device by the firmware, in translated form. Property type is a **CM_RESOURCE_LIST** structure.

### `DevicePropertyClassName`

Name of the device's setup class, in text format. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyClassGuid`

GUID for the device's setup class. Property type is a NULL-terminated array of WCHAR.

The GUID in a string format as follows, where each "c" represents a hexadecimal character: {cccccccc-cccc-cccc-cccc-cccccccccccc}

### `DevicePropertyDriverKeyName`

Name of the driver-specific registry key. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyManufacturer`

String identifying the manufacturer of the device. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyFriendlyName`

String that can be used to distinguish between two similar devices, typically defined by the class installer. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyLocationInformation`

Information about the device's location on the bus; the interpretation of this information is bus-specific. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyPhysicalDeviceObjectName`

Name of the PDO for this device. Property type is a NULL-terminated WCHAR string.

### `DevicePropertyBusTypeGuid`

GUID for the bus that the device is connected to. The system-defined bus type GUIDs are listed in the `Wdmguid.h` header file. Property type is a GUID, which is a 16-byte structure that contains the GUID in binary form.

### `DevicePropertyLegacyBusType`

Requests the bus type, such as PCIBus or PCMCIABus. Property type is an [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type) enumeration value.

### `DevicePropertyBusNumber`

Legacy bus number of the bus the device is connected to. Property type is a ULONG.

### `DevicePropertyEnumeratorName`

Name of the enumerator for the device, such as "PCI" or "root". Property type is a NULL-terminated WCHAR string.

### `DevicePropertyAddress`

Address of the device on the bus. Property type is a ULONG.

The interpretation of this address is bus-specific. The caller of this routine should call the routine again to request the **DevicePropertyBusTypeGuid**, or possibly the **DevicePropertyLegacyBusType**, so it can interpret the address. An address value of 0xFFFFFFFF indicates that the underlying bus driver did not supply a bus address for the device.

See *Remarks* for additional bus driver-specific information.

### `DevicePropertyUINumber`

Number associated with the device that can be displayed in the user interface. Property type is a ULONG value.

This number is typically a user-perceived slot number, such as a number printed next to the slot on the board, or some other number that makes locating the physical device easier for the user. If the device is on a bus that has no UI number convention, or if the bus driver for the device can't determine the UI number, this value is 0xFFFFFFFF.

### `DevicePropertyInstallState`

Device's installation state. Property type is a [DEVICE_INSTALL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_install_state) enumeration value.

### `DevicePropertyRemovalPolicy`

Device's current removal policy. The operating system uses this value as a hint to determine how the device is normally removed. Property type is a [DEVICE_REMOVAL_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_removal_policy) enumeration value.

### `DevicePropertyResourceRequirements`

Device's resource requirements. Property type is an [IO_RESOURCE_REQUIREMENTS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_requirements_list) structure.

### `DevicePropertyAllocatedResources`

Device's allocated resources. Property type is a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure.

### `DevicePropertyContainerID`

Device's container ID. Property type is a NULL-terminated WCHAR string.

## Remarks

For the **DevicePropertyAddress** value, the following list describes the information that certain bus drivers store for their child devices:

| Bus | Description |
|-----|-------------|
| 1394 | Does not supply an address because the addresses are volatile. Defaults to 0xFFFFFFFF. |
| EISA | Slot Number (0-F). |
| IDE | For an IDE device, the address contains the target ID and LUN. For an IDE channel, the address is zero or one (0 = primary channel and 1 = secondary channel). |
| ISApnp | Does not supply an address. Defaults to 0xFFFFFFFF. |
| PC Card (PCMCIA) | The socket number (typically 0x00 or 0x40). |
| PCI | The device number in the high word and the function number in the low word. |
| SCSI | The target ID. |
| USB | The port number. |

## See also

[**IoGetDeviceProperty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)