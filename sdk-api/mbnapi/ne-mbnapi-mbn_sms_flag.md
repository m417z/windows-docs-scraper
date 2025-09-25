# MBN_SMS_FLAG enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_FLAG** enumerated type specifies the SMS message class.

These enumerated values are used in the [MBN_SMS_FILTER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_filter) structure.

## Constants

### `MBN_SMS_FLAG_ALL:0`

Refers to all the messages in the device message store.

### `MBN_SMS_FLAG_INDEX`

Refers to a single message in the device message store.

### `MBN_SMS_FLAG_NEW`

Refers to all new received and unread messages.

### `MBN_SMS_FLAG_OLD`

Refers to all old and read messages.

### `MBN_SMS_FLAG_SENT`

Refers to all sent and saved messages.

### `MBN_SMS_FLAG_DRAFT`

Refers to all unsent and saved messages.