## Description

The **WIFI_DEVICE_CAPABILITIES** structure describes a WiFiCx device's capabilities.

## Members

### `Size`

The sum (in bytes) of the sizes of all contained elements.

### `HardwareRadioState`

Specifies whether the radio is enabled by hardware. Valid values are 0 (disabled) and 1 (enabled).

### `SoftwareRadioState`

Specifies whether they radio is enabled by software. Valid values are 0 (disabled) and 1 (enabled).

### `FirmwareVersion[MAX_FIRMWARE_VERSION_LENGTH]`

The firmware version.

### `ActionFramesSupported`

Specifies whether sending and receiving action frames is supported. Valid values are 0 (not supported) and 1 (supported).

### `NumRxStreams`

The supported number of RX spatial streams.

### `NumTxStreams`

The supported number of TX spatial streams.

### `Support_eCSA`

Specifies whether eCSA is supported. Valid values are 0 (not supported) and 1 (supported).

### `MACAddressRandomization`

Specifies whether the adapter supports MAC address randomization. Valid values are 0 (not supported) and 1 (supported).

### `MACAddressRandomizationMask`

A bit mask that specifies for each address bit whether it can be randomized (0) or should keep the same value as the permanent address (1). The default is all zeros.

### `BluetoothCoexistenceSupport`

A [**WDI_BLUETOOTH_COEXISTENCE_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_bluetooth_coexistence_support) enum that defines the supported level of Wi-Fi - Bluetooth coexistence.

### `SupportsNonWdiOidRequests`

Specifies non-WDI OID support. Valid values are:
- 0 : Not supported. OIDs that the Microsoft component does not understand are not forwarded to the adapter.
- 1 : Supported. OIDs that the Microsoft component does not understand are forwarded to the adapter.

### `FastTransitionSupported`

Specifies whether the Fast Transition is supported. Valid values are 0 (not supported) and 1 (supported).

### `MU_MIMOSupported`

Specifies whether Mu-MIMO is supported. Valid values are 0 (not supported) and 1 (supported).

### `BSSTransitionSupported`

Specifies if 802.11v BSS transition is supported. Valid values are 0 (not supported) and 1 (supported).

### `SAEAuthenticationSupported`

Specifies if the device supports SAE authentication. Valid values are 0 (not supported) and 1 (supported).

### `MBOSupported`

Specifies if the device supports Multiband Operation (MBO). Valid values are 0 (not supported) and 1 (supported).

### `BeaconReportsImplemented`

Specifies if the adapter implements beacon report measurements. Valid values are 0 (the adapter does not implement beacon report measurements) and 1 (the adapter implements its own 11k beacon report).

### `NumRadios`

The number of radios. **NumRadios** is equal to the number of connections on different channels that the device can simultaneously Rx and Tx.

## Remarks

Call [**WIFI_DEVICE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_capabilities_init) to initialize this structure and fill in its **Size** field. Then call [**WifiDeviceSetDeviceCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetdevicecapabilities) to report device capabilities to WiFiCx.

## See also

[**WIFI_DEVICE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_capabilities_init)

[**WifiDeviceSetDeviceCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetdevicecapabilities)