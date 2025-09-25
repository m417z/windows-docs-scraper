# MBN_SMS_FORMAT enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_FORMAT** enumerated type specifies the format of SMS messages.

## Constants

### `MBN_SMS_FORMAT_NONE:0`

No SMS format.

### `MBN_SMS_FORMAT_PDU:0x1`

For GSM devices, SMS, messages will be read in PDU format.

For CDMA devices, SMS messages will be read in binary CDMA format.

### `MBN_SMS_FORMAT_TEXT:0x2`

For CDMA devices, SMS messages will be read in text format.