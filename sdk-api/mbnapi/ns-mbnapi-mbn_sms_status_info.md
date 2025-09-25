# MBN_SMS_STATUS_INFO structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_STATUS_INFO** structure contains the status of the SMS message store of a device.

## Members

### `flag`

A bitwise OR combination of [MBN_SMS_STATUS_FLAG](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_status_flag) values that specify the state of the message store.

### `messageIndex`

Contains the index of the last received message in the store. This field is only meaningful when **flag** contains **MBN_SMS_FLAG_NEW_MESSAGE**.