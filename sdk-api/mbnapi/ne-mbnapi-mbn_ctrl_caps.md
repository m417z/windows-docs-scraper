# MBN_CTRL_CAPS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_CTRL_CAPS** enumerated type represents all of the Mobile Broadband device control capabilities as bit fields.

## Constants

### `MBN_CTRL_CAPS_NONE:0`

Device control capabilities are unavailable.

### `MBN_CTRL_CAPS_REG_MANUAL:0x1`

Manual selection is allowed for the interface. This field will not be set for CDMA type interfaces.

### `MBN_CTRL_CAPS_HW_RADIO_SWITCH:0x2`

Hardware radio switch functionality is supported.

### `MBN_CTRL_CAPS_CDMA_MOBILE_IP:0x4`

The Mobile Broadband device is configured for Mobile IP support. This field is applicable only to CDMA devices.

### `MBN_CTRL_CAPS_CDMA_SIMPLE_IP:0x8`

The Mobile Broadband device is configured for Simple IP support. This field is applicable only to CDMA devices.

If this field is set in conjunction with **MBN_CTRL_CAPS_MOBILE_IP**, then this indicates that the device is configured for Mobile IP with Simple IP as a fallback option.

### `MBN_CTRL_CAPS_PROTECT_UNIQUEID:0x10`

In some countries or regions, showing the International Mobile Subscriber Identity (IMSI) to the user is not allowed. When this flag is set, the application should not display the IMSI to users.

### `MBN_CTRL_CAPS_MODEL_MULTI_CARRIER:0x20`

Windows 8 or later: The Mobile Broadband device supports multi-carrier functionality and is not restricted by a Network Service Provider (NSP).

### `MBN_CTRL_CAPS_USSD:0x40`

Windows 8 or later: The Mobile Broadband device supports the USSD protocol. This flag applies only to GSM-based devices.

### `MBN_CTRL_CAPS_MULTI_MODE:0x80`

Windows 8 or later: The Mobile Broadband device supports multiple cellular classes.