# _HUB_INFO_FROM_PARENT structure

## Description

Describes information about a hub from its parent device.

## Members

### `IoTarget`

A pointer to the WDM device object of the parent that represents the I/O target.

### `DeviceDescriptor`

A [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure that contains the device descriptor.

### `U1ExitLatency`

The time to transition from the U1 state.

### `U2ExitLatency`

The time to transition from the U2 state.

### `ExitLatencyOfSlowestLinkForU1`

The exit latency for the slowest link for U1 transition.

### `DepthOfSlowestLinkForU1`

The depth of the hub based on which the latency
for the slowest link is calculated for a U1 transition.

### `ExitLatencyOfSlowestLinkForU2`

The exit latency for the slowest link for U2 transition.

### `DepthOfSlowestLinkForU2`

The depth of the hub based on which the latency
for the slowest link is calculated for a U2 transition.

### `HostInitiatedU1ExitLatency`

Host-initiated exit latency to transition from the U1 state.

### `HostInitiatedU2ExitLatency`

Host-initiated exit latency to transition from the U2 state.

### `TotalHubDepth`

Total hub depth.

### `TotalTPPropogationDelay`

The total TP propagation delay.

### `HubFlags`

A bitwise-OR of [PARENT_HUB_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_parent_hub_flags) flags.

### `SublinkSpeedAttr`

A pointer to a **USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED** structure that describes the USB 3.1 capability's sublink speed attributes. For structure declaration, see Usbspec.h

### `SublinkSpeedAttrCount`

The count of sublink speed attributes.