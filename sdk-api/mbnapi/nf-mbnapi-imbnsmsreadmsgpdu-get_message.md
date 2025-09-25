# IMbnSmsReadMsgPdu::get_Message

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The message in WMT format as used by CDMA devices.

This property is read-only.

## Parameters

## Remarks

For CDMA devices, this returns a byte array representing a message as defined in section 3.4.2.1 “SMS Point-to-Point Message” in the 3GPP2 specification C.S0015-A “Short Message Service (SMS) for Wideband Spread Spectrum Systems”. SMS will only support the Wireless Messaging Teleservice (WMT) format.

## See also

[IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu)