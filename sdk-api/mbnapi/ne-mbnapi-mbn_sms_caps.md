# MBN_SMS_CAPS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_CAPS** enumerated type contains bitfield values that specify SMS capabilities.

These enumerated values are used by the **smsCaps** member of the [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps) structure.

## Constants

### `MBN_SMS_CAPS_NONE:0`

The device does not support SMS.

### `MBN_SMS_CAPS_PDU_RECEIVE:0x1`

For GSM devices, this indicates that the device is capable of receiving PDU-type SMS.
For CDMA devices, this indicates that the device is capable of reading the SMS in binary format as defined in section 3.4.2.1 “SMS Point-to-Point Message” in 3GPP2 specification C.S0015-A “Short Message Service (SMS) for Wideband Spread Spectrum Systems”.

### `MBN_SMS_CAPS_PDU_SEND:0x2`

For GSM devices, this indicates that the device is capable of sending PDU-type SMS.
For CDMA devices, this indicates that the device is capable of sending the SMS in binary format as defined in section 3.4.2.1 “SMS Point-to-Point Message” in 3GPP2 specification C.S0015-A “Short Message Service (SMS) for Wideband Spread Spectrum Systems”.

### `MBN_SMS_CAPS_TEXT_RECEIVE:0x4`

The device supports receiving text-type SMS messages. This is applicable only to CDMA devices.

### `MBN_SMS_CAPS_TEXT_SEND:0x8`

The device supports sending text-type SMS messages. This is applicable only to CDMA devices.