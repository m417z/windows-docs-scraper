# MBN_SMS_STATUS_FLAG enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_STATUS_FLAG** enumerated type indicates the status of a device's SMS message store.

These enumerated values are used in a bitfield by the [MBN_SMS_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_status_info) structure.

## Constants

### `MBN_SMS_FLAG_NONE:0`

There is no SMS status information to report.

### `MBN_SMS_FLAG_MESSAGE_STORE_FULL:0x1`

The message store is full.

### `MBN_SMS_FLAG_NEW_MESSAGE:0x2`

A new non-class 0 message has been received by the interface.