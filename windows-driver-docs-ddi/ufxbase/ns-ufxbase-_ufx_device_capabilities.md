# _UFX_DEVICE_CAPABILITIES structure

## Description

The **UFX_DEVICE_CAPABILITIES** structure is used USB to define properties of the Universal Serial Bus (USB) device created by the controller.

## Members

### `Size`

Size of the **UFX_DEVICE_CAPABILITIES** structure.

### `MaxSpeed`

Indicates the maximum USB speed supported by the device.

### `RemoteWakeSignalDelay`

The minimum time interval in milliseconds to wait after being suspended before requesting remote wakeup.

### `PdcpSupported`

If **true**, indicates the client driver supports proprietary charger detection.

### `InEndpointBitmap`

A bitmap that defines which endpoint numbers can support an IN endpoint. Bit 0 indicates endpoint address 0, bit 1 indicates endpoint address 1, etc. Bit 0 (the default control endpoint) is required to be set to 1.

### `OutEndpointBitmap`

A bitmap that defines which endpoint numbers can support an OUT endpoint. Bit 0 indicates endpoint address 0, bit 1 indicates endpoint address 1, etc. Bit 0 (the default control endpoint) is required to be set to 1.

### `SharesConnectors`

A boolean value that indicates the connector supports multiple connectors.

### `GroupId`

 The group identifier the shared connector group to which a controller will be added.