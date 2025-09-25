# SW_DEVICE_CREATE_INFO structure

## Description

Describes info that PnP uses to create the software device.

## Members

### `cbSize`

The size in bytes of this structure. Use it as a version field. Initialize it to sizeof(SW_DEVICE_CREATE_INFO).

### `pszInstanceId`

A string that represents the [instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/instance-ids) portion of the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). This value is used for [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) **BusQueryInstanceID**. Because all software devices are considered "UniqueId" devices, this string must be a unique name for all devices on this software device enumerator.

### `pszzHardwareIds`

A list of strings for the [hardware IDs](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) for the software device. This value is used for [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) **BusQueryHardwareIDs**. If a client expects a driver package to be installed on the device, the client should specify hardware IDs.

### `pszzCompatibleIds`

A list of strings for the [compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) for the software device. This value is used for [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) **BusQueryCompatibleIDs**. If a client expects a class driver package to be installed on the device, the client specifies compatible IDs that match the class driver package. If a driver package isn't needed, we recommend to specify a compatible ID to classify the type of software device. In addition to the compatible IDs specified in this member, `SWD\Generic` and possibly `SWD\GenericRaw` will always be added as the least specific compatible IDs.

### `pContainerId`

A value that is used to control the base container ID for the software device. This value will be used for [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) **BusQueryContainerIDs**. For typical situations, we recommend to set this member to **NULL** and use the **SWDeviceCapabilitiesRemovable** flag to control whether the device inherits the parent's container ID or if PnP assigns a new random container ID. See [Overview of the removable device capability](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-the-removable-device-capability) for more information on how that affects the assignment of the container ID for the device. If the client needs to explicitly control the container ID, specify a **GUID** in the variable that this member points to. In general, you should not specify NULL_GUID for the container ID. See [Overview of container IDs](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-container-ids) for more information on container IDs and the special meaning of NULL_GUID.

### `CapabilityFlags`

A combination of **SW_DEVICE_CAPABILITIES** values that are combined by using a bitwise OR operation. The resulting value specifies capabilities of the software device. The capabilities that you can specify when you create a software device are a subset of the capabilities that a bus driver can specify by using the [**DEVICE_CAPABILTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure. Only capabilities that make sense to allow changing for a software only device are supported. The rest receive appropriate default values. Here are possible values:

| Value | Meaning |
| --- | --- |
| **SWDeviceCapabilitiesNone**<br><br>0x00000000 | No capabilities have been specified. |
| **SWDeviceCapabilitiesRemovable**<br><br>0x00000001 | This bit specifies that the device is removable from its parent. Setting this flag is equivalent to a bus driver setting the **Removable** member of the [**DEVICE_CAPABILTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure for a PDO. |
| **SWDeviceCapabilitiesSilentInstall**<br><br>0x00000002 | This bit suppresses UI that would normally be shown during installation. Setting this flag is equivalent to a bus driver setting the **SilentInstall** member of the [**DEVICE_CAPABILTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure for a PDO. |
| **SWDeviceCapabilitiesNoDisplayInUI**<br><br>0x00000004 | This bit prevents the device from being displayed in some UI. Setting this flag is equivalent to a bus driver setting the **NoDisplayInUI** member of the [**DEVICE_CAPABILTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure for a PDO. |
| **SWDeviceCapabilitiesDriverRequired**<br><br>0x00000008 | Specify this bit when the client wants a driver to be loaded on the device and when this driver is required for correct function of the client’s feature.<br><br>When this bit is specified, at least one of **pszzHardwareIds** or **pszzCompatibleIds** must be filled in.<br><br> If this bit is specified and if a driver can't be found, the device shows a yellow bang in **Device Manager** to indicate that the device has a problem, and Troubleshooters flag this as a device with a problem. Setting this bit is equivalent to a bus driver not setting the **RawDeviceOK** member of the [**DEVICE_CAPABILTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure for a PDO.<br><br>When this bit is specified, the driver owns creating interfaces for the device, and you can't call [SwDeviceInterfaceRegister](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdeviceinterfaceregister) for the device. |

### `pszDeviceDescription`

A string that contains the text that is displayed for the device name in the UI. This value is used for [IRP_MN_QUERY_DEVICE_TEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-text) **DeviceTextDescription**.

**Note**

When an INF is matched against the device, the name from the INF overrides this name unless steps are taken to preserve this name.

We recommend that this string be a reference to a localizable resource. For the syntax of referencing resources, see [DEVPROP_TYPE_STRING_INDIRECT](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-indirect).

### `pszDeviceLocation`

A string that contains the text that is displayed for the device location in the UI. This value is used for [IRP_MN_QUERY_DEVICE_TEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-text) **DeviceTextLocationInformation**.

**Note** Specifying a location is uncommon.

### `pSecurityDescriptor`

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the security information associated with the software device. If this member is **NULL**, the [I/O Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-i-o-manager) assigns the default security descriptor to the device. If a custom security descriptor is needed, specify a self-relative security descriptor.

## Remarks

You can only specify this info at creation time, and you can't later call the Software Device API to modify this info, by setting properties, for example.

## See also

[SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate)