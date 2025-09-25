# MBB_DEVICE_WAKE_CAPABILITIES structure

## Description

The **MBB_DEVICE_WAKE_CAPABILITIES** structure describes a MBBCx net adapter's wake-on-LAN (WoL) capabilities.

## Members

### `Size`

The size of this structure, in bytes.

### `RegisterState`

A boolean value indicating if the net adapter can generate wake-up events if its registration state with the mobile broadband service has changed.

### `SmsReceive`

A boolean value indicating if the net adapter can generate wake-up events if it receives a Short Message Service (SMS) message that it must report to the mobile broadband service.

### `UssdReceive`

A boolean value indicating if the net adapter can generate wake-up events if it receives an Unstructured Supplementary Service Data (USSD) message.

### `PacketState`

A boolean value indicating if the net adapter can generate wake-up events if a packet state changes.

### `UiccChange`

A boolean value indicating if the net adapter can generate wake-up events if the SIM card state changes.

## Remarks

Call [**MBB_DEVICE_WAKE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbb_device_wake_capabilities_init) to initialize this structure. An initialized **MBB_DEVICE_WAKE_CAPABILITIES** structure is passed as an input method to [**MbbDeviceSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdevicesetwakecapabilities).

## See also